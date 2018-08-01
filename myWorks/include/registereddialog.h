/*************************************************

 Filename:      registereddialog.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该类区别于registeredpeopledialog类，在该类中不可对成员信息进行修改，只能选定，
                当确认选定时，会发射specifiedLabel(int)信号，返回人员内部标签

 Others:

  FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明

   1. 构造和析构函数
    registeredDialog();
    ~registeredDialog();

   2. 信号
signals:
    void specifiedLabel(int label);     //广播选定的标签号

   3. 两个按钮的槽函数
private slots:
    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

 History:

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/

#ifndef REGISTEREDDIALOG_H
#define REGISTEREDDIALOG_H

#include <QDialog>
#include "people.h"
#include <vector>
using namespace std;

namespace Ui {
class registeredDialog;
}

class registeredDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registeredDialog(QWidget *parent,vector<PeopleSettings*>& peopleList);
    ~registeredDialog();
signals:
    void specifiedLabel(int label);     //广播选定的标签号

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::registeredDialog *ui;

};

#endif // REGISTEREDDIALOG_H
