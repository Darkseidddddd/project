/********************************************************************************
** Form generated from reading UI file 'playerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERWINDOW_H
#define UI_PLAYERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playerwindow
{
public:
    QHBoxLayout *horizontalLayout_17;
    QTabWidget *tabWidget;
    QWidget *tab_play;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *cb_pattern;
    QComboBox *cb_difficulty;
    QPushButton *btn_multiplayer;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lab_checkpoint;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QLabel *lab_name;
    QLabel *lab_level;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_13;
    QProgressBar *pg_ex;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *lab_word;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lab_display;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *pg_time;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *le_word;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_start;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_restart;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_exit;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_search;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_17;
    QRadioButton *rbtn2_player;
    QRadioButton *rbtn2_testbuilder;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_16;
    QLineEdit *le2_search;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *btn2_search;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer_7;
    QWidget *tab_list;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QRadioButton *rbtn3_player;
    QSpacerItem *horizontalSpacer_20;
    QRadioButton *rbtn3_testbuilder;
    QSpacerItem *horizontalSpacer_22;
    QComboBox *cb3_type;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *btn3_update;
    QTableView *tableView;
    QWidget *tab_my;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *lab4_accountName;
    QLabel *lab4_name;
    QLabel *lab4_lv;
    QLabel *lab4_ckpoint;
    QHBoxLayout *horizontalLayout_16;
    QLabel *lab4_ex;
    QSpacerItem *horizontalSpacer_23;
    QProgressBar *pg4_ex;
    QSpacerItem *horizontalSpacer_24;

    void setupUi(QDialog *playerwindow)
    {
        if (playerwindow->objectName().isEmpty())
            playerwindow->setObjectName(QString::fromUtf8("playerwindow"));
        playerwindow->resize(700, 650);
        playerwindow->setMinimumSize(QSize(700, 650));
        playerwindow->setMaximumSize(QSize(700, 650));
        playerwindow->setLayoutDirection(Qt::LeftToRight);
        playerwindow->setAutoFillBackground(true);
        horizontalLayout_17 = new QHBoxLayout(playerwindow);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        tabWidget = new QTabWidget(playerwindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_play = new QWidget();
        tab_play->setObjectName(QString::fromUtf8("tab_play"));
        horizontalLayout_8 = new QHBoxLayout(tab_play);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        cb_pattern = new QComboBox(tab_play);
        cb_pattern->addItem(QString());
        cb_pattern->addItem(QString());
        cb_pattern->addItem(QString());
        cb_pattern->setObjectName(QString::fromUtf8("cb_pattern"));

        horizontalLayout_6->addWidget(cb_pattern);

        cb_difficulty = new QComboBox(tab_play);
        cb_difficulty->addItem(QString());
        cb_difficulty->addItem(QString());
        cb_difficulty->addItem(QString());
        cb_difficulty->addItem(QString());
        cb_difficulty->addItem(QString());
        cb_difficulty->addItem(QString());
        cb_difficulty->setObjectName(QString::fromUtf8("cb_difficulty"));

        horizontalLayout_6->addWidget(cb_difficulty);

        btn_multiplayer = new QPushButton(tab_play);
        btn_multiplayer->setObjectName(QString::fromUtf8("btn_multiplayer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_multiplayer->sizePolicy().hasHeightForWidth());
        btn_multiplayer->setSizePolicy(sizePolicy);
        btn_multiplayer->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_6->addWidget(btn_multiplayer);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lab_checkpoint = new QLabel(tab_play);
        lab_checkpoint->setObjectName(QString::fromUtf8("lab_checkpoint"));

        horizontalLayout_9->addWidget(lab_checkpoint);

        lcdNumber = new QLCDNumber(tab_play);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout_9->addWidget(lcdNumber);


        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_10->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        lab_name = new QLabel(tab_play);
        lab_name->setObjectName(QString::fromUtf8("lab_name"));

        horizontalLayout_4->addWidget(lab_name);

        lab_level = new QLabel(tab_play);
        lab_level->setObjectName(QString::fromUtf8("lab_level"));

        horizontalLayout_4->addWidget(lab_level);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        pg_ex = new QProgressBar(tab_play);
        pg_ex->setObjectName(QString::fromUtf8("pg_ex"));
        pg_ex->setValue(24);

        horizontalLayout_7->addWidget(pg_ex);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lab_word = new QTextBrowser(tab_play);
        lab_word->setObjectName(QString::fromUtf8("lab_word"));
        lab_word->setEnabled(true);
        lab_word->setMinimumSize(QSize(350, 100));
        lab_word->setMaximumSize(QSize(350, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(22);
        font.setBold(false);
        font.setWeight(50);
        lab_word->setFont(font);
        lab_word->setFocusPolicy(Qt::NoFocus);
        lab_word->setLayoutDirection(Qt::LeftToRight);
        lab_word->setAutoFillBackground(true);
        lab_word->setFrameShape(QFrame::StyledPanel);
        lab_word->setFrameShadow(QFrame::Sunken);
        lab_word->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lab_word->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lab_word->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        lab_word->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(lab_word);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        lab_display = new QLabel(tab_play);
        lab_display->setObjectName(QString::fromUtf8("lab_display"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        lab_display->setFont(font1);
        lab_display->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(lab_display);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pg_time = new QProgressBar(tab_play);
        pg_time->setObjectName(QString::fromUtf8("pg_time"));
        pg_time->setValue(100);

        horizontalLayout_2->addWidget(pg_time);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        le_word = new QLineEdit(tab_play);
        le_word->setObjectName(QString::fromUtf8("le_word"));
        le_word->setMinimumSize(QSize(200, 0));
        le_word->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_3->addWidget(le_word);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btn_confirm = new QPushButton(tab_play);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));

        horizontalLayout_3->addWidget(btn_confirm);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        btn_start = new QPushButton(tab_play);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setMinimumSize(QSize(100, 20));

        horizontalLayout_5->addWidget(btn_start);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        btn_restart = new QPushButton(tab_play);
        btn_restart->setObjectName(QString::fromUtf8("btn_restart"));
        btn_restart->setMinimumSize(QSize(100, 20));

        horizontalLayout_5->addWidget(btn_restart);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        btn_exit = new QPushButton(tab_play);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setMinimumSize(QSize(100, 20));

        horizontalLayout_5->addWidget(btn_exit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 2);
        horizontalLayout_5->setStretch(2, 1);
        horizontalLayout_5->setStretch(3, 2);
        horizontalLayout_5->setStretch(4, 4);
        horizontalLayout_5->setStretch(5, 2);
        horizontalLayout_5->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 2);
        verticalLayout->setStretch(6, 2);
        verticalLayout->setStretch(7, 2);
        verticalLayout->setStretch(8, 2);
        verticalLayout->setStretch(9, 2);
        verticalLayout->setStretch(10, 2);

        horizontalLayout_10->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_10);


        horizontalLayout_8->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_play, QString());
        tab_search = new QWidget();
        tab_search->setObjectName(QString::fromUtf8("tab_search"));
        horizontalLayout_13 = new QHBoxLayout(tab_search);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_17);

        rbtn2_player = new QRadioButton(tab_search);
        rbtn2_player->setObjectName(QString::fromUtf8("rbtn2_player"));

        horizontalLayout_11->addWidget(rbtn2_player);

        rbtn2_testbuilder = new QRadioButton(tab_search);
        rbtn2_testbuilder->setObjectName(QString::fromUtf8("rbtn2_testbuilder"));

        horizontalLayout_11->addWidget(rbtn2_testbuilder);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_18);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 2);
        horizontalLayout_11->setStretch(2, 2);
        horizontalLayout_11->setStretch(3, 5);

        verticalLayout_5->addLayout(horizontalLayout_11);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_16);

        le2_search = new QLineEdit(tab_search);
        le2_search->setObjectName(QString::fromUtf8("le2_search"));

        horizontalLayout_12->addWidget(le2_search);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);

        btn2_search = new QPushButton(tab_search);
        btn2_search->setObjectName(QString::fromUtf8("btn2_search"));

        horizontalLayout_12->addWidget(btn2_search);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_19);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 6);
        horizontalLayout_12->setStretch(2, 2);
        horizontalLayout_12->setStretch(3, 1);
        horizontalLayout_12->setStretch(4, 3);

        verticalLayout_5->addLayout(horizontalLayout_12);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_7);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(1, 2);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 2);
        verticalLayout_5->setStretch(4, 5);

        horizontalLayout_13->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_search, QString());
        tab_list = new QWidget();
        tab_list->setObjectName(QString::fromUtf8("tab_list"));
        horizontalLayout_15 = new QHBoxLayout(tab_list);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        rbtn3_player = new QRadioButton(tab_list);
        rbtn3_player->setObjectName(QString::fromUtf8("rbtn3_player"));

        horizontalLayout_14->addWidget(rbtn3_player);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_20);

        rbtn3_testbuilder = new QRadioButton(tab_list);
        rbtn3_testbuilder->setObjectName(QString::fromUtf8("rbtn3_testbuilder"));

        horizontalLayout_14->addWidget(rbtn3_testbuilder);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_22);

        cb3_type = new QComboBox(tab_list);
        cb3_type->addItem(QString());
        cb3_type->addItem(QString());
        cb3_type->setObjectName(QString::fromUtf8("cb3_type"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cb3_type->sizePolicy().hasHeightForWidth());
        cb3_type->setSizePolicy(sizePolicy1);
        cb3_type->setMinimumSize(QSize(0, 20));

        horizontalLayout_14->addWidget(cb3_type);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_21);

        btn3_update = new QPushButton(tab_list);
        btn3_update->setObjectName(QString::fromUtf8("btn3_update"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn3_update->sizePolicy().hasHeightForWidth());
        btn3_update->setSizePolicy(sizePolicy2);
        btn3_update->setMinimumSize(QSize(0, 20));

        horizontalLayout_14->addWidget(btn3_update);

        horizontalLayout_14->setStretch(0, 2);
        horizontalLayout_14->setStretch(1, 1);
        horizontalLayout_14->setStretch(2, 2);
        horizontalLayout_14->setStretch(3, 4);
        horizontalLayout_14->setStretch(4, 2);
        horizontalLayout_14->setStretch(5, 1);
        horizontalLayout_14->setStretch(6, 2);

        verticalLayout_4->addLayout(horizontalLayout_14);

        tableView = new QTableView(tab_list);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_4->addWidget(tableView);


        horizontalLayout_15->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_list, QString());
        tab_my = new QWidget();
        tab_my->setObjectName(QString::fromUtf8("tab_my"));
        verticalLayout_6 = new QVBoxLayout(tab_my);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lab4_accountName = new QLabel(tab_my);
        lab4_accountName->setObjectName(QString::fromUtf8("lab4_accountName"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Copperplate Gothic Light"));
        font2.setPointSize(20);
        lab4_accountName->setFont(font2);

        verticalLayout_7->addWidget(lab4_accountName);

        lab4_name = new QLabel(tab_my);
        lab4_name->setObjectName(QString::fromUtf8("lab4_name"));
        lab4_name->setFont(font2);

        verticalLayout_7->addWidget(lab4_name);

        lab4_lv = new QLabel(tab_my);
        lab4_lv->setObjectName(QString::fromUtf8("lab4_lv"));
        lab4_lv->setFont(font2);

        verticalLayout_7->addWidget(lab4_lv);

        lab4_ckpoint = new QLabel(tab_my);
        lab4_ckpoint->setObjectName(QString::fromUtf8("lab4_ckpoint"));
        lab4_ckpoint->setFont(font2);

        verticalLayout_7->addWidget(lab4_ckpoint);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        lab4_ex = new QLabel(tab_my);
        lab4_ex->setObjectName(QString::fromUtf8("lab4_ex"));
        lab4_ex->setFont(font2);

        horizontalLayout_16->addWidget(lab4_ex);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_23);

        pg4_ex = new QProgressBar(tab_my);
        pg4_ex->setObjectName(QString::fromUtf8("pg4_ex"));
        pg4_ex->setValue(0);

        horizontalLayout_16->addWidget(pg4_ex);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_24);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 1);
        horizontalLayout_16->setStretch(2, 6);
        horizontalLayout_16->setStretch(3, 2);

        verticalLayout_8->addLayout(horizontalLayout_16);

        verticalLayout_8->setStretch(0, 6);
        verticalLayout_8->setStretch(1, 1);

        verticalLayout_6->addLayout(verticalLayout_8);

        tabWidget->addTab(tab_my, QString());

        horizontalLayout_17->addWidget(tabWidget);


        retranslateUi(playerwindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(playerwindow);
    } // setupUi

    void retranslateUi(QDialog *playerwindow)
    {
        playerwindow->setWindowTitle(QApplication::translate("playerwindow", "Dialog", nullptr));
        cb_pattern->setItemText(0, QApplication::translate("playerwindow", "\346\231\256\351\200\232\346\250\241\345\274\217", nullptr));
        cb_pattern->setItemText(1, QApplication::translate("playerwindow", "\350\207\252\345\256\232\344\271\211\346\250\241\345\274\217", nullptr));
        cb_pattern->setItemText(2, QApplication::translate("playerwindow", "\346\227\240\345\260\275\346\250\241\345\274\217", nullptr));

        cb_difficulty->setItemText(0, QApplication::translate("playerwindow", "\351\232\276\345\272\2461", nullptr));
        cb_difficulty->setItemText(1, QApplication::translate("playerwindow", "\351\232\276\345\272\2462", nullptr));
        cb_difficulty->setItemText(2, QApplication::translate("playerwindow", "\351\232\276\345\272\2463", nullptr));
        cb_difficulty->setItemText(3, QApplication::translate("playerwindow", "\351\232\276\345\272\2464", nullptr));
        cb_difficulty->setItemText(4, QApplication::translate("playerwindow", "\351\232\276\345\272\2465", nullptr));
        cb_difficulty->setItemText(5, QApplication::translate("playerwindow", "\351\232\276\345\272\2466", nullptr));

        btn_multiplayer->setText(QApplication::translate("playerwindow", "\345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        lab_checkpoint->setText(QApplication::translate("playerwindow", "\345\205\263\345\215\241:", nullptr));
        lab_name->setText(QString());
        lab_level->setText(QString());
        lab_word->setHtml(QApplication::translate("playerwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        lab_display->setText(QString());
        btn_confirm->setText(QApplication::translate("playerwindow", "\347\241\256\345\256\232", nullptr));
        btn_start->setText(QApplication::translate("playerwindow", "\345\274\200\345\247\213", nullptr));
        btn_restart->setText(QApplication::translate("playerwindow", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        btn_exit->setText(QApplication::translate("playerwindow", "\351\200\200\345\207\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_play), QApplication::translate("playerwindow", "play", nullptr));
        rbtn2_player->setText(QApplication::translate("playerwindow", "\351\227\257\345\205\263\350\200\205", nullptr));
        rbtn2_testbuilder->setText(QApplication::translate("playerwindow", "\345\207\272\351\242\230\350\200\205", nullptr));
        btn2_search->setText(QApplication::translate("playerwindow", "\346\237\245\350\257\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_search), QApplication::translate("playerwindow", "\346\237\245\350\257\242", nullptr));
        rbtn3_player->setText(QApplication::translate("playerwindow", "\351\227\257\345\205\263\350\200\205", nullptr));
        rbtn3_testbuilder->setText(QApplication::translate("playerwindow", "\345\207\272\351\242\230\350\200\205", nullptr));
        cb3_type->setItemText(0, QApplication::translate("playerwindow", "\347\255\211\347\272\247", nullptr));
        cb3_type->setItemText(1, QApplication::translate("playerwindow", "\351\227\257\345\205\263\346\225\260", nullptr));

        btn3_update->setText(QApplication::translate("playerwindow", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_list), QApplication::translate("playerwindow", "\346\216\222\350\241\214\346\246\234", nullptr));
        lab4_accountName->setText(QApplication::translate("playerwindow", "\350\264\246\346\210\267\345\220\215:", nullptr));
        lab4_name->setText(QApplication::translate("playerwindow", "\346\270\270\346\210\217\345\220\215:", nullptr));
        lab4_lv->setText(QApplication::translate("playerwindow", "\347\255\211\347\272\247:", nullptr));
        lab4_ckpoint->setText(QApplication::translate("playerwindow", "\351\227\257\345\205\263\346\225\260:", nullptr));
        lab4_ex->setText(QApplication::translate("playerwindow", "\347\273\217\351\252\214:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_my), QApplication::translate("playerwindow", "\346\210\221\347\232\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playerwindow: public Ui_playerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERWINDOW_H
