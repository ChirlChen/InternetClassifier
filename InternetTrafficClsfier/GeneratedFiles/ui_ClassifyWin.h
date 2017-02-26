/********************************************************************************
** Form generated from reading UI file 'ClassifyWin.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSIFYWIN_H
#define UI_CLASSIFYWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CClassifyWin
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_10;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *CClassifyWin)
    {
        if (CClassifyWin->objectName().isEmpty())
            CClassifyWin->setObjectName(QStringLiteral("CClassifyWin"));
        CClassifyWin->resize(712, 388);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CClassifyWin->sizePolicy().hasHeightForWidth());
        CClassifyWin->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(CClassifyWin);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(CClassifyWin);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(0, 90));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setMinimumSize(QSize(133, 20));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(75, 20));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(133, 20));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(75, 20));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(CClassifyWin);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox_16 = new QCheckBox(groupBox);
        checkBox_16->setObjectName(QStringLiteral("checkBox_16"));
        checkBox_16->setEnabled(true);

        gridLayout->addWidget(checkBox_16, 3, 1, 1, 1);

        checkBox_12 = new QCheckBox(groupBox);
        checkBox_12->setObjectName(QStringLiteral("checkBox_12"));
        checkBox_12->setEnabled(true);

        gridLayout->addWidget(checkBox_12, 5, 1, 1, 1);

        checkBox_6 = new QCheckBox(groupBox);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setChecked(true);

        gridLayout->addWidget(checkBox_6, 5, 0, 1, 1);

        checkBox_7 = new QCheckBox(groupBox);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));
        checkBox_7->setChecked(true);

        gridLayout->addWidget(checkBox_7, 6, 0, 1, 1);

        checkBox_8 = new QCheckBox(groupBox);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));
        checkBox_8->setChecked(true);

        gridLayout->addWidget(checkBox_8, 7, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        gridLayout->addWidget(checkBox_5, 4, 0, 1, 1);

        checkBox_9 = new QCheckBox(groupBox);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));
        checkBox_9->setEnabled(true);

        gridLayout->addWidget(checkBox_9, 7, 1, 1, 1);

        checkBox_14 = new QCheckBox(groupBox);
        checkBox_14->setObjectName(QStringLiteral("checkBox_14"));
        checkBox_14->setEnabled(true);

        gridLayout->addWidget(checkBox_14, 6, 1, 1, 1);

        checkBox_13 = new QCheckBox(groupBox);
        checkBox_13->setObjectName(QStringLiteral("checkBox_13"));
        checkBox_13->setEnabled(true);

        gridLayout->addWidget(checkBox_13, 4, 1, 1, 1);

        checkBox_15 = new QCheckBox(groupBox);
        checkBox_15->setObjectName(QStringLiteral("checkBox_15"));
        checkBox_15->setEnabled(true);

        gridLayout->addWidget(checkBox_15, 2, 1, 1, 1);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        gridLayout->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        gridLayout->addWidget(checkBox_3, 2, 0, 1, 1);

        checkBox_11 = new QCheckBox(groupBox);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));
        checkBox_11->setEnabled(true);

        gridLayout->addWidget(checkBox_11, 0, 1, 1, 1);

        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setChecked(true);

        gridLayout->addWidget(checkBox_4, 3, 0, 1, 1);

        checkBox_10 = new QCheckBox(groupBox);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));
        checkBox_10->setEnabled(true);

        gridLayout->addWidget(checkBox_10, 1, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        groupBox_3 = new QGroupBox(CClassifyWin);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(0, 45));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton_3);


        horizontalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(groupBox_3);

        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_5);
        QWidget::setTabOrder(checkBox_5, checkBox_6);
        QWidget::setTabOrder(checkBox_6, checkBox_7);
        QWidget::setTabOrder(checkBox_7, checkBox_8);
        QWidget::setTabOrder(checkBox_8, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_3);
        QWidget::setTabOrder(pushButton_3, checkBox_11);
        QWidget::setTabOrder(checkBox_11, checkBox_10);
        QWidget::setTabOrder(checkBox_10, checkBox_15);
        QWidget::setTabOrder(checkBox_15, checkBox_16);
        QWidget::setTabOrder(checkBox_16, checkBox_13);
        QWidget::setTabOrder(checkBox_13, checkBox_12);
        QWidget::setTabOrder(checkBox_12, checkBox_14);
        QWidget::setTabOrder(checkBox_14, checkBox_9);
        QWidget::setTabOrder(checkBox_9, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit);

        retranslateUi(CClassifyWin);

        QMetaObject::connectSlotsByName(CClassifyWin);
    } // setupUi

    void retranslateUi(QWidget *CClassifyWin)
    {
        CClassifyWin->setWindowTitle(QApplication::translate("CClassifyWin", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        groupBox_2->setTitle(QApplication::translate("CClassifyWin", "\346\225\260\346\215\256\345\214\205\351\200\211\346\213\251\357\274\232", 0));
        lineEdit->setPlaceholderText(QApplication::translate("CClassifyWin", "\350\257\267\351\200\211\346\213\251\350\256\255\347\273\203\351\233\206\357\274\201", 0));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("CClassifyWin", "\345\277\253\346\215\267\351\224\256\357\274\210ctrl + o\357\274\211", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("CClassifyWin", "\346\211\223\345\274\200", 0));
        pushButton->setShortcut(QApplication::translate("CClassifyWin", "Ctrl+O", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("CClassifyWin", "\350\257\267\351\200\211\346\213\251\345\210\206\347\261\273\351\233\206\357\274\201", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("CClassifyWin", "\345\277\253\346\215\267\351\224\256\357\274\210ctrl + shift + o\357\274\211", 0));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("CClassifyWin", "\346\211\223\345\274\200", 0));
        pushButton_2->setShortcut(QApplication::translate("CClassifyWin", "Ctrl+Shift+O", 0));
        groupBox->setTitle(QApplication::translate("CClassifyWin", "\345\210\206\347\261\273\345\261\236\346\200\247\357\274\232", 0));
        checkBox_16->setText(QApplication::translate("CClassifyWin", "190", 0));
        checkBox_12->setText(QApplication::translate("CClassifyWin", "220", 0));
        checkBox_6->setText(QApplication::translate("CClassifyWin", "113", 0));
        checkBox_7->setText(QApplication::translate("CClassifyWin", "155", 0));
        checkBox_8->setText(QApplication::translate("CClassifyWin", "202", 0));
        checkBox_5->setText(QApplication::translate("CClassifyWin", "108", 0));
        checkBox_9->setText(QApplication::translate("CClassifyWin", "250", 0));
        checkBox_14->setText(QApplication::translate("CClassifyWin", "230", 0));
        checkBox_13->setText(QApplication::translate("CClassifyWin", "210", 0));
        checkBox_15->setText(QApplication::translate("CClassifyWin", "170", 0));
        checkBox_2->setText(QApplication::translate("CClassifyWin", "50", 0));
        checkBox->setText(QApplication::translate("CClassifyWin", "4", 0));
        checkBox_3->setText(QApplication::translate("CClassifyWin", "72", 0));
        checkBox_11->setText(QApplication::translate("CClassifyWin", "8", 0));
        checkBox_4->setText(QApplication::translate("CClassifyWin", "91", 0));
        checkBox_10->setText(QApplication::translate("CClassifyWin", "60", 0));
        groupBox_3->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("CClassifyWin", "\345\277\253\346\215\267\351\224\256\357\274\210ctrl + t\357\274\211", 0));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("CClassifyWin", "\345\274\200\345\247\213\350\256\255\347\273\203", 0));
        pushButton_4->setShortcut(QApplication::translate("CClassifyWin", "Ctrl+T", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("CClassifyWin", "\345\277\253\346\215\267\351\224\256\357\274\210ctrl + c\357\274\211", 0));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("CClassifyWin", "\345\274\200\345\247\213\345\210\206\347\261\273", 0));
        pushButton_3->setShortcut(QApplication::translate("CClassifyWin", "Ctrl+C", 0));
    } // retranslateUi

};

namespace Ui {
    class CClassifyWin: public Ui_CClassifyWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSIFYWIN_H
