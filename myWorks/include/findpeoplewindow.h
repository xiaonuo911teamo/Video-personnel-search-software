#ifndef FINDPEOPLEWINDOW_H
#define FINDPEOPLEWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <iostream>
#include <QSlider>
#include <QCloseEvent>
#include "configuredialog.h"
#include "strangersdialog.h"
#include "registereddialog.h"
#include "playcontrols.h"
#include "settings.h"
#include "registeredpeopledialog.h"
#include "video.h"

using namespace cv;
using namespace face;
using namespace std;

namespace Ui {
class findPeopleWindow;
}

/*
Mode:软件工作模式
State：当前视频的播放状态
*/
enum Mode{ORIGINAL,RECOGNIZE,SPECIFIED,STRANGER};

//主窗口界面
class findPeopleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit findPeopleWindow(QWidget *parent = 0);
    ~findPeopleWindow();
    void recognize();
    void originalPlay();
    void findStrangers();
    void specifiedR();     //由于需要先指定人，所以需要槽函数调用
    void setDuration(int pos);
    int getDuration();


private slots:
    void on_recognizeButton_clicked();
    void nextFrame();                   //下一帧，多种工作模式共用次函数
    void setSpecifiedNum(int num);
    void openFile();
    void close();
    void createMyXML();
    void createConfigure();
    void changeConfigure();
    void createStrangers();
    void createRegistered();
    void addPeople();
    void play();
    void pause();
    void stop();
    void seek(int pos);                 //调动视频进度

    void on_originalButton_clicked();

    void on_strangerButton_clicked();

    void on_specifiedButton_clicked();

private :
    void setVideo(QString videoAddr = "video0.mp4");
    void setCascadeClassifier(QString faceCascadeAddr = "haarcascade_frontalface_alt.xml");
    void setFaceRecognizer(QString modelPCAAddr = "facePCAModel.xml");


protected:
     void closeEvent(QCloseEvent *event);

private:
    Ui::findPeopleWindow *ui;
    QLabel* tipLabel;
    configureDialog *configure;
    strangersDialog *strangers;
    registeredDialog* registered;
    RegisteredPeopleDialog* registeredPeopleDialog;
    PlayerControls *controls;
    QSlider* slider;
    Video video;
    enum Mode playMode;
    enum State playState;

    QTimer *timer;
    QImage image;

    CascadeClassifier faceCascade;
    Ptr<FaceRecognizer> modelPCA;
    Mat frame;
    int strangerNum;
    int strangerRate;       //陌生人保存频率
    int specifiedNum;
    int threshold;

    Settings sets;  //配置
};

#endif // FINDPEOPLEWINDOW_H
