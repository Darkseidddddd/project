#include "testbuilderwindow.h"
#include "ui_testbuilderwindow.h"
#include "User.h"
#include <fstream>
#include <sstream>
#include <UsefulFunction.h>
#include <qmessagebox.h>
#include <qbuttongroup.h>
#include <qstandarditemmodel.h>

static TestBuilder T;
static int line;
testBuilderwindow::testBuilderwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testBuilderwindow)
{
    ui->setupUi(this);
	this->ui->le1_word->setFocus();
	this->ui->tabWidget->setCurrentIndex(0);
	connect(this->ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
	//出题界面
	connect(this->ui->btn1_exit, SIGNAL(clicked(bool)), this, SLOT(exit()));
	connect(this->ui->btn1_detect, SIGNAL(clicked(bool)), this, SLOT(detect()));
	connect(this->ui->btn1_confirm, SIGNAL(clicked(bool)), this, SLOT(confirm()));
	//查询界面
	BG2 = new QButtonGroup(this);
	connect(this->ui->btn2_search, SIGNAL(clicked(bool)), this, SLOT(search()));
	BG2->setExclusive(true);
	BG2->addButton(this->ui->rbtn2_player, 0);
	BG2->addButton(this->ui->rbtn2_testbuilder, 1);
	this->ui->rbtn2_player->setChecked(true);
	//排行榜
	BG3 = new QButtonGroup(this);
	BG3->setExclusive(true);
	BG3->addButton(this->ui->rbtn3_player, 0);
	BG3->addButton(this->ui->rbtn3_testbuilder, 1);
	this->ui->rbtn3_player->setChecked(true);
	connect(this->ui->btn3_update, SIGNAL(clicked(bool)), this, SLOT(update()));
	connect(BG3, SIGNAL(buttonClicked(int)), this, SLOT(rbtnChanged(int)));
}

testBuilderwindow::~testBuilderwindow()
{
    delete ui;
}

void testBuilderwindow::exit() {
	this->close();
}

void testBuilderwindow::receiveData(QString name) {
	char *accountName;
	//char fileName[maxNum] = "C:\\Users\\light\\Desktop\\TestBuilder.csv";
	QByteArray b1 = name.toLatin1();
	accountName = b1.data();
	line = T.getContentInFile(testBuilderFile, accountName);

	QString lv, wordCount;
	lv = QString::number(T.level);
	this->ui->lab1_lv->setText("LV: " + lv);
	wordCount = QString::number(T.wordCount);
	this->ui->lab1_wordNum->setText(u8"出题数: " + wordCount);
}

void testBuilderwindow::writeToFile(QString word, char *fileName, int n) {
	string str;
	char num[maxNum];
	_itoa_s(n+1, num, maxNum, 10);
	str = str + charToString(num) + '\n';
	ifstream file;
	char line[maxNum] = { '\0' };
	file.open(fileName);
	if (file.is_open()) {
		file.getline(line, maxNum);
		while (file.getline(line, maxNum)) {
			str = str + charToString(line) + '\n';
		}
		_itoa_s(n, num, maxNum, 10);
		str = str + charToString(num) + ',' + word.toStdString();
	}
	file.close();
	fstream ofile;
	ofile.open(fileName, ios::out);							//覆盖原来的文件，将整个更改后新的内容写入
	ofile << str;
	ofile.close();
}

int testBuilderwindow::isExist(QString word, char *fileName) {
	QByteArray b = word.toLatin1();
	char *word_ = b.data();
	ifstream file;
	char le[1024] = { '\0' };
	char n[1024] = { '\0' };
	char *word_tmp = NULL;
	file.open(fileName);
	if (file.is_open()) {
		file.getline(n, sizeof(n));
		int num;
		istringstream istr;
		istr.str(n);
		istr >> num;
		int i = 0;
		while (file.getline(le, maxNum) && i <= num) {
			strtok(le, ",");
			word_tmp = strtok(NULL, ",");
			if (!strcmp(word_, word_tmp)) {
				this->ui->lab1_display->setText(u8"单词已存在");
				return 0;
			}
			i++;
		}
		file.close();
		return num;
	}
	this->ui->lab1_display->setText(u8"检测失败");
	return 0;
}

void testBuilderwindow::detect() {
	QString word = this->ui->le1_word->text();
	int length = word.length();
	if (length == 0) {
		this->ui->lab1_display->setText(u8"请输入单词");
	}
	else if (length <= 3 && length > 0) {
		char fileName[maxNum] = "D:\\learn\\C++\\words1.csv";
		int n = isExist(word, fileName);
		if (n != 0)
			this->ui->lab1_display->setText(u8"可加入");
	}
	else if (length <= 6 && length > 3) {
		char fileName[maxNum] = "D:\\learn\\C++\\words2.csv";
		int n = isExist(word, fileName);
		if (n != 0)
			this->ui->lab1_display->setText(u8"可加入");
	}
	else if (length <= 9 && length > 6) {
		char fileName[maxNum] = "D:\\learn\\C++\\words3.csv";
		int n = isExist(word, fileName);
		if (n != 0)
			this->ui->lab1_display->setText(u8"可加入");
	}
	else if (length <= 12 && length > 9) {
		char fileName[maxNum] = "D:\\learn\\C++\\words4.csv";
		int n = isExist(word, fileName);
		if (n != 0)
			this->ui->lab1_display->setText(u8"可加入");
	}
	else if (length <= 15 && length > 12) {
		char fileName[maxNum] = "D:\\learn\\C++\\words5.csv";
		int n = isExist(word, fileName);
		if (n != 0)
			this->ui->lab1_display->setText(u8"可加入");
	}
	else if (length <= 18 && length > 15) {
		char fileName[maxNum] = "D:\\learn\\C++\\words6.csv";
		int n = isExist(word, fileName);
		if (n != 0)
			this->ui->lab1_display->setText(u8"可加入");
	}
	else {
		this->ui->lab1_display->setText(u8"您输入的单词过长");
	}
}

void testBuilderwindow::confirm() {
	QString word = this->ui->le1_word->text();
	int length = word.length();
	if (length == 0) {
		this->ui->lab1_display->setText(u8"请输入单词");
	}
	else if (length <= 3 && length > 0) {
		char fileName[maxNum] = "D:\\learn\\C++\\words1.csv";
		int n = isExist(word, fileName);
		if (n != 0) {
			writeToFile(word, fileName, n);
			this->ui->lab1_display->setText(u8"添加成功");
			T.wordCount++;
			this->ui->le1_word->clear();
		}
		else
			this->ui->lab1_display->setText(u8"添加失败");
	}
	else if (length <= 6 && length > 3) {
		char fileName[maxNum] = "D:\\learn\\C++\\words2.csv";
		int n = isExist(word, fileName);
		if (n != 0) {
			writeToFile(word, fileName, n);
			this->ui->lab1_display->setText(u8"添加成功");
			T.wordCount++;
			this->ui->le1_word->clear();
		}
		else
			this->ui->lab1_display->setText(u8"添加失败");
	}
	else if (length <= 9 && length > 6) {
		char fileName[maxNum] = "D:\\learn\\C++\\words3.csv";
		int n = isExist(word, fileName);
		if (n != 0) {
			writeToFile(word, fileName, n);
			this->ui->lab1_display->setText(u8"添加成功");
			T.wordCount++;
			this->ui->le1_word->clear();
		}
		else
			this->ui->lab1_display->setText(u8"添加失败");
	}
	else if (length <= 12 && length > 9) {
		char fileName[maxNum] = "D:\\learn\\C++\\words4.csv";
		int n = isExist(word, fileName);
		if (n != 0) {
			writeToFile(word, fileName, n);
			this->ui->lab1_display->setText(u8"添加成功");
			T.wordCount++;
			this->ui->le1_word->clear();
		}
		else
			this->ui->lab1_display->setText(u8"添加失败");
	}
	else if (length <= 15 && length > 12) {
		char fileName[maxNum] = "D:\\learn\\C++\\words5.csv";
		int n = isExist(word, fileName);
		if (n != 0) {
			writeToFile(word, fileName, n);
			this->ui->lab1_display->setText(u8"添加成功");
			T.wordCount++;
			this->ui->le1_word->clear();
		}
		else
			this->ui->lab1_display->setText(u8"添加失败");
	}
	else if (length <= 18 && length > 15) {
		char fileName[maxNum] = "D:\\learn\\C++\\words6.csv";
		int n = isExist(word, fileName);
		if (n != 0) {
			writeToFile(word, fileName, n);
			this->ui->lab1_display->setText(u8"添加成功");
			T.wordCount++;
			this->ui->le1_word->clear();
		}
		else
			this->ui->lab1_display->setText(u8"添加失败");
	}
	else {
		this->ui->lab1_display->setText(u8"您输入的单词过长");
	}
	if (T.wordCount >= sum(T.level))
		T.level++;
	T.modifyContentInFile(testBuilderFile, line);
	QString lv, wordCount;
	lv = QString::number(T.level);
	this->ui->lab1_lv->setText("LV: " + lv);
	wordCount = QString::number(T.wordCount);
	this->ui->lab1_wordNum->setText(u8"出题数: " + wordCount);
	this->ui->le1_word->setFocus();
}

void testBuilderwindow::tabChanged(int tab) {
	if (tab == 0) {
		this->ui->lab1_display->setText(u8"");
		this->ui->le1_word->setFocus();
	}
	else if (tab == 1) {
		this->ui->le2_search->setFocus();
	}
	else if (tab == 3)
		displayMy();
}

void testBuilderwindow::search() {
	QString content = this->ui->le2_search->text();
	char *name;
	QByteArray b = content.toLatin1();
	name = b.data();
	//QApplication::setQuitOnLastWindowClosed(false);			//关闭窗口时不会退出程序
	switch (BG2->checkedId()) {
	case 0:
	{
		Player search_p;
		int n = search_p.getContentInFile(playerFile, name);
		if (n != -1) {
			QString content = "Name:    " + QString(QLatin1String(search_p.playerName)) + '\n';
			content = content + "lv:         " + QString::number(search_p.level) + '\n';
			content = content + u8"通关数:    " + QString::number(search_p.checkPoint) + '\n';
			QMessageBox::information(this, "player", content, QMessageBox::Ok);
		}
		else {
			QString content = u8"用户不存在";
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
			content = content + u8"出题数:    " + QString::number(search_t.wordCount) + '\n';
			QMessageBox::information(this, "player", content, QMessageBox::Ok);
		}
		else {
			QString content = u8"用户不存在";
			QMessageBox::warning(this, "player", content, QMessageBox::Ok);
		}
		break;
	}
	default:
		break;
	}
}

void testBuilderwindow::update() {
	QStandardItemModel *model = new QStandardItemModel(this);
	model->setColumnCount(4);
	model->setHeaderData(0, Qt::Horizontal, u8"账户名");
	model->setHeaderData(1, Qt::Horizontal, u8"游戏名");
	model->setHeaderData(2, Qt::Horizontal, u8"等级");
	int i = 0;
	if (BG3->checkedId() == 0) {			//选中闯关者
		model->setHeaderData(3, Qt::Horizontal, u8"通关数");
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
				else {									//选择排序
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
	else {									//选中出题者
		model->setHeaderData(3, Qt::Horizontal, u8"出题数");
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
				else {									//选择排序
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

void testBuilderwindow::rbtnChanged(int index) {
	if (index == 0) {						//选中闯关者
		this->ui->cb3_type->setItemText(1, u8"闯关数");
	}
	else {									//选中出题者
		this->ui->cb3_type->setItemText(1, u8"出题数");
	}
}

void testBuilderwindow::displayMy() {
	TestBuilder my;
	my.getContentInFile(testBuilderFile, T.accountName);
	QString accoutName, builderName, lv, wordCount;
	accoutName = QString(QLatin1String(my.accountName));
	builderName = QString(QLatin1String(my.builderName));
	lv = QString::number(my.level);
	wordCount = QString::number(my.wordCount);

	this->ui->lab4_accountName->setText(u8"账户名:       " + accoutName);
	this->ui->lab4_name->setText(u8"游戏名:       " + builderName);
	this->ui->lab4_lv->setText(u8"等级:       " + lv);
	this->ui->lab4_testNum->setText(u8"出题数:       " + wordCount);
	
}