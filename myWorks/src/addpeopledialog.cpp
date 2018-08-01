#include "addpeopledialog.h"
#include "ui_addpeopledialog.h"
#include <QFileDialog>
#include <QDebug>

/* 构造函数
 * 申请堆空间，用于存放人员信息
 * 构建ui界面
 */
addPeopleDialog::addPeopleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPeopleDialog)
{
    people = new PeopleSettings;
    ui->setupUi(this);

    //ui->buttonBox->button(ui->buttonBox->Apply)->setDisabled(true);
}

/* 析构函数
 * 删除ui界面
 */
addPeopleDialog::~addPeopleDialog()
{
    delete ui;
}

/* 头像按钮被点击函数
 * 调用选择文件对话框，返回图片的地址
 * 并调用setPicture设置到人员信息中
 */
void addPeopleDialog::on_pictureButton_clicked()
{
    QString fileName =QFileDialog::getOpenFileName(this,tr("Select a picture"),
                                     ".",tr("Image Files(*.jpg *.png)"));
    setPicture(fileName);
}

/*************************************************
 Function:      setPicture
 Description:   设置该人员头像的地址
 Calls:         QIcon::QIcon()
                QToolButton::setIcon()
                QToolButton::setIconSize()
                QString::toLocal8Bit().data()
 CalledBy:      on_pictureButton_clicked()
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         由对话框返回的QString字符串
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::setPicture(QString pictureAddr)
{
    QIcon *icon = new QIcon(pictureAddr);
    ui->pictureButton->setIcon(*icon);
    ui->pictureButton->setIconSize(QSize(110,120));
    people->s_picAddr=pictureAddr.toLocal8Bit().data();
}

/*************************************************
 Function:      setAge
 Description:   设置该人员的年龄
 Calls:
 CalledBy:      on_ageLineEdit_textChanged()
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         @age：年龄
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::setAge(int age)
{
    people->i_age=age;
}

/*************************************************
 Function:      setName
 Description:   设置该人员的姓名
 Calls:
 CalledBy:      on_nameLineEdit_textChanged()
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         @name：姓名
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::setName(QString name)
{
    people->s_name=name.toLocal8Bit().data();
}

/*************************************************
 Function:      setNote
 Description:   设置该人员的备注
 Calls:
 CalledBy:      on_noteTextEdit_textChanged()
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         @note：备注
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::setNote(QString note)
{
    people->s_note=note.toLocal8Bit().data();
}

/*************************************************
 Function:      setNum
 Description:   设置该人员的编号
 Calls:
 CalledBy:      on_numLineEdit_textChanged()
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         @num：编号
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::setNum(QString num)
{
    people->s_num = num.toLocal8Bit().data();
}

/*************************************************
 Function:      on_nameLineEdit_textChanged
 Description:   设置该人员的年龄
 Calls:         addPeopleDialog::setName()
 CalledBy:
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:         @arg1:LineEdit返回的值
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::on_nameLineEdit_textChanged(const QString &arg1)
{
    setName(arg1);
}

void addPeopleDialog::on_numLineEdit_textChanged(const QString &arg1)
{
    setNum(arg1);
}

void addPeopleDialog::on_ageLineEdit_textChanged(const QString &arg1)
{
    setAge(arg1.toInt());
}

void addPeopleDialog::on_noteTextEdit_textChanged()
{
    setNote(ui->noteTextEdit->toPlainText());
}

/*************************************************
 Function:      on_transButton_clicked
 Description:   训练按钮的应答函数,将发射开始训练的信号
 Calls:         startTrans()
 CalledBy:
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::on_transButton_clicked()
{
    //检查输入后，发射训练信号
    emit startTrans();
    //ui->buttonBox->button(ui->buttonBox->Apply)->setDisabled(false);
}

/*************************************************
 Function:      on_buttonBox_accepted
 Description:   当触发该对话框的确认时，添加人员才有效，该函数发射添加人员的信号
 Calls:         addPeople()
 CalledBy:
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::on_buttonBox_accepted()
{
    emit addPeople();
}

/*************************************************
 Function:      on_buttonBox_rejected
 Description:   当点击该对话框取消按钮时，删除申请的堆空间
 Calls:
 CalledBy:
 Table Accessed:// 被访问的表（此项仅对于牵扯到数据库操作的程序）
 TableUpdated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input:
 Output:         // 对输出参数的说明
 Return:         // 函数返回值的说明
 Others:         // 其它说明
*************************************************/
void addPeopleDialog::on_buttonBox_rejected()
{
    delete people;
}
