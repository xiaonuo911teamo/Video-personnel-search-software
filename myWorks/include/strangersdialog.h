#ifndef STRANGERSDIALOG_H
#define STRANGERSDIALOG_H

#include <QDialog>
#include "addpeopledialog.h"
#include <iostream>
#include <opencv.hpp>
#include <opencv2/face.hpp>
#include <QTableWidgetItem>

using namespace cv;
using namespace face;

using namespace std;

namespace Ui {
class strangersDialog;
}

class strangersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit strangersDialog(Ptr<FaceRecognizer> model,QWidget *parent = 0,QString strangers=tr("/strangers"),int strangersNum=0,int registerSum=0);
    ~strangersDialog();
    void setModelLBP(QString modelLBP);
signals:
    void addPeopleSignals();

private slots:
    void on_addButton_clicked();
    void openAddPeopleDialog();
    void trans();

private:
    void addTableItem();
    void strangersTrans(vector<QString> s,int label);

public:
    addPeopleDialog *addPeople;

private:
    Ui::strangersDialog *ui;

    QList<QTableWidgetItem *> selected;
    Ptr<FaceRecognizer> model;
    QString s_strangers;
    QString s_modelLBP;
    int col;
    int i_strangersNum;
    int i_registerSum;
};

#endif // STRANGERSDIALOG_H
