#include "findpeoplewindow.h"
#include "ui_findpeoplewindow.h"
#include "ui_configuredialog.h"
#include "mat2qimage.h"
#include "tipdialog.h"
#include <QTimer>
#include <QFileDialog>
#include <QDialog>

findPeopleWindow::findPeopleWindow(QWidget *parent) :QMainWindow(parent),
    ui(new Ui::findPeopleWindow)
{
    ui->setupUi(this);
    ui->videoLabel->setScaledContents(true); //video自动调整大小

    //modelPCA = createEigenFaceRecognizer();
    modelPCA =  createLBPHFaceRecognizer();
    strangerNum = 0;    //陌生人数量
    strangerRate = 1;   //检测到6张陌生人，记录一张
    threshold = 50;     //判断是否为陌生人的阈值

    slider = new QSlider(Qt::Horizontal, this); //添加水平视频滑块
    connect(slider,SIGNAL(sliderMoved(int)),this,SLOT(seek(int)));
    video.setVideo(sets.s_video);   //设置要播放的视频地址

    controls = new PlayerControls(this);    //添加视频控制工具箱
    connect(controls,SIGNAL(play()),this,SLOT(play()));
    connect(controls,SIGNAL(pause()),this,SLOT(pause()));
    connect(controls,SIGNAL(stop()),this,SLOT(stop()));

    //添加状态栏
    (void)statusBar();
    tipLabel = new QLabel;
    statusBar()->addWidget(tipLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

    //加载已有配置
    if(!sets.load("myApp.xml"))
    {
        tipDialog* tip = new tipDialog(0,tr("加载myApp.xml失败，是否创建新的myApp.xml?"));

        connect(tip,SIGNAL(accepted()),this,SLOT(createMyXML()));
    }

    connect(ui->actionOpen_File,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->actionConfigure,SIGNAL(triggered()),this,SLOT(createConfigure()));
    connect(ui->actionStrangers,SIGNAL(triggered()),this,SLOT(createStrangers()));
    connect(ui->actionRegisteredPeoples,SIGNAL(triggered()),this,SLOT(createRegistered()));

    //主界面布局
    QBoxLayout *displayLayout = new QVBoxLayout;
    displayLayout->addWidget(ui->videoLabel,10);

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addSpacing(100);
    controlsLayout->addWidget(controls,1);
    //controlsLayout->addSpacerItem(new QSpacerItem(15, 15, QSizePolicy::Expanding));
    controlsLayout->addSpacing(300);

    displayLayout->addWidget(slider,1);
    displayLayout->addLayout(controlsLayout,1);

    QBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->addSpacing(150);
    buttonLayout->addWidget(ui->originalButton);
    buttonLayout->addWidget(ui->recognizeButton);
    buttonLayout->addWidget(ui->specifiedButton);
    buttonLayout->addWidget(ui->strangerButton);
    buttonLayout->addSpacing(80);

    QBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(displayLayout,5);
    layout->addLayout(buttonLayout,1);

    ui->centralWidget->setLayout(layout);
    connect(this,SIGNAL(destroyed()),this,SLOT(close()));
}

findPeopleWindow::~findPeopleWindow()
{
    delete ui;
}

/*设置视频地址*/
void findPeopleWindow::setVideo(QString videoAddr)
{
    sets.setVideo(videoAddr.toLocal8Bit().data());
    video.setVideo(sets.s_video);   //设置要播放的视频地址
}

void findPeopleWindow::seek(int pos)
{

    double d=video.get(CV_CAP_PROP_POS_FRAMES);
    if(pos-d>30 || d-pos>30)
        video.set(CV_CAP_PROP_POS_FRAMES,pos);

}

/*设置人脸分类器xml的地址*/
void findPeopleWindow::setCascadeClassifier(QString faceCascadeAddr)
{
    sets.setFaceCascade(faceCascadeAddr.toLocal8Bit().data());
}

/*设置已有人员的人脸xml地址*/
void findPeopleWindow::setFaceRecognizer(QString modelPCAAddr)
{
    sets.setModelPCA(modelPCAAddr.toLocal8Bit().data());
}

/*创建新的myAppXML文件*/
void findPeopleWindow::createMyXML()
{
    QFile* fp = new QFile(tr("myApp.xml"));
    sets.save("myApp.xml");
    sets.load("myApp.xml");
    fp->close();
    tipLabel->setText(tr("myApp.xml 创建完毕"));
}

/*
    创建配置对话框
    可修改人脸分类器xml，已有人脸xml以及陌生人的储存位置
*/
void findPeopleWindow::createConfigure()
{
    configure=new configureDialog(0,&sets);
    configure->setModal(true); //设置为模态对话框
    configure->show();

    connect(configure->ui->buttonBox,SIGNAL(accepted()),this,SLOT(changeConfigure()));
}

void findPeopleWindow::changeConfigure()
{
    sets.s_faceCascade = configure->getFaceCascade();
    sets.s_modelPCA = configure->getModelPCA();
    sets.s_strangers = configure->getStrangers();
}

void findPeopleWindow::createRegistered()
{
    registeredPeopleDialog = new RegisteredPeopleDialog(0,sets.peopleSets);
    registeredPeopleDialog->setModal(true); //设置为模态对话框
    registeredPeopleDialog->show();

}

void findPeopleWindow::addPeople()
{
    sets.addPeople(strangers->addPeople->people);
    tipLabel->setText(tr("成功添加%1").arg(QString::fromStdString(strangers->addPeople->people->s_num)));
}

void findPeopleWindow::play()
{
    if(playState == STOP)
    {
        playState = PLAYING;
        controls->setState(playState);
        switch (playMode) {
        case ORIGINAL:
            originalPlay();
            break;
        case STRANGER:
            findStrangers();
            break;
        case SPECIFIED:
            specifiedR();
            break;
        case RECOGNIZE:
            recognize();
            break;
        default:
            break;
        }
    }
    else if(playState == PAUSE)
    {
        playState = PLAYING;
        controls->setState(playState);
    }
}

void findPeopleWindow::pause()
{
    playState = PAUSE;
    controls->setState(playState);
}

void findPeopleWindow::stop()
{
    playState = STOP;
    controls->setState(playState);
    //播放退回初始帧
    video.set(CV_CAP_PROP_POS_FRAMES,0);
    slider->setValue(0);
    frame=video.getNextFrame(1);
    image = Mat2QImage(frame);
    ui->videoLabel->setPixmap(QPixmap::fromImage(image));
}

/*
    陌生人列表对话框
*/
void findPeopleWindow::createStrangers()
{
    try
    {
        modelPCA->load(sets.s_modelPCA);

    }
    catch (cv::Exception& )
    {
        tipLabel->setText(tr("facePCAModel文件打开 %1失败.").arg(sets.s_modelPCA.c_str()));
        return ;
    }

    strangers = new strangersDialog(modelPCA,this,QString::fromStdString(sets.s_strangers),strangerNum);
    strangers->setModal(true);
    strangers->show();
    connect(strangers,SIGNAL(addPeopleSignals()),this,SLOT(addPeople()));
}


void findPeopleWindow::nextFrame()
{
    Mat grayFrame;
    vector<Rect> faces;

    frame=video.getNextFrame(7);
    slider->setValue((int)video.get(CV_CAP_PROP_POS_FRAMES));

    if (!frame.empty() && playState == PLAYING)
    {
        if(RECOGNIZE == playMode || STRANGER == playMode || SPECIFIED == playMode)
        {
            frame.copyTo(grayFrame);
            cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
            //equalizeHist(grayFrame, grayFrame);

            faceCascade.detectMultiScale(grayFrame, faces, 1.1, 10, 0, Size(30, 30), Size(300, 300));
            for (size_t i = 0; i < faces.size(); i++)
            {
                if(STRANGER == playMode || SPECIFIED == playMode)
                {
                    Mat faceROI(grayFrame, faces[i]);

                    if (!modelPCA->empty())
                    {
                        int label = -1;
                        double confidence = 0;

                        cv::resize(faceROI, faceROI, Size(92, 112));

                        modelPCA->predict(faceROI, label, confidence);

                        if (confidence > threshold && STRANGER == playMode)
                        {
                            rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
                            if(strangerRate++%6 == 0)
                            {
                                equalizeHist(faceROI, faceROI);
                                string filename = sets.s_strangers + format("stranger%d.jpg", strangerNum);
                                imwrite(filename, faceROI);
                                strangerNum++;
                                tipLabel->setText(tr("陌生人 %1").arg(strangerNum));
                            }
                        }
                        else if(SPECIFIED == playMode && confidence < threshold && label==specifiedNum)
                        {
                            rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
                        }
                    }
                }
                else
                    rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
            }
        }

        image = Mat2QImage(frame);
        ui->videoLabel->setPixmap(QPixmap::fromImage(image));
    }
    else
    {
        timer->stop();
        delete timer;
    }
}

void findPeopleWindow::recognize()
{
    Mat grayFrame;

    //加载人脸识别器
    if (!faceCascade.load(sets.s_faceCascade))
    {
        tipLabel->setText(tr("人脸识别器加载失败."));
        return ;
    }

    if(video.isOpened())
    {
        vector<Rect> faces;

        tipLabel->setText(tr("开始播放."));

        slider->setRange(0,(int)video.get(CV_CAP_PROP_FRAME_COUNT));
        frame = video.getNextFrame(1);
        if (!frame.empty())
        {
            frame.copyTo(grayFrame);
            cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
            //equalizeHist(grayFrame, grayFrame);

            faceCascade.detectMultiScale(grayFrame, faces, 1.1, 10, 0, Size(30, 30), Size(300, 300));
            for (size_t i = 0; i < faces.size(); i++)
            {
                rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
            }

            image = Mat2QImage(frame);
            ui->videoLabel->setPixmap(QPixmap::fromImage(image));
            timer = new QTimer(this);
            timer->setInterval(1000/video.rate);   //设置定时间隔
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start();
        }
    }
}

void findPeopleWindow::originalPlay()
{
    //video.open(sets.s_video);

    if(video.isOpened())
    {
        tipLabel->setText(tr("开始播放."));
        //rate = video.get(CV_CAP_PROP_FPS);
        slider->setRange(0,(int)video.get(CV_CAP_PROP_FRAME_COUNT));
        frame=video.getNextFrame(1);

        if (!frame.empty())
        {
            //逆时针旋转90度
            //transpose(frame, frame);
            //flip(frame, frame, 0);

            image = Mat2QImage(frame);
            ui->videoLabel->setPixmap(QPixmap::fromImage(image));
            timer = new QTimer(this);
            timer->setInterval(1000/video.rate);   //set timer match with FPS *5: delay
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start();
        }
    }
}

void findPeopleWindow::findStrangers()
{
    Mat grayFrame;
    //video.open(sets.s_video);

    try
    {
        modelPCA->load(sets.s_modelPCA);

    }
    catch (cv::Exception& )
    {
        tipLabel->setText(tr("facePCAModel文件打开 %1失败.").arg(sets.s_modelPCA.c_str()));
        return ;
    }

    //加载人脸识别器
    if (!faceCascade.load(sets.s_faceCascade))
    {
        tipLabel->setText(tr("人脸识别器加载失败."));
        return ;
    }

    if(video.isOpened())
    {
        vector<Rect> faces;
        strangerNum = 0;
        tipLabel->setText(tr("开始检测陌生人."));

        //rate = video.get(CV_CAP_PROP_FPS);
        slider->setRange(0,(int)video.get(CV_CAP_PROP_FRAME_COUNT));
        frame=video.getNextFrame(1);

        if (!frame.empty())
        {
            //逆时针旋转90度
            //transpose(frame, frame);
            //flip(frame, frame, 0);

            frame.copyTo(grayFrame);
            cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
            //equalizeHist(grayFrame, grayFrame);

            faceCascade.detectMultiScale(grayFrame, faces, 1.1, 10, 0, Size(30, 30), Size(300, 300));
            for (size_t i = 0; i < faces.size(); i++)
            {
                Mat faceROI(grayFrame, faces[i]);

                if (!modelPCA->empty())
                {
                    int label = 0;
                    double confidence = 0;

                    cv::resize(faceROI, faceROI, Size(92, 112));

                    modelPCA->predict(faceROI, label, confidence);
                    //tipLabel->setText(tr("%1").arg(confidence));

                    if (confidence > threshold)
                    {
                        rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
                        equalizeHist(faceROI, faceROI);
                        string filename = sets.s_strangers + format("stranger%d.jpg", strangerNum);
                        imwrite(filename, faceROI);
                        strangerNum++;
                        tipLabel->setText(tr("陌生人 %1").arg(strangerNum));
                    }
                }
            }

            image = Mat2QImage(frame);
            ui->videoLabel->setPixmap(QPixmap::fromImage(image));
            timer = new QTimer(this);
            timer->setInterval(1000/video.rate*5);   //set timer match with FPS *5: delay
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start();
        }
    }
}

void findPeopleWindow::specifiedR()
{
    Mat grayFrame;
    int label = -1;
    double confidence = 0;

    try
    {
        modelPCA->load(sets.s_modelPCA);

    }
    catch (cv::Exception& )
    {
        tipLabel->setText(tr("facePCAModel文件打开失败."));
        return ;
    }

    //加载人脸识别器
    if (!faceCascade.load(sets.s_faceCascade))
    {
        tipLabel->setText(tr("人脸识别器加载失败."));
        return ;
    }

    if(video.isOpened())
    {
        vector<Rect> faces;
        strangerNum = 0;
        tipLabel->setText(tr("开始检测."));

        slider->setRange(0,(int)video.get(CV_CAP_PROP_FRAME_COUNT));

        for(frame=video.getNextFrame(1); !frame.empty(); frame=video.getNextFrame(15))
        {
            frame.copyTo(grayFrame);
            cvtColor(frame, grayFrame, COLOR_BGR2GRAY);

            faceCascade.detectMultiScale(grayFrame,faces,1.1,10,0,Size(30,30),Size(300,300));
            for(size_t i=0;i<faces.size();i++)
            {
                Mat faceROI(grayFrame, faces[i]);

                if(!modelPCA->empty())
                {
                    cv::resize(faceROI, faceROI, Size(92, 112));
                    modelPCA->predict(faceROI,label,confidence);

                    if(confidence<threshold && label == specifiedNum)
                    {
                        rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
                        break;
                    }
                }
            }
            if(confidence<threshold && label == specifiedNum)
            {
                image = Mat2QImage(frame);
                ui->videoLabel->setPixmap(QPixmap::fromImage(image));
                timer = new QTimer(this);
                timer->setInterval(1000/video.rate*5);   //set timer match with FPS *5: delay
                connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
                timer->start();
                break;
            }
        }
    }
}

void findPeopleWindow::openFile()
{
    QString filename =QFileDialog::getOpenFileName(this,tr("Open Video File"),
                                     ".",tr("Video Files(*.avi *.mp4 *.flv *.mkv)"));
    setVideo(filename);
    ui->videoLabel->setText(tr("文件已选定：%1").arg(filename));
}

void findPeopleWindow::on_recognizeButton_clicked()
{
    playMode = RECOGNIZE;
    playState = STOP;
    controls->stop();   //emit
    tipLabel->setText(tr("工作模式已选定为：识别人脸"));
}

void findPeopleWindow::on_originalButton_clicked()
{
    playMode = ORIGINAL;
    playState = STOP;
    controls->stop();   //emit
    tipLabel->setText(tr("工作模式已选定为：原始视频"));
}

void findPeopleWindow::on_strangerButton_clicked()
{
    playMode = STRANGER;
    playState = STOP;
    controls->stop();   //emit
    tipLabel->setText(tr("工作模式已选定为：陌生人"));
}

void findPeopleWindow::on_specifiedButton_clicked()
{
    playMode = SPECIFIED;
    playState = STOP;
    controls->stop();   //emit

    tipLabel->setText(tr("工作模式已选定为：指定识别"));
    registered = new registeredDialog(0,sets.peopleSets);
    registered->setModal(true);
    registered->show();
    connect(registered,SIGNAL(specifiedLabel(int)),this,SLOT(setSpecifiedNum(int)));
}

void findPeopleWindow::setSpecifiedNum(int num)
{
    specifiedNum = num;
}

void findPeopleWindow::close()
{

}

void findPeopleWindow::closeEvent(QCloseEvent *event)
{
    sets.save("myApp.xml");
}
