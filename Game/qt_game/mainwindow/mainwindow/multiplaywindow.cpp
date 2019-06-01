#include "multiplaywindow.h"
#include "ui_multiplaywindow.h"
#include <qstandarditemmodel.h>
#include "User.h"
#include <qdebug.h>
#include <iostream>
#include <fstream>
using namespace std;

static int I = 0;

multiplaywindow::multiplaywindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::multiplaywindow)
{
    ui->setupUi(this);
	//游戏界面
	connect(this->ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
	//查询在线界面
	connect(this->ui->btn2_update, SIGNAL(clicked(bool)), this, SLOT(update()));
}

multiplaywindow::~multiplaywindow()
{
    delete ui;
}

void multiplaywindow::exit() {
	this->close();
}

void multiplaywindow::update() {
	QStandardItemModel *model = new QStandardItemModel(this);
	model->setColumnCount(4);
	model->setHeaderData(0, Qt::Horizontal, u8"账户名");
	model->setHeaderData(1, Qt::Horizontal, u8"游戏名");
	model->setHeaderData(2, Qt::Horizontal, u8"等级");
	model->setHeaderData(3, Qt::Horizontal, u8"通关数");
	this->ui->tableView->setModel(model);
	this->ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	char sendBuf[2] = "2";
	send(Client, sendBuf, strlen(sendBuf) + 1, 0);
	char recvBuf[128];
	if (I == 0) {
		recv(Client, recvBuf, 128, 0);
		qDebug() << recvBuf[0] << endl;
		I = 1;
	}
	recv(Client, recvBuf, 128, 0);
	qDebug() << recvBuf[0] << endl;
	int n = recvBuf[0] - '0';
	if (n == 1) {
		Player tmp_P;
		char fileName[1024] = "C:\\Users\\light\\Desktop\\online.csv";
		if (fileName) {
			ifstream file;
			char line[1024] = { '\0' };
			file.open(fileName);
			if (file.is_open()) {
				int i = 0;
				while (file.getline(line, maxNum)) {
					qDebug() << line << endl;
					tmp_P.getContentInFile(playerFile, line);
					model->setItem(i, 0, new QStandardItem(QString(QLatin1String(tmp_P.accountName))));
					model->setItem(i, 1, new QStandardItem(QString(QLatin1String(tmp_P.playerName))));
					model->setItem(i, 2, new QStandardItem(QString::number(tmp_P.level)));
					model->setItem(i, 3, new QStandardItem(QString::number(tmp_P.checkPoint)));
					i++;
				}
				file.close();
			}
		}
	}
	/*
	char *account;
	strcpy(account, strtok(recvBuf, ","));
	while (account) {
		qDebug() << account << endl;
		strcpy(account, strtok(NULL, ","));
	}
	*/
}
