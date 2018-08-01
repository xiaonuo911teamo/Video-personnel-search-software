/*************************************************

 Filename:      registeredpeopledialog.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该类区别于registereddialog类，在该类中可对成员信息进行修改，默认为
                不可修改状态，当点击编辑按钮之后，则选中的item可以被修改

 Others:

  FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明

   1. 构造和析构函数
    RegisteredPeopleDialog();
    ~RegisteredPeopleDialog();

   2. 一个槽函数
private slots:
    void on_editButton_clicked();

 History:

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/

#ifndef REGISTEREDPEOPLEDIALOG_H
#define REGISTEREDPEOPLEDIALOG_H

#include <QDialog>
#include <vector>
#include "peoplelistitem.h"
#include "settings.h"

using namespace std;

namespace Ui {
class RegisteredPeopleDialog;
}

class RegisteredPeopleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisteredPeopleDialog(QWidget *parent,vector<PeopleSettings*>& p);
    ~RegisteredPeopleDialog();

private slots:
    void on_editButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::RegisteredPeopleDialog *ui;
    vector<PeopleSettings*> people;
    vector<peopleListItem*> peopleWidgetList;
};

#endif // REGISTEREDPEOPLEDIALOG_H
