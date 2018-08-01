/********************************************************************************
** Form generated from reading UI file 'addpeopledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPEOPLEDIALOG_H
#define UI_ADDPEOPLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addPeopleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *transButton;
    QLabel *label_5;
    QToolButton *pictureButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_2;
    QLineEdit *numLineEdit;
    QLabel *label_3;
    QLineEdit *ageLineEdit;
    QLabel *label_4;
    QTextEdit *noteTextEdit;

    void setupUi(QDialog *addPeopleDialog)
    {
        if (addPeopleDialog->objectName().isEmpty())
            addPeopleDialog->setObjectName(QStringLiteral("addPeopleDialog"));
        addPeopleDialog->resize(479, 373);
        buttonBox = new QDialogButtonBox(addPeopleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-190, 320, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        transButton = new QPushButton(addPeopleDialog);
        transButton->setObjectName(QStringLiteral("transButton"));
        transButton->setGeometry(QRect(190, 324, 75, 23));
        label_5 = new QLabel(addPeopleDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 24, 54, 12));
        pictureButton = new QToolButton(addPeopleDialog);
        pictureButton->setObjectName(QStringLiteral("pictureButton"));
        pictureButton->setGeometry(QRect(330, 20, 111, 121));
        pictureButton->setArrowType(Qt::NoArrow);
        layoutWidget = new QWidget(addPeopleDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 231, 272));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        numLineEdit = new QLineEdit(layoutWidget);
        numLineEdit->setObjectName(QStringLiteral("numLineEdit"));

        gridLayout->addWidget(numLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        ageLineEdit = new QLineEdit(layoutWidget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        gridLayout->addWidget(ageLineEdit, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        noteTextEdit = new QTextEdit(layoutWidget);
        noteTextEdit->setObjectName(QStringLiteral("noteTextEdit"));

        gridLayout->addWidget(noteTextEdit, 3, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 4);

        retranslateUi(addPeopleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), addPeopleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addPeopleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(addPeopleDialog);
    } // setupUi

    void retranslateUi(QDialog *addPeopleDialog)
    {
        addPeopleDialog->setWindowTitle(QApplication::translate("addPeopleDialog", "Dialog", 0));
        transButton->setText(QApplication::translate("addPeopleDialog", "\350\256\255\347\273\203", 0));
        label_5->setText(QApplication::translate("addPeopleDialog", "\347\205\247\347\211\207\357\274\232", 0));
        pictureButton->setText(QApplication::translate("addPeopleDialog", "...", 0));
        label->setText(QApplication::translate("addPeopleDialog", "\345\247\223\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("addPeopleDialog", "\345\267\245\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("addPeopleDialog", "\345\271\264\351\276\204\357\274\232", 0));
        label_4->setText(QApplication::translate("addPeopleDialog", "\345\244\207\346\263\250\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class addPeopleDialog: public Ui_addPeopleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPEOPLEDIALOG_H
