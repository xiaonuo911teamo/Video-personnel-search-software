#include "peoplelistitem.h"
#include<QString>
#include <QLabel>
#include<QBoxLayout>

peopleListItem::peopleListItem(QWidget *parent,QString s_name,QString s_num,int i_age,QString s_note,QString s_picAddr):
    QWidget(parent)
{
    QLabel* nameLabel = new QLabel;
    nameLabel->setText(QObject::tr("姓名："));
    name = new QLineEdit;
    name->setText(s_name);
    name->setReadOnly(true);

    QLabel* numLabel = new QLabel;
    numLabel->setText(QObject::tr("工号："));
    num = new QLineEdit;
    num->setText(s_num);
    num->setReadOnly(true);

    QLabel* ageLabel = new QLabel;
    ageLabel->setText(QObject::tr("年龄："));
    age = new QLineEdit;
    age->setText(QObject::tr("%1").arg(i_age));
    age->setReadOnly(true);

    QLabel* noteLabel = new QLabel;
    noteLabel->setText(QObject::tr("备注："));
    note = new QTextEdit;
    note->setText(s_note);
    note->setReadOnly(true);

    QPixmap icon(s_picAddr);
    pic = new QLabel;
    pic->setPixmap(icon);

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(pic,0,0,3,1);
    layout->addWidget(nameLabel,0,1);
    layout->addWidget(name,0,2);
    layout->addWidget(numLabel,1,1);
    layout->addWidget(num,1,2);
    layout->addWidget(ageLabel,2,1);
    layout->addWidget(age,2,2);
    layout->addWidget(noteLabel,0,3);
    layout->addWidget(note,1,3,2,1);
    layout->setColumnStretch(3,2);

    setLayout(layout);
}

peopleListItem::peopleListItem(QWidget* parent,PeopleSettings* p):
    QWidget(parent)
{
    QLabel* nameLabel = new QLabel;
    nameLabel->setText(QObject::tr("姓名："));
    name = new QLineEdit;
    name->setText(QString::fromStdString((*p).s_name));
    name->setReadOnly(true);

    QLabel* numLabel = new QLabel;
    numLabel->setText(QObject::tr("工号："));
    num = new QLineEdit;
    num->setText(QString::fromStdString((*p).s_num));
    num->setReadOnly(true);

    QLabel* ageLabel = new QLabel;
    ageLabel->setText(QObject::tr("年龄："));
    age = new QLineEdit;
    age->setText(QObject::tr("%1").arg((*p).i_age));
    age->setReadOnly(true);

    QLabel* noteLabel = new QLabel;
    noteLabel->setText(QObject::tr("备注："));
    note = new QTextEdit;
    note->setText(QString::fromStdString((*p).s_note));
    note->setReadOnly(true);

    QPixmap icon(QString::fromStdString((*p).s_picAddr));
    pic = new QLabel;
    pic->setPixmap(icon);

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(pic,0,0,3,1);
    layout->addWidget(nameLabel,0,1);
    layout->addWidget(name,0,2);
    layout->addWidget(numLabel,1,1);
    layout->addWidget(num,1,2);
    layout->addWidget(ageLabel,2,1);
    layout->addWidget(age,2,2);
    layout->addWidget(noteLabel,0,3);
    layout->addWidget(note,1,3,2,1);
    layout->setColumnStretch(3,2);

    setLayout(layout);
}

/*****************************
    编辑函数，将该item变为可编辑状态
******************************/
void peopleListItem::edit()
{
    name->setReadOnly(false);
    num->setReadOnly(false);
    age->setReadOnly(false);
    note->setReadOnly(false);
}

peopleListItem::~peopleListItem()
{

}

