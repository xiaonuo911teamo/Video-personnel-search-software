#include "registeredpeopledialog.h"
#include "ui_registeredpeopledialog.h"
#include "tipdialog.h"

RegisteredPeopleDialog::RegisteredPeopleDialog(QWidget *parent,vector<PeopleSettings*>& p) :
    QDialog(parent),ui(new Ui::RegisteredPeopleDialog),people(p)
{
    ui->setupUi(this);
    peopleWidgetList.reserve(p.size()+2);
    
    for(size_t i=0;i<p.size();i++)
    {
        QListWidgetItem* item = new QListWidgetItem();
        peopleListItem* itemWidget = new peopleListItem(0,people[i]);

        item->setSizeHint(QSize(0,120));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,itemWidget);
        peopleWidgetList[i]=itemWidget;            //保存List内部Widget地址
        //ui->listWidget->addItem(tr("123"));
    }
    if(ui->listWidget->count()>0)
        ui->listWidget->setCurrentRow(0);
    if(p.size()==0)
    {
        tipDialog* tip = new tipDialog(this,tr("无数据"));
        tip->setModal(true);
        tip->show();
    }
}

RegisteredPeopleDialog::~RegisteredPeopleDialog()
{
    delete ui;
}

/*点击修改按钮，可选中员工的信息*/
void RegisteredPeopleDialog::on_editButton_clicked()
{    
    int i=ui->listWidget->currentRow();
    peopleListItem* itemWidget = peopleWidgetList[i];

    if(itemWidget!=NULL)
    {
        itemWidget->edit();//将该item设置为可修改状态

    }
    else
    {
        tipDialog* tip = new tipDialog(this,tr("未选中项目"));
        tip->setModal(true);
        tip->show();
    }

}

/*
 * 确认后，将修改内容进行更新
*/
void RegisteredPeopleDialog::on_buttonBox_accepted()
{
    for(size_t i=0;i<people.size();i++)
    {
        PeopleSettings* p=people[i];
        peopleListItem* w=peopleWidgetList[i];
        p->setName(w->name->text().toLocal8Bit().data());
        p->setNote(w->note->document()->toPlainText().toLocal8Bit().data());
        p->setNum(w->num->text().toLocal8Bit().data());
        p->setAge(w->age->text().toLocal8Bit().data());
    }
}
