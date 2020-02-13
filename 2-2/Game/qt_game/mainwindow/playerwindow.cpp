#include "playerwindow.h"
#include "ui_playerwindow.h"
#include "User.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <qmessagebox.h>
#include <qbuttongroup.h>
#include <qstandarditemmodel.h>
#include "multiplaywindow.h"

static Player P;
static int line, ex_temp, Count = 1;
static char word[maxNum];
//SOCKET Client;

playerwindow::playerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playerwindow)
{
	temp = 100;
	qtimer = new QTimer(this);
    ui->setupUi(this); 
	
	this->ui->tabWidget->setCurrentIndex(0);
	connect(this->ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
	//��Ϸ����
	connect(this->ui->btn_exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
	connect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));
	connect(qtimer, SIGNAL(timeout()), this, SLOT(play()));
	connect(this, SIGNAL(sendsignal()), this, SLOT(start()));
	connect(this->ui->cb_pattern, SIGNAL(currentIndexChanged(int)), this, SLOT(changePattern(int)));
	connect(this->ui->cb_difficulty, SIGNAL(currentIndexChanged(int)), this, SLOT(changePattern(int)));
	this->ui->cb_difficulty->setVisible(false);
	this->ui->le_word->setEnabled(false);
	connect(this->ui->btn_multiplayer, SIGNAL(clicked(bool)), this, SLOT(multiplay()));
	//��ѯ����
	BG2 = new QButtonGroup(this);
	connect(this->ui->btn2_search, SIGNAL(clicked(bool)), this, SLOT(search()));
	BG2->setExclusive(true);
	BG2->addButton(this->ui->rbtn2_player, 0);
	BG2->addButton(this->ui->rbtn2_testbuilder, 1);
	this->ui->rbtn2_player->setChecked(true);
	//���а�
	BG3 = new QButtonGroup(this);
	BG3->setExclusive(true);
	BG3->addButton(this->ui->rbtn3_player, 0);
	BG3->addButton(this->ui->rbtn3_testbuilder, 1);
	this->ui->rbtn3_player->setChecked(true);
	connect(this->ui->btn3_update, SIGNAL(clicked(bool)), this, SLOT(update()));
	connect(BG3, SIGNAL(buttonClicked(int)), this, SLOT(rbtnChanged(int)));
	//connect(BG3, SIGNAL(buttonClicked(this->ui->rbtn3_testbuilder)), this, SLOT(rbntChanged(int)));
}

playerwindow::~playerwindow()
{
    delete ui;
}

void playerwindow::exit() {
	this->close();
}

void playerwindow::receiveData(QString name) {
	char *accountName;
	//char fileName[maxNum] = "C:\\Users\\light\\Desktop\\Player.csv";
	QByteArray b1 = name.toLatin1();
	accountName = b1.data();
	line = P.getContentInFile(playerFile, accountName);
																		//��ʾ�����Ϣ
	QString playername, lv;
	playername = QString(QLatin1String(P.playerName));
	lv = QString::number(P.level);
	this->ui->lab_name->setText(playername);							//��ʾ����
	this->ui->lab_level->setText(lv);
	int Ex = Ex(P.level);
	this->ui->pg_ex->setRange(0, Ex);							//��ʾ������
	this->ui->pg_ex->setValue(P.experience);
	
}

char *playerwindow::getword(char *fileName) {
	srand((unsigned)time(NULL));
	ifstream file;
	char le[1024] = { '\0' };
	char n[1024] = { '\0' };
	char *word = NULL;
	file.open(fileName);
	if (file.is_open()) {
		file.getline(n, sizeof(n));
		int num;
		istringstream istr;
		istr.str(n);
		istr >> num;
		int rd = rand() % num + 1, i = 0;
		while (file.getline(le, maxNum) && i <= rd) {
			i++;
		}
		strtok(le, ",");
		word = strtok(NULL, ",");
	}
	return word;
}

void playerwindow::play() {			//qtimer�ź�ѭ������
	--temp;
	this->ui->pg_time->setValue(temp);
	if (temp == 0) {				//һ��ʱ��������
		qtimer->stop();
		temp = 100;
		this->ui->lab_word->setText("");
		this->ui->le_word->setEnabled(true);			//�������
		this->ui->le_word->setFocus();					//�۽��������
		connect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));			//����ȷ�ϰ�ť
	}
}

void playerwindow::start() {
	switch (this->ui->cb_pattern->currentIndex()) {
	case 0:
		start_1();
		break;
	case 1:
		start_2();
		break;
	case 2:
		start_3();
		break;
	default:
		break;
	}
}

void playerwindow::check() {
	QString str = this->ui->le_word->text();
	if (str.isEmpty()) {				//������뵥��Ϊ�գ�����ʾ���뵥��
		this->ui->lab_display->setText(u8"�����뵥��");
		return;
	}
	this->ui->le_word->clear();
	char *input;
	QByteArray b = str.toLatin1();
	input = b.data();
	if (!strcmp(input, word)) {					//ÿͨ��һ�ؼӾ���
		this->ui->lab_display->setText(u8"��ȷ");
		P.checkPoint += 1;
		ex_temp = (int)ex(P.level);
		P.experience += ex_temp;
		if (Count % 20 == 0)					//ÿ20�ػ��ö��⾭��
			P.experience += 10 * ex_temp;
		int E = (int)Ex(P.level);
		if (P.experience >= E) {
			P.experience -= E;
			P.level += 1;
			QString lv;
			lv = QString::number(P.level);
			this->ui->lab_level->setText("lv:" + lv);
			this->ui->pg_ex->setRange(0, Ex(P.level));
		}
		this->ui->pg_ex->setValue(P.experience);
		//char fileName[maxNum] = "C:\\Users\\light\\Desktop\\Player.csv";
		P.modifyContentInFile(playerFile,line);
		//qtimer2->start(30);
	}
	else {
		this->ui->lab_display->setText(u8"����");
		connect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));
		disconnect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));
		Count = 1;
		return;
	}
	if (Count == 20 && this->ui->cb_pattern->currentIndex() != 2) {					//ͨ��20�������һ����ͨģʽ
		connect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));
		disconnect(this->ui->btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart()));
		disconnect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));
		this->ui->le_word->setEnabled(false);
		this->ui->pg_time->setValue(100);
		this->ui->lab_display->setText(u8"��ϲ���");
		Count = 0;
	}
	else {
		Count += 1;
		emit sendsignal();
	}
}

void playerwindow::restart() {
	Count = 1;
	if (qtimer->isActive()) {
		qtimer->stop();
		temp = 100;
	}
	emit sendsignal();
}


void playerwindow::start_1() {			//��ͨģʽ
	if (!qtimer->isActive()) {
		this->ui->lcdNumber->display((double)Count);
		//char fileName[maxNum];
		if (Count == 1) {
			connect(this->ui->btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart()));
			char fileName[maxNum] = "D:\\learn\\C++\\words1.csv";
			disconnect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));		//start��ťʧȥ����
			strcpy(word, getword(fileName));					//����ӵ��ʿ���ȡ��һ������
		}
		else if (Count >= 2 && Count <= 3) {
			char fileName[maxNum] = "D:\\learn\\C++\\words2.csv";
			strcpy(word, getword(fileName));
		}
		else if (Count >= 4 && Count <= 6) {
			char fileName[maxNum] = "D:\\learn\\C++\\words3.csv";
			strcpy(word, getword(fileName));
		}
		else if (Count >= 7 && Count <= 10) {
			char fileName[maxNum] = "D:\\learn\\C++\\words4.csv";
			strcpy(word, getword(fileName));
		}
		else if (Count >= 11 && Count <= 15) {
			char fileName[maxNum] = "D:\\learn\\C++\\words5.csv";
			strcpy(word, getword(fileName));
		}
		else if (Count >= 16 && Count <= 21) {
			char fileName[maxNum] = "D:\\learn\\C++\\words6.csv";
			strcpy(word, getword(fileName));
		}
		QString str;
		str = QString(QLatin1String(word));
		this->ui->lab_word->setText(str);
		qtimer->start(45);					//������ʾʱ���qtimer���
		this->ui->le_word->setEnabled(false);
		disconnect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));
	}
}

void playerwindow::start_2() {					//�Զ���ģʽ
	if (!qtimer->isActive()) {
		this->ui->lcdNumber->display((double)Count);
		connect(this->ui->btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart()));
		disconnect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));
		switch(this->ui->cb_difficulty->currentIndex()) {
		case 0: 
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words1.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 1:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words2.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 2:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words3.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 3:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words4.csv";
			strcpy(word, getword(fileName));
		}
		case 4:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words5.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 5:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words6.csv";
			strcpy(word, getword(fileName));
			break;
		}
		default:
			break;
		}
		QString str;
		str = QString(QLatin1String(word));
		this->ui->lab_word->setText(str);
		qtimer->start(45-(Count-1)/5*10);					//������ʾʱ���qtimer���
		this->ui->le_word->setEnabled(false);
		disconnect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));
	}
}

void playerwindow::start_3() {				//�޾�ģʽ
	if (!qtimer->isActive()) {
		this->ui->lcdNumber->display((double)Count);
		connect(this->ui->btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart()));
		disconnect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));
		srand((unsigned)time(NULL));
		int dif = rand() % 6;
		switch (dif) {
		case 0:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words1.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 1:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words2.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 2:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words3.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 3:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words4.csv";
			strcpy(word, getword(fileName));
		}
		case 4:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words5.csv";
			strcpy(word, getword(fileName));
			break;
		}
		case 5:
		{
			char fileName[maxNum] = "D:\\learn\\C++\\words6.csv";
			strcpy(word, getword(fileName));
			break;
		}
		default:
			break;
		}
		QString str;
		str = QString(QLatin1String(word));
		this->ui->lab_word->setText(str);
		if (Count <= 20)
			qtimer->start(45 - (Count - 1) / 5 * 10);					//������ʾʱ���qtimer���
		else
			qtimer->start(15);
		this->ui->le_word->setEnabled(false);
		disconnect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));
	}
}

void playerwindow::changePattern(int index) {
	if (sender() == this->ui->cb_pattern) {
		if (index == 1)												//�Ѷ�ѡ��ؼ�����ģʽ��ʾ
			this->ui->cb_difficulty->setVisible(true);
		else
			this->ui->cb_difficulty->setVisible(false);
	}
	Count = 1;													//��ʼ��
	temp = 100;
	this->ui->pg_time->setValue(temp);
	this->ui->lcdNumber->display((double)Count);
	this->ui->lab_word->setText("");
	disconnect(this->ui->btn_confirm, SIGNAL(clicked(bool)), this, SLOT(check()));
	disconnect(this->ui->btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart()));
	connect(this->ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start()));
	if (qtimer->isActive())
		qtimer->stop();
}

void playerwindow::tabChanged(int tab) {
	if (tab == 1) {
		this->ui->le2_search->setFocus();
	}
	else if (tab == 3)
		displayMy();
}

void playerwindow::search() {
	QString content = this->ui->le2_search->text();
	char *name;
	QByteArray b = content.toLatin1();
	name = b.data();
	//QApplication::setQuitOnLastWindowClosed(false);			//�رմ���ʱ�����˳�����
	switch (BG2->checkedId()) {
	case 0:
	{
		Player search_p;
		int n = search_p.getContentInFile(playerFile, name);
		if (n != -1) {
			QString content = "Name:    " + QString(QLatin1String(search_p.playerName)) + '\n';
			content = content + "lv:         " + QString::number(search_p.level) + '\n';
			content = content + u8"ͨ����:    " + QString::number(search_p.checkPoint) + '\n';
			QMessageBox::information(this, "player", content, QMessageBox::Ok);
		}
		else {
			QString content = u8"�û�������";
			QMessageBox::warning(this, "player", content, QMessageBox::Ok);
		}
		break;
	}
	case 1:
	{
		TestBuilder search_t;
		int n = search_t.getContentInFile(testBuilderFile, name);
		if (n != -1) {
			QString content = "Name:    " + QString(QLatin1String(search_t.builderName)) + '\n';
			content = content + "lv:         " + QString::number(search_t.level) + '\n';
			content = content + u8"������:    " + QString::number(search_t.wordCount) + '\n';
			QMessageBox::information(this, "player", content, QMessageBox::Ok);
		}
		else {
			QString content = u8"�û�������";
			QMessageBox::warning(this, "player", content, QMessageBox::Ok);
		}
		break;
	}
	default:
		break;
	}
}

void playerwindow::update() {
	QStandardItemModel *model = new QStandardItemModel(this);
	model->setColumnCount(4);
	model->setHeaderData(0, Qt::Horizontal, u8"�˻���");
	model->setHeaderData(1, Qt::Horizontal, u8"��Ϸ��");
	model->setHeaderData(2, Qt::Horizontal, u8"�ȼ�");
	int i = 0;
	if (BG3->checkedId() == 0) {			//ѡ�д�����
		model->setHeaderData(3, Qt::Horizontal, u8"ͨ����");
		this->ui->tableView->setModel(model);
		this->ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

		Player *tmp_P;
		tmp_P = new Player[10];
		ifstream file;
		char line[1024] = { '\0' };
		file.open(playerFile);
		if (file.is_open()) {
			while (file.getline(line, sizeof(line))) {
				Player temp;
				strcpy(temp.accountName, strtok(line, ","));
				strcpy(temp.playerName, strtok(NULL, ","));
				temp.checkPoint = atoi(strtok(NULL, ","));
				temp.experience = atoi(strtok(NULL, ","));
				temp.level = atoi(strtok(NULL, ","));
				if (i == 0)
					tmp_P[0] = temp;
				else {									//ѡ������
					int j = 0;
					if (this->ui->cb3_type->currentIndex() == 0) {
						while (j <= i - 1) {
							if (temp.level > tmp_P[j].level)
								break;
							j++;
						}
					}
					else {
						while (j <= i - 1) {
							if (temp.checkPoint > tmp_P[j].checkPoint)
								break;
							j++;
						}
					}
					int k;
					k = i < 10 ? i : i - 1;
					while (k > j) {
						tmp_P[k] = tmp_P[k - 1];
						k--;
					}
					tmp_P[j] = temp;
				}
				i = i < 10 ? i + 1 : 10;
			}
			file.close();
		}
		else
			cout << "error!" << endl;

		for (int j = 0; j < i; ++j) {
			model->setItem(j, 0, new QStandardItem(QString(QLatin1String(tmp_P[j].accountName))));
			model->setItem(j, 1, new QStandardItem(QString(QLatin1String(tmp_P[j].playerName))));
			model->setItem(j, 2, new QStandardItem(QString::number(tmp_P[j].level)));
			model->setItem(j, 3, new QStandardItem(QString::number(tmp_P[j].checkPoint)));
		}
	}
	else {									//ѡ�г�����
		model->setHeaderData(3, Qt::Horizontal, u8"������");
		this->ui->tableView->setModel(model);
		this->ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

		TestBuilder *tmp_T;
		tmp_T = new TestBuilder[10];
		int i = 0;
		ifstream file;
		char line[1024] = { '\0' };
		file.open(testBuilderFile);
		if (file.is_open()) {
			while (file.getline(line, sizeof(line))) {
				TestBuilder temp;
				strcpy(temp.accountName, strtok(line, ","));
				strcpy(temp.builderName, strtok(NULL, ","));
				temp.wordCount = atoi(strtok(NULL, ","));
				temp.level = atoi(strtok(NULL, ","));
				if (i == 0)
					tmp_T[0] = temp;
				else {									//ѡ������
					int j = 0;
					if (this->ui->cb3_type->currentIndex() == 0) {
						while (j <= i - 1) {
							if (temp.level > tmp_T[j].level)
								break;
							j++;
						}
					}
					else {
						while (j <= i - 1) {
							if (temp.wordCount > tmp_T[j].wordCount)
								break;
							j++;
						}
					}
					int k;
					k = i < 10 ? i : i - 1;
					while (k > j) {
						tmp_T[k] = tmp_T[k - 1];
						k--;
					}
					tmp_T[j] = temp;
				}
				i = i < 10 ? i + 1 : 10;
			}
			file.close();
		}
		else
			cout << "error!" << endl;

		for (int j = 0; j < i; ++j) {
			model->setItem(j, 0, new QStandardItem(QString(QLatin1String(tmp_T[j].accountName))));
			model->setItem(j, 1, new QStandardItem(QString(QLatin1String(tmp_T[j].builderName))));
			model->setItem(j, 2, new QStandardItem(QString::number(tmp_T[j].level)));
			model->setItem(j, 3, new QStandardItem(QString::number(tmp_T[j].wordCount)));
		}
	}
}

void playerwindow::rbtnChanged(int index) {
	if (index == 0) {						//ѡ�д�����
		this->ui->cb3_type->setItemText(1, u8"������");
	}
	else {									//ѡ�г�����
		this->ui->cb3_type->setItemText(1, u8"������");
	}
}

void playerwindow::displayMy() {
	Player my;
	my.getContentInFile(playerFile, P.accountName);
	QString accoutName, playerName, lv, ckpoint;
	accoutName = QString(QLatin1String(my.accountName));
	playerName = QString(QLatin1String(my.playerName));
	lv = QString::number(my.level);
	ckpoint = QString::number(my.checkPoint);

	this->ui->lab4_accountName->setText(u8"�˻���:       " + accoutName);
	this->ui->lab4_name->setText(u8"��Ϸ��:       " + playerName);
	this->ui->lab4_lv->setText(u8"�ȼ�:       " + lv);
	this->ui->lab4_ckpoint->setText(u8"������:       " + ckpoint);
	int Ex = Ex(my.level);
	this->ui->pg4_ex->setRange(0, Ex);							//��ʾ������
	this->ui->pg4_ex->setValue(my.experience);
}

void playerwindow::reshow() {
	this->show();
}

void playerwindow::multiplay() {
	this->hide();
	multiplaywindow *p = new multiplaywindow(this);
	connect(p, SIGNAL(sendsignal()), this, SLOT(reshow()));
	p->show();
}