#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QDialog>

namespace Ui {
class Regwindow;
}

class Regwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Regwindow(QWidget *parent = nullptr);
    ~Regwindow();
private slots:
    void cancel();
	void Register();
signals:
	void sendsignal();

private:
    Ui::Regwindow *ui;
};

#endif // REGWINDOW_H
