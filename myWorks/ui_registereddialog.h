/********************************************************************************
** Form generated from reading UI file 'registereddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTEREDDIALOG_H
#define UI_REGISTEREDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registeredDialog
{
public:
    QListWidget *listWidget;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *registeredDialog)
    {
        if (registeredDialog->objectName().isEmpty())
            registeredDialog->setObjectName(QStringLiteral("registeredDialog"));
        registeredDialog->resize(640, 480);
        listWidget = new QListWidget(registeredDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 491, 451));
        confirmButton = new QPushButton(registeredDialog);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(540, 50, 75, 23));
        cancelButton = new QPushButton(registeredDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(540, 90, 75, 23));

        retranslateUi(registeredDialog);

        QMetaObject::connectSlotsByName(registeredDialog);
    } // setupUi

    void retranslateUi(QDialog *registeredDialog)
    {
        registeredDialog->setWindowTitle(QApplication::translate("registeredDialog", "Dialog", 0));
        confirmButton->setText(QApplication::translate("registeredDialog", "\351\200\211\345\256\232", 0));
        cancelButton->setText(QApplication::translate("registeredDialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class registeredDialog: public Ui_registeredDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTEREDDIALOG_H
