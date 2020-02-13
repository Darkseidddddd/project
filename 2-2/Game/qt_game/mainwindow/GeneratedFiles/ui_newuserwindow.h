/********************************************************************************
** Form generated from reading UI file 'newuserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERWINDOW_H
#define UI_NEWUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newUserwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lab_name;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *le_name;
    QLabel *lab_display;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_exit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *newUserwindow)
    {
        if (newUserwindow->objectName().isEmpty())
            newUserwindow->setObjectName(QString::fromUtf8("newUserwindow"));
        newUserwindow->resize(550, 500);
        newUserwindow->setMinimumSize(QSize(550, 500));
        newUserwindow->setMaximumSize(QSize(550, 500));
        verticalLayout_2 = new QVBoxLayout(newUserwindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lab_name = new QLabel(newUserwindow);
        lab_name->setObjectName(QString::fromUtf8("lab_name"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        lab_name->setFont(font);

        horizontalLayout->addWidget(lab_name);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        le_name = new QLineEdit(newUserwindow);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        le_name->setClearButtonEnabled(true);

        horizontalLayout->addWidget(le_name);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 8);

        verticalLayout->addLayout(horizontalLayout);

        lab_display = new QLabel(newUserwindow);
        lab_display->setObjectName(QString::fromUtf8("lab_display"));

        verticalLayout->addWidget(lab_display);

        verticalSpacer = new QSpacerItem(247, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_confirm = new QPushButton(newUserwindow);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setFont(font);

        horizontalLayout_2->addWidget(btn_confirm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_exit = new QPushButton(newUserwindow);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setFont(font);

        horizontalLayout_2->addWidget(btn_exit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);
        verticalLayout->setStretch(4, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(newUserwindow);

        QMetaObject::connectSlotsByName(newUserwindow);
    } // setupUi

    void retranslateUi(QDialog *newUserwindow)
    {
        newUserwindow->setWindowTitle(QApplication::translate("newUserwindow", "Dialog", nullptr));
        lab_name->setText(QApplication::translate("newUserwindow", "\346\270\270\346\210\217\345\220\215:", nullptr));
        le_name->setPlaceholderText(QApplication::translate("newUserwindow", "\350\257\267\350\276\223\345\205\245\346\270\270\346\210\217\345\220\215", nullptr));
        lab_display->setText(QString());
        btn_confirm->setText(QApplication::translate("newUserwindow", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QApplication::translate("newUserwindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newUserwindow: public Ui_newUserwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERWINDOW_H
