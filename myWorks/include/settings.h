/*************************************************

 Filename:      settings.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该类包含了软件内的所有配置，包括一些地址和已登记的人员信息，并且会将这些配置保存为xml文件。
                另外，也有读取xml的接口，这样可保留上一次的使用记录。

 Others:    该类的所有成员包括成员函数都是共有量，方便调用

  FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明

   1. 构造和析构函数
    Settings();
    ~Settings();
   2. 保存/加载xml文件
    void save(const char* filename);
    bool load(const char* filename);
   3. 添加指定成员
    void addPeople(PeopleSettings* people);
    void addPeople(string name,string num,string note,string picAddr,int age,int label);
   4. 设置各属性的地址
    void setStrangers(string strangers);
    void setVideo(string video);
    void setModelPCA(string modelPCA);
    void setFaceCascade(string faceCascade);

 History:

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/

#ifndef SETTING_H
#define SETTING_H

#include <iostream>
#include <vector>
#include <map>
#include "people.h"

using namespace std;

class Settings
{
public:
    Settings();
    ~Settings();

    void save(const char* filename);
    bool load(const char* filename);
    void addPeople(PeopleSettings* people);
    void addPeople(string name,string num,string note,string picAddr,int age,int label);
    void setStrangers(string strangers);
    void setVideo(string video);
    void setModelPCA(string modelPCA);
    void setFaceCascade(string faceCascade);

    vector<PeopleSettings*> peopleSets;
    std::map<std::string,std::string> m_datas;

    string s_strangers;

    string s_video;
    string s_faceCascade;
    string s_modelPCA;

    int i_sum;

};

#endif // SETTINGS_H
