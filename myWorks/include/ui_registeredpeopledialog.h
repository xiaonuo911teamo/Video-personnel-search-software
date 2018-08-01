/********************************************************************************
** Form generated from reading UI file 'registeredpeopledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTEREDPEOPLEDIALOG_H
#define UI_REGISTEREDPEOPLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisteredPeopleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QPushButton *editButton;

    void setupUi(QDialog *RegisteredPeopleDialog)
    {
        if (RegisteredPeopleDialog->objectName().isEmpty())
            RegisteredPeopleDialog->setObjectName(QStringLiteral("RegisteredPeopleDialog"));
        RegisteredPeopleDialog->resize(640, 480);
        buttonBox = new QDialogButtonBox(RegisteredPeopleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(540, 70, 81, 341));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(RegisteredPeopleDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 501, 431));
        editButton = new QPushButton(RegisteredPeopleDialog);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(540, 40, 81, 23));

        retranslateUi(RegisteredPeopleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RegisteredPeopleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RegisteredPeopleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RegisteredPeopleDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisteredPeopleDialog)
    {
        RegisteredPeopleDialog->setWindowTitle(QApplication::translate("RegisteredPeopleDialog", "Dialog", 0));
        editButton->setText(QApplication::translate("RegisteredPeopleDialog", "\347\274\226\350\276\221", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisteredPeopleDialog: public Ui_RegisteredPeopleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTEREDPEOPLEDIALOG_H
