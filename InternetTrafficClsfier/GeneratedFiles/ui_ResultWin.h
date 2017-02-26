/********************************************************************************
** Form generated from reading UI file 'ResultWin.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWIN_H
#define UI_RESULTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CResultWin
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *CResultWin)
    {
        if (CResultWin->objectName().isEmpty())
            CResultWin->setObjectName(QStringLiteral("CResultWin"));
        CResultWin->resize(400, 300);
        horizontalLayout = new QHBoxLayout(CResultWin);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(CResultWin);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(CResultWin);

        QMetaObject::connectSlotsByName(CResultWin);
    } // setupUi

    void retranslateUi(QWidget *CResultWin)
    {
        CResultWin->setWindowTitle(QApplication::translate("CResultWin", "CResultWin", 0));
    } // retranslateUi

};

namespace Ui {
    class CResultWin: public Ui_CResultWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWIN_H
