#ifndef TIPDIALOG_H
#define TIPDIALOG_H

#include <QDialog>

namespace Ui {
class tipDialog;
}

class tipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tipDialog(QWidget *parent = 0,QString tip=tr("是否确认？"));
    ~tipDialog();

private:
    Ui::tipDialog *ui;

    QString s_tip;
};

#endif // TIPDIALOG_H
