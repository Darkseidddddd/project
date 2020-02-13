/********************************************************************************
** Form generated from reading UI file 'Regwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOW_H
#define UI_REGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Regwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lab_reg;
    QHBoxLayout *horizontalLayout;
    QLabel *lab_account;
    QSpacerItem *horizontalSpacer;
    QLineEdit *le_accountReg;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_pw;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *le_pwReg;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_confirmpw;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *le_confirmpw;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *cb_type;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lab_display;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btn_confirmReg;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_return;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Regwindow)
    {
        if (Regwindow->objectName().isEmpty())
            Regwindow->setObjectName(QString::fromUtf8("Regwindow"));
        Regwindow->resize(550, 500);
        Regwindow->setMinimumSize(QSize(550, 500));
        Regwindow->setMaximumSize(QSize(550, 500));
        verticalLayout_2 = new QVBoxLayout(Regwindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lab_reg = new QLabel(Regwindow);
        lab_reg->setObjectName(QString::fromUtf8("lab_reg"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        lab_reg->setFont(font);
        lab_reg->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lab_reg);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lab_account = new QLabel(Regwindow);
        lab_account->setObjectName(QString::fromUtf8("lab_account"));
        lab_account->setFont(font);

        horizontalLayout->addWidget(lab_account);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        le_accountReg = new QLineEdit(Regwindow);
        le_accountReg->setObjectName(QString::fromUtf8("le_accountReg"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_accountReg->sizePolicy().hasHeightForWidth());
        le_accountReg->setSizePolicy(sizePolicy);
        le_accountReg->setClearButtonEnabled(true);

        horizontalLayout->addWidget(le_accountReg);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 9);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lab_pw = new QLabel(Regwindow);
        lab_pw->setObjectName(QString::fromUtf8("lab_pw"));
        lab_pw->setFont(font);

        horizontalLayout_2->addWidget(lab_pw);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        le_pwReg = new QLineEdit(Regwindow);
        le_pwReg->setObjectName(QString::fromUtf8("le_pwReg"));
        sizePolicy.setHeightForWidth(le_pwReg->sizePolicy().hasHeightForWidth());
        le_pwReg->setSizePolicy(sizePolicy);
        le_pwReg->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(le_pwReg);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 9);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lab_confirmpw = new QLabel(Regwindow);
        lab_confirmpw->setObjectName(QString::fromUtf8("lab_confirmpw"));
        lab_confirmpw->setFont(font);

        horizontalLayout_3->addWidget(lab_confirmpw);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        le_confirmpw = new QLineEdit(Regwindow);
        le_confirmpw->setObjectName(QString::fromUtf8("le_confirmpw"));
        sizePolicy.setHeightForWidth(le_confirmpw->sizePolicy().hasHeightForWidth());
        le_confirmpw->setSizePolicy(sizePolicy);
        le_confirmpw->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(le_confirmpw);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 9);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        cb_type = new QComboBox(Regwindow);
        cb_type->addItem(QString());
        cb_type->addItem(QString());
        cb_type->setObjectName(QString::fromUtf8("cb_type"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cb_type->sizePolicy().hasHeightForWidth());
        cb_type->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        cb_type->setFont(font1);

        horizontalLayout_5->addWidget(cb_type);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        lab_display = new QLabel(Regwindow);
        lab_display->setObjectName(QString::fromUtf8("lab_display"));
        lab_display->setFont(font);

        horizontalLayout_5->addWidget(lab_display);

        horizontalLayout_5->setStretch(0, 4);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 4);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(207, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        btn_confirmReg = new QPushButton(Regwindow);
        btn_confirmReg->setObjectName(QString::fromUtf8("btn_confirmReg"));

        horizontalLayout_4->addWidget(btn_confirmReg);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        btn_return = new QPushButton(Regwindow);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));

        horizontalLayout_4->addWidget(btn_return);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 3);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 1);
        verticalLayout->setStretch(6, 3);

        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(Regwindow);

        QMetaObject::connectSlotsByName(Regwindow);
    } // setupUi

    void retranslateUi(QDialog *Regwindow)
    {
        Regwindow->setWindowTitle(QApplication::translate("Regwindow", "Dialog", nullptr));
        lab_reg->setText(QApplication::translate("Regwindow", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        lab_account->setText(QApplication::translate("Regwindow", "\350\264\246\346\210\267\345\220\215:", nullptr));
        le_accountReg->setPlaceholderText(QApplication::translate("Regwindow", "\350\257\267\350\276\223\345\205\245\350\264\246\346\210\267\345\220\215", nullptr));
        lab_pw->setText(QApplication::translate("Regwindow", "\345\257\206\347\240\201:", nullptr));
        le_pwReg->setPlaceholderText(QApplication::translate("Regwindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        lab_confirmpw->setText(QApplication::translate("Regwindow", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        le_confirmpw->setPlaceholderText(QApplication::translate("Regwindow", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        cb_type->setItemText(0, QApplication::translate("Regwindow", "\351\227\257\345\205\263\350\200\205", nullptr));
        cb_type->setItemText(1, QApplication::translate("Regwindow", "\345\207\272\351\242\230\350\200\205", nullptr));

        lab_display->setText(QString());
        btn_confirmReg->setText(QApplication::translate("Regwindow", "\346\263\250\345\206\214", nullptr));
        btn_return->setText(QApplication::translate("Regwindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Regwindow: public Ui_Regwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
