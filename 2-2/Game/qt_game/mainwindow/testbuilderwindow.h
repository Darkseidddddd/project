#ifndef TESTBUILDERWINDOW_H
#define TESTBUILDERWINDOW_H

#include <QDialog>
#include <qbuttongroup.h>

namespace Ui {
class testBuilderwindow;
}

class testBuilderwindow : public QDialog
{
    Q_OBJECT

public:
    explicit testBuilderwindow(QWidget *parent = nullptr);
    ~testBuilderwindow();

private slots:
	void receiveData(QString name);
	void tabChanged(int);
	//����
	void exit();
	void detect();
	int isExist(QString word, char *fileName);
	void writeToFile(QString word, char *fileName, int n);
	void confirm();
	//��ѯ����
	void search();
	//���а�
	void update();
	void rbtnChanged(int);
	//�ҵ�
	void displayMy();

private:
    Ui::testBuilderwindow *ui;
	QButtonGroup *BG2, *BG3;
};

#endif // TESTBUILDERWINDOW_H
