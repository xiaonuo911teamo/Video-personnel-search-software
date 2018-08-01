#include "tipdialog.h"
#include "ui_tipdialog.h"

tipDialog::tipDialog(QWidget *parent,QString tip) :
    QDialog(parent),
    ui(new Ui::tipDialog),s_tip(tip)
{
    ui->setupUi(this);

    ui->textEdit->setText(s_tip);
    ui->textEdit->setAlignment(Qt::AlignCenter);
    QPalette pal = palette();
    pal.setColor(QPalette::Base,QColor(255,255,255,0));
    ui->textEdit->setPalette(pal);
    setModal(true);
    show();
}

tipDialog::~tipDialog()
{
    delete ui;
}
