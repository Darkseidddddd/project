/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lab_Game;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lab_account;
    QLineEdit *le_account;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lab_password;
    QLineEdit *le_password;
    QSpacerItem *horizontalSpacer_3;
    QLabel *display;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_login;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_cancel;
    QSpacerItem *horizontalSpacer_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(550, 500);
        MainWindow->setMinimumSize(QSize(550, 500));
        MainWindow->setMaximumSize(QSize(550, 500));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(500, 400));
        centralWidget->setMaximumSize(QSize(500, 400));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lab_Game = new QLabel(centralWidget);
        lab_Game->setObjectName(QString::fromUtf8("lab_Game"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        lab_Game->setFont(font);
        lab_Game->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lab_Game);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lab_account = new QLabel(centralWidget);
        lab_account->setObjectName(QString::fromUtf8("lab_account"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        lab_account->setFont(font1);

        horizontalLayout->addWidget(lab_account);

        le_account = new QLineEdit(centralWidget);
        le_account->setObjectName(QString::fromUtf8("le_account"));
        le_account->setEchoMode(QLineEdit::Normal);
        le_account->setClearButtonEnabled(true);

        horizontalLayout->addWidget(le_account);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 8);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lab_password = new QLabel(centralWidget);
        lab_password->setObjectName(QString::fromUtf8("lab_password"));
        lab_password->setFont(font1);

        horizontalLayout_2->addWidget(lab_password);

        le_password = new QLineEdit(centralWidget);
        le_password->setObjectName(QString::fromUtf8("le_password"));
        le_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(le_password);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 8);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        display = new QLabel(centralWidget);
        display->setObjectName(QString::fromUtf8("display"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        display->setFont(font2);
        display->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(display);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_register = new QPushButton(centralWidget);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));

        horizontalLayout_4->addWidget(btn_register);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        btn_login = new QPushButton(centralWidget);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(btn_login);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        btn_cancel = new QPushButton(centralWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        sizePolicy.setHeightForWidth(btn_cancel->sizePolicy().hasHeightForWidth());
        btn_cancel->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(btn_cancel);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);
        horizontalLayout_4->setStretch(2, 3);
        horizontalLayout_4->setStretch(3, 3);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 3);
        horizontalLayout_4->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lab_Game->setText(QApplication::translate("MainWindow", "Game", nullptr));
        lab_account->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267\357\274\232", nullptr));
        le_account->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lab_password->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        le_password->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        display->setText(QString());
        btn_register->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        btn_login->setText(QApplication::translate("MainWindow", "\347\231\273\351\231\206", nullptr));
        btn_cancel->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
