/********************************************************************************
** Form generated from reading UI file 'testbuilderwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTBUILDERWINDOW_H
#define UI_TESTBUILDERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testBuilderwindow
{
public:
    QHBoxLayout *horizontalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab_testMake;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lab1_lv;
    QSpacerItem *horizontalSpacer_9;
    QLabel *lab1_wordNum;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *le1_word;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn1_detect;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QLabel *lab1_display;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn1_confirm;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn1_exit;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_search;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QRadioButton *rbtn2_player;
    QRadioButton *rbtn2_testbuilder;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_15;
    QLineEdit *le2_search;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *btn2_search;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_7;
    QWidget *tab_list;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *rbtn3_player;
    QSpacerItem *horizontalSpacer_13;
    QRadioButton *rbtn3_testbuilder;
    QSpacerItem *horizontalSpacer_18;
    QComboBox *cb3_type;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *btn3_update;
    QTableView *tableView;
    QWidget *tab_my;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *lab4_accountName;
    QLabel *lab4_name;
    QLabel *lab4_lv;
    QLabel *lab4_testNum;
    QSpacerItem *verticalSpacer_8;

    void setupUi(QDialog *testBuilderwindow)
    {
        if (testBuilderwindow->objectName().isEmpty())
            testBuilderwindow->setObjectName(QString::fromUtf8("testBuilderwindow"));
        testBuilderwindow->resize(700, 650);
        testBuilderwindow->setMinimumSize(QSize(700, 650));
        testBuilderwindow->setMaximumSize(QSize(700, 650));
        horizontalLayout_8 = new QHBoxLayout(testBuilderwindow);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tabWidget = new QTabWidget(testBuilderwindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_testMake = new QWidget();
        tab_testMake->setObjectName(QString::fromUtf8("tab_testMake"));
        horizontalLayout_5 = new QHBoxLayout(tab_testMake);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        lab1_lv = new QLabel(tab_testMake);
        lab1_lv->setObjectName(QString::fromUtf8("lab1_lv"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lab1_lv->setFont(font);

        horizontalLayout_3->addWidget(lab1_lv);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        lab1_wordNum = new QLabel(tab_testMake);
        lab1_wordNum->setObjectName(QString::fromUtf8("lab1_wordNum"));
        lab1_wordNum->setFont(font);

        horizontalLayout_3->addWidget(lab1_wordNum);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        horizontalLayout_3->setStretch(0, 8);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 4);
        horizontalLayout_3->setStretch(4, 8);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        le1_word = new QLineEdit(tab_testMake);
        le1_word->setObjectName(QString::fromUtf8("le1_word"));

        horizontalLayout->addWidget(le1_word);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btn1_detect = new QPushButton(tab_testMake);
        btn1_detect->setObjectName(QString::fromUtf8("btn1_detect"));

        horizontalLayout->addWidget(btn1_detect);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        lab1_display = new QLabel(tab_testMake);
        lab1_display->setObjectName(QString::fromUtf8("lab1_display"));

        horizontalLayout_4->addWidget(lab1_display);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 7);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn1_confirm = new QPushButton(tab_testMake);
        btn1_confirm->setObjectName(QString::fromUtf8("btn1_confirm"));

        horizontalLayout_2->addWidget(btn1_confirm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn1_exit = new QPushButton(tab_testMake);
        btn1_exit->setObjectName(QString::fromUtf8("btn1_exit"));

        horizontalLayout_2->addWidget(btn1_exit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        horizontalLayout_5->addLayout(verticalLayout);

        tabWidget->addTab(tab_testMake, QString());
        tab_search = new QWidget();
        tab_search->setObjectName(QString::fromUtf8("tab_search"));
        verticalLayout_2 = new QVBoxLayout(tab_search);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        rbtn2_player = new QRadioButton(tab_search);
        rbtn2_player->setObjectName(QString::fromUtf8("rbtn2_player"));

        horizontalLayout_6->addWidget(rbtn2_player);

        rbtn2_testbuilder = new QRadioButton(tab_search);
        rbtn2_testbuilder->setObjectName(QString::fromUtf8("rbtn2_testbuilder"));

        horizontalLayout_6->addWidget(rbtn2_testbuilder);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 2);
        horizontalLayout_6->setStretch(2, 2);
        horizontalLayout_6->setStretch(3, 5);

        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_15);

        le2_search = new QLineEdit(tab_search);
        le2_search->setObjectName(QString::fromUtf8("le2_search"));

        horizontalLayout_7->addWidget(le2_search);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);

        btn2_search = new QPushButton(tab_search);
        btn2_search->setObjectName(QString::fromUtf8("btn2_search"));

        horizontalLayout_7->addWidget(btn2_search);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 6);
        horizontalLayout_7->setStretch(2, 2);
        horizontalLayout_7->setStretch(3, 1);
        horizontalLayout_7->setStretch(4, 3);

        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        verticalLayout_3->setStretch(0, 5);
        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 2);
        verticalLayout_3->setStretch(4, 5);

        verticalLayout_2->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_search, QString());
        tab_list = new QWidget();
        tab_list->setObjectName(QString::fromUtf8("tab_list"));
        verticalLayout_6 = new QVBoxLayout(tab_list);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        rbtn3_player = new QRadioButton(tab_list);
        rbtn3_player->setObjectName(QString::fromUtf8("rbtn3_player"));

        horizontalLayout_9->addWidget(rbtn3_player);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);

        rbtn3_testbuilder = new QRadioButton(tab_list);
        rbtn3_testbuilder->setObjectName(QString::fromUtf8("rbtn3_testbuilder"));

        horizontalLayout_9->addWidget(rbtn3_testbuilder);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_18);

        cb3_type = new QComboBox(tab_list);
        cb3_type->addItem(QString());
        cb3_type->addItem(QString());
        cb3_type->setObjectName(QString::fromUtf8("cb3_type"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cb3_type->sizePolicy().hasHeightForWidth());
        cb3_type->setSizePolicy(sizePolicy);
        cb3_type->setMinimumSize(QSize(0, 20));

        horizontalLayout_9->addWidget(cb3_type);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_19);

        btn3_update = new QPushButton(tab_list);
        btn3_update->setObjectName(QString::fromUtf8("btn3_update"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn3_update->sizePolicy().hasHeightForWidth());
        btn3_update->setSizePolicy(sizePolicy1);
        btn3_update->setMinimumSize(QSize(0, 20));

        horizontalLayout_9->addWidget(btn3_update);

        horizontalLayout_9->setStretch(0, 2);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 2);
        horizontalLayout_9->setStretch(3, 4);
        horizontalLayout_9->setStretch(4, 2);
        horizontalLayout_9->setStretch(5, 1);
        horizontalLayout_9->setStretch(6, 2);

        verticalLayout_4->addLayout(horizontalLayout_9);

        tableView = new QTableView(tab_list);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_4->addWidget(tableView);


        verticalLayout_6->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_list, QString());
        tab_my = new QWidget();
        tab_my->setObjectName(QString::fromUtf8("tab_my"));
        verticalLayout_5 = new QVBoxLayout(tab_my);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lab4_accountName = new QLabel(tab_my);
        lab4_accountName->setObjectName(QString::fromUtf8("lab4_accountName"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Copperplate Gothic Light"));
        font1.setPointSize(20);
        lab4_accountName->setFont(font1);

        verticalLayout_7->addWidget(lab4_accountName);

        lab4_name = new QLabel(tab_my);
        lab4_name->setObjectName(QString::fromUtf8("lab4_name"));
        lab4_name->setFont(font1);

        verticalLayout_7->addWidget(lab4_name);

        lab4_lv = new QLabel(tab_my);
        lab4_lv->setObjectName(QString::fromUtf8("lab4_lv"));
        lab4_lv->setFont(font1);

        verticalLayout_7->addWidget(lab4_lv);

        lab4_testNum = new QLabel(tab_my);
        lab4_testNum->setObjectName(QString::fromUtf8("lab4_testNum"));
        lab4_testNum->setFont(font1);

        verticalLayout_7->addWidget(lab4_testNum);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_8);

        verticalLayout_8->setStretch(0, 5);
        verticalLayout_8->setStretch(1, 1);

        verticalLayout_5->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_my, QString());

        horizontalLayout_8->addWidget(tabWidget);


        retranslateUi(testBuilderwindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(testBuilderwindow);
    } // setupUi

    void retranslateUi(QDialog *testBuilderwindow)
    {
        testBuilderwindow->setWindowTitle(QApplication::translate("testBuilderwindow", "Dialog", nullptr));
        lab1_lv->setText(QApplication::translate("testBuilderwindow", "LV\357\274\232", nullptr));
        lab1_wordNum->setText(QApplication::translate("testBuilderwindow", "\345\207\272\351\242\230\346\225\260:", nullptr));
        btn1_detect->setText(QApplication::translate("testBuilderwindow", "\346\243\200\346\265\213", nullptr));
        lab1_display->setText(QString());
        btn1_confirm->setText(QApplication::translate("testBuilderwindow", "\347\241\256\345\256\232", nullptr));
        btn1_exit->setText(QApplication::translate("testBuilderwindow", "\351\200\200\345\207\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_testMake), QApplication::translate("testBuilderwindow", "\345\207\272\351\242\230", nullptr));
        rbtn2_player->setText(QApplication::translate("testBuilderwindow", "\351\227\257\345\205\263\350\200\205", nullptr));
        rbtn2_testbuilder->setText(QApplication::translate("testBuilderwindow", "\345\207\272\351\242\230\350\200\205", nullptr));
        btn2_search->setText(QApplication::translate("testBuilderwindow", "\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_search), QApplication::translate("testBuilderwindow", "\346\237\245\350\257\242", nullptr));
        rbtn3_player->setText(QApplication::translate("testBuilderwindow", "\351\227\257\345\205\263\350\200\205", nullptr));
        rbtn3_testbuilder->setText(QApplication::translate("testBuilderwindow", "\345\207\272\351\242\230\350\200\205", nullptr));
        cb3_type->setItemText(0, QApplication::translate("testBuilderwindow", "\347\255\211\347\272\247", nullptr));
        cb3_type->setItemText(1, QApplication::translate("testBuilderwindow", "\351\227\257\345\205\263\346\225\260", nullptr));

        btn3_update->setText(QApplication::translate("testBuilderwindow", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_list), QApplication::translate("testBuilderwindow", "\346\216\222\350\241\214\346\246\234", nullptr));
        lab4_accountName->setText(QApplication::translate("testBuilderwindow", "\350\264\246\346\210\267\345\220\215:", nullptr));
        lab4_name->setText(QApplication::translate("testBuilderwindow", "\346\270\270\346\210\217\345\220\215:", nullptr));
        lab4_lv->setText(QApplication::translate("testBuilderwindow", "\347\255\211\347\272\247:", nullptr));
        lab4_testNum->setText(QApplication::translate("testBuilderwindow", "\345\207\272\351\242\230\346\225\260:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_my), QApplication::translate("testBuilderwindow", "\346\210\221\347\232\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testBuilderwindow: public Ui_testBuilderwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTBUILDERWINDOW_H
