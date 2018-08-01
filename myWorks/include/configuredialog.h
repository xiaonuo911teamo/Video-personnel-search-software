/*************************************************

 Filename:      configuredialog.h

 Author: 小诺     Version: 1.0       Date: 2018/5/20

 Description:   该文件可创建一个可更改配置的对话框。可更改的内容有：
                1.在陌生人模式下，识别出的陌生人图片的存放位置；
                2.选用的人脸识别器（xml）
                3.已登记人员人脸信息库（xml）

 Others:  在构建时需提供Settings*类型的指针，修改完成的信息将直接修改该指针中的内容

 FunctionList:  // 主要函数列表，每条记录应包括函数名及功能简要说明
   1. configureDialog();            //构造函数
   2. ~configureDialog();           //析构函数
   3. setFaceCascade();             //设置人脸识别器xml地址
   4. setModelPCA();                //设置已登记人员人脸信息xml的地址
   5. setStrangers();               //设置陌生人图片储存位置
   6. getFaceCascade();             //返回人脸识别器xml地址
   7. getModelPCA();                //返回已登记人员人脸信息xml的地址
   8. getStrangers();               //返回陌生人图片储存位置
   9. on_faceCascadeAddrButton_clicked();        //选择人脸识别器xml地址按钮触发事件
   10.on_modelPCAAddrButton_clicked();           //选择已登记人员人脸信息xml的地址按钮触发事件
   11.on_strangersAddrButton_clicked();          //选择陌生人图片储存位置按钮触发事件


 History:        // 修改历史记录列表，每条修改记录应包括修改日期、修改

                 // 者及修改内容简述

   1. Date:

      Author:

      Modification:

   2. ...
********************************************************************************/
#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class configureDialog;
}

class configureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit configureDialog(QWidget *parent = 0,Settings* p=0); //构造函数
    ~configureDialog();                             //析构函数
    void setFaceCascade(QString faceCascade);       //设置人脸识别器xml地址
    void setModelPCA(QString modelPCA);             //设置已登记人员人脸信息xml的地址
    void setStrangers(QString strangers);           //设置陌生人图片储存位置

    string getFaceCascade();                        //返回人脸识别器xml地址
    string getModelPCA();                           //返回已登记人员人脸信息xml的地址
    string getStrangers();                          //返回陌生人图片储存位置

private slots:
    void on_faceCascadeAddrButton_clicked();        //选择人脸识别器xml地址按钮触发事件

    void on_modelPCAAddrButton_clicked();           //选择已登记人员人脸信息xml的地址按钮触发事件

    void on_strangersAddrButton_clicked();          //选择陌生人图片储存位置按钮触发事件

public:
    Ui::configureDialog *ui;
private:
    Settings* pset;
};

#endif // CONFIGUREDIALOG_H
