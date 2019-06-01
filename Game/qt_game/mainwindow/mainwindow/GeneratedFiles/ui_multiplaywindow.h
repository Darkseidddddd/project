/********************************************************************************
** Form generated from reading UI file 'multiplaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAYWINDOW_H
#define UI_MULTIPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiplaywindow
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *table;
    QWidget *tab_play;
    QVBoxLayout *play;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lab_checkpoint;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *lab_name;
    QLabel *lab_level;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QProgressBar *pg_ex;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_12;
    QTextBrowser *lab_word;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *verticalSpacer;
    QLabel *lab_display;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *pg_time;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *le_word;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_start;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_restart;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_exit;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_5;
    QWidget *tab_online;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *btn2_update;
    QTableView *tableView;

    void setupUi(QDialog *multiplaywindow)
    {
        if (multiplaywindow->objectName().isEmpty())
            multiplaywindow->setObjectName(QString::fromUtf8("multiplaywindow"));
        multiplaywindow->resize(700, 650);
        multiplaywindow->setMaximumSize(QSize(700, 650));
        multiplaywindow->setSizeIncrement(QSize(700, 650));
        horizontalLayout = new QHBoxLayout(multiplaywindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        table = new QTabWidget(multiplaywindow);
        table->setObjectName(QString::fromUtf8("table"));
        tab_play = new QWidget();
        tab_play->setObjectName(QString::fromUtf8("tab_play"));
        play = new QVBoxLayout(tab_play);
        play->setObjectName(QString::fromUtf8("play"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
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

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lab_name = new QLabel(tab_play);
        lab_name->setObjectName(QString::fromUtf8("lab_name"));

        horizontalLayout_2->addWidget(lab_name);

        lab_level = new QLabel(tab_play);
        lab_level->setObjectName(QString::fromUtf8("lab_level"));

        horizontalLayout_2->addWidget(lab_level);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        pg_ex = new QProgressBar(tab_play);
        pg_ex->setObjectName(QString::fromUtf8("pg_ex"));
        pg_ex->setValue(24);

        horizontalLayout_4->addWidget(pg_ex);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);

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

        horizontalLayout_5->addWidget(lab_word);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

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

        pg_time = new QProgressBar(tab_play);
        pg_time->setObjectName(QString::fromUtf8("pg_time"));
        pg_time->setValue(100);

        verticalLayout->addWidget(pg_time);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        le_word = new QLineEdit(tab_play);
        le_word->setObjectName(QString::fromUtf8("le_word"));
        le_word->setMinimumSize(QSize(200, 0));
        le_word->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_3->addWidget(le_word);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btn_confirm = new QPushButton(tab_play);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));

        horizontalLayout_3->addWidget(btn_confirm);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        btn_start = new QPushButton(tab_play);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setMinimumSize(QSize(100, 30));

        horizontalLayout_7->addWidget(btn_start);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        btn_restart = new QPushButton(tab_play);
        btn_restart->setObjectName(QString::fromUtf8("btn_restart"));
        btn_restart->setMinimumSize(QSize(100, 30));

        horizontalLayout_7->addWidget(btn_restart);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        btn_exit = new QPushButton(tab_play);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setMinimumSize(QSize(100, 30));

        horizontalLayout_7->addWidget(btn_exit);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 2);
        horizontalLayout_7->setStretch(2, 4);
        horizontalLayout_7->setStretch(3, 2);
        horizontalLayout_7->setStretch(4, 1);
        horizontalLayout_7->setStretch(5, 2);
        horizontalLayout_7->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 2);
        verticalLayout->setStretch(6, 2);
        verticalLayout->setStretch(7, 2);
        verticalLayout->setStretch(8, 2);
        verticalLayout->setStretch(9, 2);
        verticalLayout->setStretch(10, 2);
        verticalLayout->setStretch(11, 2);

        horizontalLayout_6->addLayout(verticalLayout);


        play->addLayout(horizontalLayout_6);

        table->addTab(tab_play, QString());
        tab_online = new QWidget();
        tab_online->setObjectName(QString::fromUtf8("tab_online"));
        verticalLayout_3 = new QVBoxLayout(tab_online);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_22);

        btn2_update = new QPushButton(tab_online);
        btn2_update->setObjectName(QString::fromUtf8("btn2_update"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn2_update->sizePolicy().hasHeightForWidth());
        btn2_update->setSizePolicy(sizePolicy);
        btn2_update->setMinimumSize(QSize(0, 20));

        horizontalLayout_14->addWidget(btn2_update);

        horizontalLayout_14->setStretch(0, 4);
        horizontalLayout_14->setStretch(1, 2);

        verticalLayout_4->addLayout(horizontalLayout_14);

        tableView = new QTableView(tab_online);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_4->addWidget(tableView);


        verticalLayout_3->addLayout(verticalLayout_4);

        table->addTab(tab_online, QString());

        horizontalLayout->addWidget(table);


        retranslateUi(multiplaywindow);

        table->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(multiplaywindow);
    } // setupUi

    void retranslateUi(QDialog *multiplaywindow)
    {
        multiplaywindow->setWindowTitle(QApplication::translate("multiplaywindow", "Dialog", nullptr));
        lab_checkpoint->setText(QApplication::translate("multiplaywindow", "\345\205\263\345\215\241:", nullptr));
        lab_name->setText(QString());
        lab_level->setText(QString());
        lab_word->setHtml(QApplication::translate("multiplaywindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:22pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        lab_display->setText(QString());
        btn_confirm->setText(QApplication::translate("multiplaywindow", "\347\241\256\345\256\232", nullptr));
        btn_start->setText(QApplication::translate("multiplaywindow", "\345\207\206\345\244\207", nullptr));
        btn_restart->setText(QApplication::translate("multiplaywindow", "\350\277\224\345\233\236", nullptr));
        btn_exit->setText(QApplication::translate("multiplaywindow", "\351\200\200\345\207\272", nullptr));
        table->setTabText(table->indexOf(tab_play), QApplication::translate("multiplaywindow", "play", nullptr));
        btn2_update->setText(QApplication::translate("multiplaywindow", "\345\210\267\346\226\260", nullptr));
        table->setTabText(table->indexOf(tab_online), QApplication::translate("multiplaywindow", "\345\275\223\345\211\215\345\234\250\347\272\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class multiplaywindow: public Ui_multiplaywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYWINDOW_H
