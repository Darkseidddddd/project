#ifndef MULTIPLAYWINDOW_H
#define MULTIPLAYWINDOW_H

#include <QDialog>
#include <string.h>
#include <qtimer.h>


namespace Ui {
class multiplaywindow;
}

class multiplaywindow : public QDialog
{
    Q_OBJECT

public:
    explicit multiplaywindow(QWidget *parent = nullptr);
    ~multiplaywindow();
public slots:
	//游戏界面
	void exit();
	//查询在线界面
	void update();

signals:
	void sendsignal();

private:
    Ui::multiplaywindow *ui;
};

#endif // MULTIPLAYWINDOW_H
