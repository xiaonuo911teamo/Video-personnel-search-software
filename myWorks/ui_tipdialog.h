/********************************************************************************
** Form generated from reading UI file 'tipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPDIALOG_H
#define UI_TIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_tipDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *tipDialog)
    {
        if (tipDialog->objectName().isEmpty())
            tipDialog->setObjectName(QStringLiteral("tipDialog"));
        tipDialog->resize(320, 240);
        buttonBox = new QDialogButtonBox(tipDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(70, 190, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(tipDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(30, 40, 251, 121));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setLineWidth(1);
        textEdit->setUndoRedoEnabled(true);
        textEdit->setReadOnly(true);

        retranslateUi(tipDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), tipDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), tipDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(tipDialog);
    } // setupUi

    void retranslateUi(QDialog *tipDialog)
    {
        tipDialog->setWindowTitle(QApplication::translate("tipDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class tipDialog: public Ui_tipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPDIALOG_H
