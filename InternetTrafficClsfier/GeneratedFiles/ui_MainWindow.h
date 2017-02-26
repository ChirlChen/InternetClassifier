/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QAction *actionBegin;
    QAction *actionShow;
    QAction *actionBegin_1;
    QAction *action_2;
    QAction *actionExit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuClassify;
    QMenu *menuResults;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QStringLiteral("CMainWindow"));
        CMainWindow->resize(643, 409);
        CMainWindow->setMinimumSize(QSize(643, 409));
        CMainWindow->setMaximumSize(QSize(1677721, 16777215));
        actionBegin = new QAction(CMainWindow);
        actionBegin->setObjectName(QStringLiteral("actionBegin"));
        actionBegin->setCheckable(true);
        actionShow = new QAction(CMainWindow);
        actionShow->setObjectName(QStringLiteral("actionShow"));
        actionShow->setCheckable(true);
        actionBegin_1 = new QAction(CMainWindow);
        actionBegin_1->setObjectName(QStringLiteral("actionBegin_1"));
        actionBegin_1->setCheckable(false);
        actionBegin_1->setEnabled(false);
        action_2 = new QAction(CMainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setCheckable(true);
        actionExit = new QAction(CMainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(true);
        centralWidget = new QWidget(CMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        CMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 643, 23));
        menuClassify = new QMenu(menuBar);
        menuClassify->setObjectName(QStringLiteral("menuClassify"));
        menuClassify->setAutoFillBackground(true);
        menuResults = new QMenu(menuBar);
        menuResults->setObjectName(QStringLiteral("menuResults"));
        menuResults->setAutoFillBackground(true);
        CMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuClassify->menuAction());
        menuBar->addAction(menuResults->menuAction());
        menuClassify->addSeparator();
        menuClassify->addAction(actionBegin);
        menuClassify->addAction(actionBegin_1);
        menuClassify->addSeparator();
        menuClassify->addAction(actionExit);
        menuResults->addSeparator();
        menuResults->addAction(actionShow);
        menuResults->addAction(action_2);

        retranslateUi(CMainWindow);

        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QApplication::translate("CMainWindow", "\347\275\221\347\273\234\346\265\201\351\207\217\345\210\206\347\261\273\347\263\273\347\273\237", 0));
        actionBegin->setText(QApplication::translate("CMainWindow", "\347\273\237\350\256\241\346\263\225\345\210\206\347\261\273", 0));
#ifndef QT_NO_TOOLTIP
        actionBegin->setToolTip(QApplication::translate("CMainWindow", "\347\273\237\350\256\241\346\263\225\345\210\206\347\261\273", 0));
#endif // QT_NO_TOOLTIP
        actionBegin->setShortcut(QApplication::translate("CMainWindow", "Alt+Shift+C", 0));
        actionShow->setText(QApplication::translate("CMainWindow", "\345\210\206\347\261\273\347\273\223\346\236\234\357\274\210\346\246\202\347\216\207\357\274\211", 0));
#ifndef QT_NO_TOOLTIP
        actionShow->setToolTip(QApplication::translate("CMainWindow", "\346\230\276\347\244\272\345\210\206\347\261\273\347\273\223\346\236\234\347\232\204\346\267\267\346\262\214\347\237\251\351\230\265", 0));
#endif // QT_NO_TOOLTIP
        actionShow->setShortcut(QApplication::translate("CMainWindow", "Alt+S", 0));
        actionBegin_1->setText(QApplication::translate("CMainWindow", "\346\255\243\346\200\201\345\210\206\345\270\203\346\263\225\345\210\206\347\261\273", 0));
#ifndef QT_NO_TOOLTIP
        actionBegin_1->setToolTip(QApplication::translate("CMainWindow", "\346\255\243\346\200\201\345\210\206\345\270\203\346\263\225\345\210\206\347\261\273", 0));
#endif // QT_NO_TOOLTIP
        actionBegin_1->setShortcut(QApplication::translate("CMainWindow", "Alt+C", 0));
        action_2->setText(QApplication::translate("CMainWindow", "\345\210\206\347\261\273\347\273\223\346\236\234\357\274\210\346\225\260\345\200\274\357\274\211", 0));
#ifndef QT_NO_TOOLTIP
        action_2->setToolTip(QApplication::translate("CMainWindow", "\346\230\276\347\244\272\345\210\206\347\261\273\345\210\260\346\257\217\347\247\215\347\261\273\345\236\213\347\232\204\347\273\223\346\236\234\346\225\260\346\215\256\346\235\241\346\225\260", 0));
#endif // QT_NO_TOOLTIP
        action_2->setShortcut(QApplication::translate("CMainWindow", "Alt+Shift+S", 0));
        actionExit->setText(QApplication::translate("CMainWindow", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("CMainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("CMainWindow", "Alt+E", 0));
        menuClassify->setTitle(QApplication::translate("CMainWindow", "\345\274\200\345\247\213", 0));
        menuResults->setTitle(QApplication::translate("CMainWindow", "\347\273\223\346\236\234", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
