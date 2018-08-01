#include "registereddialog.h"
#include "ui_registereddialog.h"
#include "peoplelistitem.h"

registeredDialog::registeredDialog(QWidget *parent,vector<PeopleSettings*>& peopleList) :
    QDialog(parent),
    ui(new Ui::registeredDialog)
{
    ui->setupUi(this);

    for(size_t i=0;i<peopleList.size();i++)
    {
        QListWidgetItem* item = new QListWidgetItem();
        peopleListItem* itemWidget = new peopleListItem(0,peopleList[i]);

        item->setSizeHint(QSize(0,120));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,itemWidget);
    }
    ui->listWidget->setCurrentRow(0);
}

registeredDialog::~registeredDialog()
{
    delete ui;
}

void registeredDialog::on_confirmButton_clicked()
{
    emit specifiedLabel(ui->listWidget->currentRow());
    close();
}

void registeredDialog::on_cancelButton_clicked()
{
    close();
}
