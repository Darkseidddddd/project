#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"

#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <stdlib.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:      //²Ûº¯ÊýÉêÃ÷
	void login();
	void cancel();
	void Register();
	void reshow();
signals:
	//void sendsignal();
	void sendData(QString);

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
