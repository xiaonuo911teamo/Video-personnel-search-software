/********************************************************************************
** Form generated from reading UI file 'configuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREDIALOG_H
#define UI_CONFIGUREDIALOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configureDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *faceCascadeAddrLineEdit;
    QPushButton *faceCascadeAddrButton;
    QLabel *label_2;
    QLineEdit *modelPCAAddrLineEdit;
    QPushButton *modelPCAAddrButton;
    QLabel *label_3;
    QLineEdit *strangersAddrLineEdit;
    QPushButton *strangersAddrButton;

    void setupUi(QDialog *configureDialog)
    {
        if (configureDialog->objectName().isEmpty())
            configureDialog->setObjectName(QStringLiteral("configureDialog"));
        configureDialog->resize(640, 480);
        buttonBox = new QDialogButtonBox(configureDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 440, 621, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(configureDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 50, 511, 141));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        faceCascadeAddrLineEdit = new QLineEdit(widget);
        faceCascadeAddrLineEdit->setObjectName(QStringLiteral("faceCascadeAddrLineEdit"));

        gridLayout->addWidget(faceCascadeAddrLineEdit, 0, 1, 1, 1);

        faceCascadeAddrButton = new QPushButton(widget);
        faceCascadeAddrButton->setObjectName(QStringLiteral("faceCascadeAddrButton"));

        gridLayout->addWidget(faceCascadeAddrButton, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        modelPCAAddrLineEdit = new QLineEdit(widget);
        modelPCAAddrLineEdit->setObjectName(QStringLiteral("modelPCAAddrLineEdit"));

        gridLayout->addWidget(modelPCAAddrLineEdit, 1, 1, 1, 1);

        modelPCAAddrButton = new QPushButton(widget);
        modelPCAAddrButton->setObjectName(QStringLiteral("modelPCAAddrButton"));

        gridLayout->addWidget(modelPCAAddrButton, 1, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        strangersAddrLineEdit = new QLineEdit(widget);
        strangersAddrLineEdit->setObjectName(QStringLiteral("strangersAddrLineEdit"));

        gridLayout->addWidget(strangersAddrLineEdit, 2, 1, 1, 1);

        strangersAddrButton = new QPushButton(widget);
        strangersAddrButton->setObjectName(QStringLiteral("strangersAddrButton"));

        gridLayout->addWidget(strangersAddrButton, 2, 2, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 5);
        gridLayout->setColumnStretch(2, 1);

        retranslateUi(configureDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), configureDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), configureDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(configureDialog);
    } // setupUi

    void retranslateUi(QDialog *configureDialog)
    {
        configureDialog->setWindowTitle(QApplication::translate("configureDialog", "Dialog", 0));
        label->setText(QApplication::translate("configureDialog", "\344\272\272\350\204\270\350\257\206\345\210\253\345\231\250\350\267\257\345\276\204\357\274\210XML\357\274\211\357\274\232", 0));
        faceCascadeAddrButton->setText(QApplication::translate("configureDialog", "\351\200\211\346\213\251", 0));
        label_2->setText(QApplication::translate("configureDialog", "\345\267\262\345\255\230\345\234\250\344\272\272\345\221\230\347\211\271\345\276\201\350\267\257\345\276\204\357\274\210XML\357\274\211\357\274\232", 0));
        modelPCAAddrButton->setText(QApplication::translate("configureDialog", "\351\200\211\346\213\251", 0));
        label_3->setText(QApplication::translate("configureDialog", "\351\231\214\347\224\237\344\272\272\345\255\230\345\202\250\350\267\257\345\276\204 \357\274\232   ", 0));
        strangersAddrButton->setText(QApplication::translate("configureDialog", "\351\200\211\346\213\251", 0));
    } // retranslateUi

};

namespace Ui {
    class configureDialog: public Ui_configureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREDIALOG_H
