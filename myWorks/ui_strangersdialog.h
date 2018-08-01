/********************************************************************************
** Form generated from reading UI file 'strangersdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRANGERSDIALOG_H
#define UI_STRANGERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_strangersDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *tableWidget;
    QPushButton *addButton;

    void setupUi(QDialog *strangersDialog)
    {
        if (strangersDialog->objectName().isEmpty())
            strangersDialog->setObjectName(QStringLiteral("strangersDialog"));
        strangersDialog->resize(640, 480);
        buttonBox = new QDialogButtonBox(strangersDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(550, 390, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableWidget = new QTableWidget(strangersDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 521, 451));
        addButton = new QPushButton(strangersDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(550, 360, 81, 23));

        retranslateUi(strangersDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), strangersDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), strangersDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(strangersDialog);
    } // setupUi

    void retranslateUi(QDialog *strangersDialog)
    {
        strangersDialog->setWindowTitle(QApplication::translate("strangersDialog", "Dialog", 0));
        addButton->setText(QApplication::translate("strangersDialog", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class strangersDialog: public Ui_strangersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRANGERSDIALOG_H
