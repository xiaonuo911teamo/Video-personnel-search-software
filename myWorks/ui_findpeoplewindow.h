/********************************************************************************
** Form generated from reading UI file 'findpeoplewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPEOPLEWINDOW_H
#define UI_FINDPEOPLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findPeopleWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionConfigure;
    QAction *actionStrangers;
    QAction *actionRegisteredPeoples;
    QWidget *centralWidget;
    QLabel *videoLabel;
    QPushButton *originalButton;
    QPushButton *recognizeButton;
    QPushButton *specifiedButton;
    QPushButton *strangerButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *findPeopleWindow)
    {
        if (findPeopleWindow->objectName().isEmpty())
            findPeopleWindow->setObjectName(QStringLiteral("findPeopleWindow"));
        findPeopleWindow->resize(526, 411);
        actionOpen_File = new QAction(findPeopleWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionConfigure = new QAction(findPeopleWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        actionStrangers = new QAction(findPeopleWindow);
        actionStrangers->setObjectName(QStringLiteral("actionStrangers"));
        actionRegisteredPeoples = new QAction(findPeopleWindow);
        actionRegisteredPeoples->setObjectName(QStringLiteral("actionRegisteredPeoples"));
        centralWidget = new QWidget(findPeopleWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        videoLabel = new QLabel(centralWidget);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));
        videoLabel->setGeometry(QRect(0, 0, 431, 311));
        videoLabel->setAlignment(Qt::AlignCenter);
        originalButton = new QPushButton(centralWidget);
        originalButton->setObjectName(QStringLiteral("originalButton"));
        originalButton->setGeometry(QRect(321, 191, 75, 23));
        recognizeButton = new QPushButton(centralWidget);
        recognizeButton->setObjectName(QStringLiteral("recognizeButton"));
        recognizeButton->setGeometry(QRect(321, 220, 75, 23));
        specifiedButton = new QPushButton(centralWidget);
        specifiedButton->setObjectName(QStringLiteral("specifiedButton"));
        specifiedButton->setGeometry(QRect(321, 249, 75, 23));
        strangerButton = new QPushButton(centralWidget);
        strangerButton->setObjectName(QStringLiteral("strangerButton"));
        strangerButton->setGeometry(QRect(321, 278, 75, 23));
        findPeopleWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(findPeopleWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 526, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        findPeopleWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(findPeopleWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        findPeopleWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(findPeopleWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        findPeopleWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionOpen_File);
        menu->addAction(actionStrangers);
        menu->addAction(actionRegisteredPeoples);
        menu_2->addAction(actionConfigure);

        retranslateUi(findPeopleWindow);

        QMetaObject::connectSlotsByName(findPeopleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *findPeopleWindow)
    {
        findPeopleWindow->setWindowTitle(QApplication::translate("findPeopleWindow", "findPeopleWindow", 0));
#ifndef QT_NO_TOOLTIP
        findPeopleWindow->setToolTip(QApplication::translate("findPeopleWindow", "\350\247\206\351\242\221\347\252\227\345\217\243.", 0));
#endif // QT_NO_TOOLTIP
        actionOpen_File->setText(QApplication::translate("findPeopleWindow", "Open File ...", 0));
        actionConfigure->setText(QApplication::translate("findPeopleWindow", "configure ...", 0));
        actionStrangers->setText(QApplication::translate("findPeopleWindow", "Strangers ...", 0));
        actionRegisteredPeoples->setText(QApplication::translate("findPeopleWindow", "Registered Peoples ...", 0));
#ifndef QT_NO_STATUSTIP
        videoLabel->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        videoLabel->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        videoLabel->setText(QApplication::translate("findPeopleWindow", "\346\226\207\344\273\266->Open File", 0));
#ifndef QT_NO_TOOLTIP
        originalButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        originalButton->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        originalButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        originalButton->setText(QApplication::translate("findPeopleWindow", "\345\216\237\350\247\206\351\242\221", 0));
        recognizeButton->setText(QApplication::translate("findPeopleWindow", "\350\257\206\345\210\253\344\272\272\350\204\270", 0));
        specifiedButton->setText(QApplication::translate("findPeopleWindow", "\346\214\207\345\256\232\350\257\206\345\210\253", 0));
        strangerButton->setText(QApplication::translate("findPeopleWindow", "\351\231\214\347\224\237\344\272\272", 0));
        menu->setTitle(QApplication::translate("findPeopleWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("findPeopleWindow", "\351\200\211\351\241\271", 0));
    } // retranslateUi

};

namespace Ui {
    class findPeopleWindow: public Ui_findPeopleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPEOPLEWINDOW_H
