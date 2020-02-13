/********************************************************************************
** Form generated from reading UI file 'multiplay.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAY_H
#define UI_MULTIPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_multiplay
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *multiplay)
    {
        if (multiplay->objectName().isEmpty())
            multiplay->setObjectName(QString::fromUtf8("multiplay"));
        multiplay->resize(800, 600);
        menubar = new QMenuBar(multiplay);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        multiplay->setMenuBar(menubar);
        centralwidget = new QWidget(multiplay);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        multiplay->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(multiplay);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        multiplay->setStatusBar(statusbar);

        retranslateUi(multiplay);

        QMetaObject::connectSlotsByName(multiplay);
    } // setupUi

    void retranslateUi(QMainWindow *multiplay)
    {
        multiplay->setWindowTitle(QApplication::translate("multiplay", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class multiplay: public Ui_multiplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAY_H
