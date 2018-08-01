#include "strangersdialog.h"
#include "ui_strangersdialog.h"
#include "tipdialog.h"
#include <QLabel>
#include <QToolButton>

strangersDialog::strangersDialog(Ptr<FaceRecognizer> p_model,QWidget *parent,QString strangers,int strangersNum,int registerSum) :
    QDialog(parent),ui(new Ui::strangersDialog),model(p_model),s_strangers(strangers),i_strangersNum(strangersNum),i_registerSum(registerSum)

{
    ui->setupUi(this);

    col=6;

    //table设置
    ui->tableWidget->setColumnCount(col);
    ui->tableWidget->setRowCount(30);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);    //禁止修改文本
    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//允许选择多个
    ui->tableWidget->horizontalHeader()->setVisible(false);                 //表头隐藏
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);   //水平滚动条
    ui->tableWidget->setTextElideMode(Qt::ElideMiddle);                     //文本过长，则中间省略
    ui->tableWidget->setShowGrid(false);//不显示表格线
    ui->tableWidget->setIconSize(QSize(75,100));

    addTableItem();

}

strangersDialog::~strangersDialog()
{
    delete ui;
}

void strangersDialog::addTableItem()
{
    int i=0;
    QString addr;
    while(//i<i_strangersNum &&
          i<150)
    {
        addr=s_strangers+tr("stranger%1.jpg").arg(i);
        QTableWidgetItem* item = new QTableWidgetItem;
        QIcon icon(addr);

        item->setIcon(icon);

        ui->tableWidget->setItem(i/col,i%col,item);
        i++;
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->show();

}

void strangersDialog::on_addButton_clicked()
{
    selected=ui->tableWidget->selectedItems();
    if(selected.size()<10)
    {
        tipDialog* tips=new tipDialog(0,tr("提示：您选择的图像数目过少%1，进行特征提取效果可能不理想。重选请取消！").arg(selected.size()));
        connect(tips,SIGNAL(accepted()),this,SLOT(openAddPeopleDialog()));

        return ;
    }
    else
        openAddPeopleDialog();
}

void strangersDialog::openAddPeopleDialog()
{
    addPeople = new addPeopleDialog(this);
    addPeople->setModal(true);

    addPeople->show();
    connect(addPeople,SIGNAL(addPeople()),this,SIGNAL(addPeopleSignals()));
    connect(addPeople,SIGNAL(startTrans()),this,SLOT(trans()));
}

void strangersDialog::strangersTrans(vector<QString> s, int label)
{
    vector<Mat> images;
    vector<int> labels;

    labels.reserve(s.size());
    images.reserve(s.size());

    for(size_t i=0;i<s.size();i++)
    {
        labels.push_back(label);
        images.push_back(imread(s[i].toLocal8Bit().data(),0));
    }
    if(i_registerSum == 0)
    {
        model->train(images,labels);
        model->save(s_modelLBP.toLocal8Bit().data());
    }
    else
        model->update(images, labels);

    tipDialog* tip = new tipDialog(0,tr("训练已完成。"));
}

void strangersDialog::trans()
{
    vector<QString> s;
    QString addr;
    int num=0;

    for(int i=0;i<selected.size();i++)
    {
        num = col*selected.at(i)->row() + selected.at(i)->column();
        addr=s_strangers+tr("stranger%1.jpg").arg(num);
        s.push_back(addr);
    }
    strangersTrans(s,i_registerSum);
}

void strangersDialog::setModelLBP(QString modelLBP)
{
    s_modelLBP = modelLBP;
}
