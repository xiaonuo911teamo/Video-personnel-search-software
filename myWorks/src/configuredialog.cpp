#include "configuredialog.h"
#include "ui_configuredialog.h"
#include <QFileDialog>

/*************************************************
 Function:      configureDialog
 Description:   构造函数。用于构建配置对话框
 Calls:         Ui_configureDialog::setupUi()
                QLineEdit::setText()
 CalledBy:
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         @parent: 父对象指针
                @p:通过该指针返回修改的配置
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
configureDialog::configureDialog(QWidget *parent,Settings* p) :
    QDialog(parent),ui(new Ui::configureDialog),pset(p)
{
    ui->setupUi(this);
    ui->faceCascadeAddrLineEdit->setText(QString::fromStdString(pset->s_faceCascade));
    ui->modelPCAAddrLineEdit->setText(QString::fromStdString(pset->s_modelPCA));
    ui->strangersAddrLineEdit->setText(QString::fromStdString(pset->s_strangers));
}

/*析构函数*/
configureDialog::~configureDialog()
{
    delete ui;
}

/*设置人脸识别器xml地址*/
void configureDialog::setFaceCascade(QString faceCascade)
{
    pset->s_faceCascade = faceCascade.toLocal8Bit().data();
}

/*设置已登记人员人脸信息xml的地址*/
void configureDialog::setModelPCA(QString modelPCA)
{
    pset->s_modelPCA = modelPCA.toLocal8Bit().data();
}

/*设置陌生人图片储存位置*/
void configureDialog::setStrangers(QString strangers)
{
    pset->s_strangers = strangers.toLocal8Bit().data();
}

/*返回人脸识别器xml地址*/
string configureDialog::getFaceCascade()
{
    return pset->s_faceCascade;
}

/*返回已登记人员人脸信息xml的地址*/
string configureDialog::getModelPCA()
{
    return pset->s_modelPCA;
}

/*返回陌生人图片储存位置*/
string configureDialog::getStrangers()
{
    return pset->s_strangers;
}

/*调用修改人脸识别器xml地址的对话框*/
void configureDialog::on_faceCascadeAddrButton_clicked()
{
    QString fileName =QFileDialog::getOpenFileName(this,tr("Select Face Cascade XML File"),
                                     ".",tr("XML Files(*.xml *.XML)"));
    setFaceCascade(fileName);
    ui->faceCascadeAddrLineEdit->setText(fileName);
}

/*调用修改已登记人员人脸信息xml的地址的对话框*/
void configureDialog::on_modelPCAAddrButton_clicked()
{
    QString fileName =QFileDialog::getOpenFileName(this,tr("Select My Model PCA XML File"),
                                     ".",tr("XML Files(*.xml *.XML)"));
    setModelPCA(fileName);
    ui->modelPCAAddrLineEdit->setText(fileName);
}

/*调用修改陌生人图片储存位置的对话框*/
void configureDialog::on_strangersAddrButton_clicked()
{
    QUrl fileName =QFileDialog::getExistingDirectoryUrl(this,tr("Select Strangers's Address"));
    setStrangers(fileName.toLocalFile());
    ui->strangersAddrLineEdit->setText(fileName.toLocalFile());
}
