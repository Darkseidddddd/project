#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include <qstring.h>
#include "User.h"
#include "playerwindow.h"
#include "testbuilderwindow.h"
static User U;
static int line;

newUserwindow::newUserwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUserwindow)
{
    ui->setupUi(this);
	connect(this->ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
	connect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(confirm()));
}

newUserwindow::~newUserwindow()
{
    delete ui;
}

void newUserwindow::exit() {
	this->close();
}

void newUserwindow::confirm() {
	QString playerName = this->ui->le_name->text();
	char *gaName;
	if (playerName.isEmpty()) {
		this->ui->lab_display->setText(u8"请输入游戏名");
	}
	else {
		QByteArray b1 = playerName.toLatin1();
		gaName = b1.data();
		if (U.Type == 1) {
			Player P;
			char fileName[maxNum] = "C:\\Users\\light\\Desktop\\Player.csv";
			if (P.getContentInFile(fileName, gaName) != -1) {
				this->ui->lab_display->setText(u8"名字已存在");
				return;
			}
			strcpy(P.playerName, gaName);
			strcpy(P.accountName, U.accountName);
			P.checkPoint = 0;
			P.experience = 0;
			P.level = 1;
			P.writeIntoFile(fileName);
			U.isNew = false;
			char file[maxNum] = "C:\\Users\\light\\Desktop\\User.csv";
			U.modifyContentInFile(file, line);
			//跳转至player窗口
			playerwindow *p4 = new playerwindow(this);
			connect(this, SIGNAL(sendData(QString)), p4, SLOT(receiveData(QString)));
			emit sendData(U.accountName);
			this->close();
			p4->show();
		}
		else if (U.Type == 2) {
			TestBuilder T;
			char fileName[maxNum] = "C:\\Users\\light\\Desktop\\TestBuilder.csv";
			if (T.getContentInFile(fileName, gaName) != -1) {
				this->ui->lab_display->setText(u8"名字已存在");
				return;
			}
			strcpy(T.builderName, gaName);
			strcpy(T.accountName, U.accountName);
			T.wordCount = 0;
			T.level = 1;
			T.writeIntoFile(fileName);
			U.isNew = false;
			char file[maxNum] = "C:\\Users\\light\\Desktop\\User.csv";
			U.modifyContentInFile(file, line);
			//跳转至TestBuilder窗口
			testBuilderwindow *p5 = new testBuilderwindow(this);
			connect(this, SIGNAL(sendData(QString)), p5, SLOT(receiveData(QString)));
			emit sendData(U.accountName);
			this->close();
			p5->show();
		}
	}
}

void newUserwindow::receiveData(QString name) {
	this->ui->lab_display->setText(name);
	char *accountName;
	char fileName[maxNum] = "C:\\Users\\light\\Desktop\\User.csv";
	QByteArray b1 = name.toLatin1();
	accountName = b1.data();
	line = U.getContentInFile(fileName, accountName);
}
