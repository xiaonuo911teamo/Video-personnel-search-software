/*************************************************

 Filename:      peoplelistitem.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该类是listWidget的item类，继承自 QObject 和 QListWidgetItem，具体形式如下：
         ___________________________________________
         |          姓名： ****      备注：          |
         |  头像     编号： ****         **********  |
         |          年龄： ****         **********  |
         ———————————————————————————————————————————

 Others:    生成该类时，内容是不可编辑的，需触发edit()函数，才可以编辑其中的信息

  FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明

   1. setName();                //设置姓名
   2. setNum();                 //设置编号
   3. setAge();                 //设置年龄
   4. setNote();                //设置备注
   5. PeopleSettings();         //构造函数

 History:

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/

#ifndef PEOPLELISTITEM_H
#define PEOPLELISTITEM_H

#include <QWidget>
#include <QTextLine>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QLineEdit>
#include <QWidget>
#include <QLabel>
#include "people.h"

class peopleListItem : public QWidget
{
    Q_OBJECT
public:
    peopleListItem(QWidget *parent,QString s_name,QString s_sum,int i_age,QString s_note,QString s_picAddr);
    peopleListItem(QWidget* parent,PeopleSettings* p);
    ~peopleListItem();
    void edit();

    QLineEdit* name;
    QLineEdit* num;
    QLineEdit* label;
    QLineEdit* age;
    QLabel* pic;
    QTextEdit* note;

};

#endif // PEOPLELISTITEM_H
