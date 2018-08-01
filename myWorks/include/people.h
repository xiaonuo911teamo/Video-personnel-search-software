/*************************************************

 Filename:      people.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该类是一个人的类，包含人员信息有：姓名，编号，年龄，备注，头像地址以及内部标签。

 Others:         // 其它内容的说明

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

#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <list>
#include <map>
#include <QObject>

using namespace std;

class PeopleSettings : public QObject
{
    Q_OBJECT
public slots:
    void setName(string name);     //设置姓名
    void setNum(string num);       //设置编号
    void setAge(string age);       //设置年龄
    void setNote(string note);     //设置备注

public:
    PeopleSettings(string& name,string& num,int age,string& note,string& picAddr,int label);//
    PeopleSettings();               //构造函数

    string s_name;
    string s_num;
    string s_note;
    string s_picAddr;
    int i_label;
    int i_age;
};

#endif // PEOPLE_H
