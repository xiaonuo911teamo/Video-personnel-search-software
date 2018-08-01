/*************************************************

 Filename:      addpeopledialog.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该文件可创建一个添加人员的对话框，可添加的人员信息有：姓名，编号，年龄，备注以及头像，确认输入无误后，
                点击训练按钮，可将该人员的人脸库添加到已有的信息库中，则为已登记人员。
                返回值：一个peopleSettings的指针，指向该人员的堆空间。如未完成登记，返回的是空指针，并删除申请的堆空间

 Others:         // 其它内容的说明

  FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明

   1. addPeopleDialog(QWidget *parent = 0);  //构造函数
   2. ~addPeopleDialog();               //析构函数
   3. setPicture(QString pictureAddr);  //设置头像
   4. setName(QString name);            //设置姓名
   5. setAge(int age);                  //设置年龄
   6. setNum(QString num);              //设置编号
   7. setNote(QString note);            //设置备注
   8. getPicture();                     //返回头像的地址
   9. getName();                        //返回姓名
   10. getNote();                       //返回备注
   11. startTrans();                    //开始训练信号
   12. addPeople();                     //新增人员信号
   13. on_pictureButton_clicked();      //头像被点击槽函数，可更换头像
   14. on_nameLineEdit_textChanged(const QString &arg1);  //姓名被修改
   15. on_numLineEdit_textChanged(const QString &arg1);   //编号被修改
   16. on_ageLineEdit_textChanged(const QString &arg1);   //年龄被修改
   17. on_noteTextEdit_textChanged();   //备注被修改
   18. on_transButton_clicked();        //训练按钮被点击,发射开始训练信号（startTrans）
   19. on_buttonBox_accepted();         //确认按钮被按下，发射新增人员信号（addPeople）
   20. on_buttonBox_rejected();         //取消按钮被按下,删除已申请的堆空间

 History:

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/

#ifndef ADDPEOPLEDIALOG_H
#define ADDPEOPLEDIALOG_H

#include <QDialog>
#include "people.h"

namespace Ui {
class addPeopleDialog;
}

class addPeopleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPeopleDialog(QWidget *parent = 0);  //构造函数
    ~addPeopleDialog();     //析构函数

    void setPicture(QString pictureAddr);   //设置头像
    void setName(QString name);             //设置姓名
    void setAge(int age);                   //设置年龄
    void setNum(QString num);               //设置编号
    void setNote(QString note);             //设置备注
    QString getPicture();                   //返回头像的地址
    QString getName();                      //返回姓名
    QString getNote();                      //返回备注

signals:
    void startTrans();          //开始训练信号
    void addPeople();           //新增人员信号

private slots:
    void on_pictureButton_clicked();    //头像被点击槽函数，可更换头像

    void on_nameLineEdit_textChanged(const QString &arg1);  //姓名被修改

    void on_numLineEdit_textChanged(const QString &arg1);   //编号被修改

    void on_ageLineEdit_textChanged(const QString &arg1);   //年龄被修改

    void on_noteTextEdit_textChanged(); //备注被修改

    void on_transButton_clicked();  //训练按钮被点击

    void on_buttonBox_accepted();   //确认按钮被按下

    void on_buttonBox_rejected();   //取消按钮被按下

public:
    PeopleSettings* people;
private:
    Ui::addPeopleDialog *ui;
};

#endif // ADDPEOPLEDIALOG_H
