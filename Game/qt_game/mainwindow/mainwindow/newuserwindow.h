#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QDialog>
#include "User.h"

namespace Ui {
class newUserwindow;
}

class newUserwindow : public QDialog
{
    Q_OBJECT

public:
    explicit newUserwindow(QWidget *parent = nullptr);
    ~newUserwindow();

private slots:
    void exit();
	void confirm();
	void receiveData(QString name);

signals:
	void sendData(QString);
private:
    Ui::newUserwindow *ui;
};

#endif // NEWUSERWINDOW_H
