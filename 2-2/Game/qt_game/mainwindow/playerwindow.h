#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QDialog>
#include <string.h>
#include <qtimer.h>
#include <qbuttongroup.h>
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <stdlib.h>

namespace Ui {
class playerwindow;
}

class playerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit playerwindow(QWidget *parent = nullptr);
    ~playerwindow();
	
private slots:
	void exit();
	void receiveData(QString name);
	char *getword(char *fileName);
	void start();
	void start_1();
	void start_2();
	void start_3();
	void play();
	void check();
	void restart();
	void changePattern(int index);
	void multiplay();
	void reshow();
	//查询界面
	void tabChanged(int);
	void search();
	//排行榜
	void update();
	void rbtnChanged(int);
	//我的
	void displayMy();
signals:
	void sendsignal();

private:
    Ui::playerwindow *ui;
	QTimer *qtimer;
	int temp;
	QButtonGroup *BG2, *BG3;
};

#endif // PLAYERWINDOW_H
