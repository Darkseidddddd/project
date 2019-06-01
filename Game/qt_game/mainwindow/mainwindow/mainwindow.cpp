#include <string.h>
#include <fstream>
#include <sstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include "User.h"
#include "UsefulFunction.h"
#include "Regwindow.h"
#include "newuserwindow.h"
#include "playerwindow.h"
#include "testbuilderwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	// connect(˭��������ʲô�źţ�˭��ִ��ʲô����);
	connect(this->ui->btn_login, SIGNAL(clicked(bool)), this, SLOT(login()));
	connect(this->ui->btn_cancel, SIGNAL(clicked(bool)), this, SLOT(cancel()));
	connect(this->ui->btn_register, SIGNAL(clicked(bool)), this, SLOT(Register()));
	connect(this->ui->le_account, SIGNAL(returnPressed()), this, SLOT(login()));		//���»س���½
	connect(this->ui->le_password, SIGNAL(returnPressed()), this, SLOT(login()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

SOCKET new_client(char *account)
{
	//SOCKET Client;
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return Client; }

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return Client;
	}

	Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN Server;

	// Ҫ���ӵĻ�����Ϣ
	Server.sin_family = AF_INET;
	Server.sin_port = htons(8888);
	inet_pton(AF_INET, "127.0.0.1", &Server.sin_addr); //���ʮ���Ƶ�ַת���������ֽ���

	// �����˷�������
	int ret = connect(Client, (struct sockaddr*)&Server, sizeof(Server));

	if (ret == SOCKET_ERROR)
	{
		printf("����ʧ��\n");
		closesocket(Client);
		WSACleanup();
		return Client;
	}

	char recvBuf[128];
	char sendBuf[128];
	strcpy(sendBuf, account);
		return Client;
	//closesocket(Client);
	//WSACleanup();
	
}

void MainWindow::login()
{
	static int count = 0;
	count++;
	if (count > 3) {
		this->ui->display->setText(u8"��½ʧ��");
		disconnect(this->ui->btn_login, SIGNAL(clicked(bool)), this, SLOT(login()));
	}
	QString name = this->ui->le_account->text();            //��ȡ���������
	QString password = this->ui->le_password->text();
	if (name.isEmpty()) {
		this->ui->display->setText(u8"�˻�������Ϊ��");
	}
	else if (password.isEmpty()) {
		this->ui->display->setText(u8"���벻��Ϊ��");
	}
	else {
		User U;
		switch (U.Login(name, password)) {
		case 0:
			this->ui->display->setText(u8"�û�������");
			break;
		case 1: 
		{
			this->ui->display->setText(u8"��½�ɹ�");
			//new_client(U.accountName);
			if (U.isNew) {
				newUserwindow *p3 = new newUserwindow(this);
				connect(this, SIGNAL(sendData(QString)), p3, SLOT(receiveData(QString)));		//����½���˻��������¸�����
				emit sendData(U.accountName);
				this->close();
				p3->show();
			}
			else if (U.Type == 1) {
				playerwindow *p4 = new playerwindow(this);
				connect(this, SIGNAL(sendData(QString)), p4, SLOT(receiveData(QString)));
				emit sendData(U.accountName);
				this->close();
				p4->show();
			}
			else if (U.Type == 2) {
				testBuilderwindow *p5 = new testBuilderwindow(this);
				connect(this, SIGNAL(sendData(QString)), p5, SLOT(receiveData(QString)));
				emit sendData(U.accountName);
				this->close();
				p5->show();
			}
			break;
		}
		case 2:
			this->ui->display->setText(u8"�������");
			break;
		case 3:
			this->ui->display->setText(u8"�û��ѵ�¼");
			break;
		default:
			break;
		}
	}
}

void MainWindow::cancel() {
	this->close();
}

void MainWindow::reshow() {
	this->show();
}

void MainWindow::Register() {
	this->hide();
	Regwindow *regwindow = new Regwindow(this);
	connect(regwindow, SIGNAL(sendsignal()), this, SLOT(reshow()));
	regwindow->show();
}
