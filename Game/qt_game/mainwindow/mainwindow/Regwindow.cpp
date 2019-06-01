#include "Regwindow.h"
#include "ui_Regwindow.h"
#include "User.h"

Regwindow::Regwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Regwindow)
{
    ui->setupUi(this);
	connect(this->ui->btn_return, SIGNAL(clicked(bool)), this, SLOT(cancel()));
	connect(this->ui->btn_confirmReg, SIGNAL(clicked(bool)), this, SLOT(Register()));
}

Regwindow::~Regwindow()
{
    delete ui;
}

void Regwindow::Register() {
	QString name = this->ui->le_accountReg->text();            //获取输入的内容
	QString password = this->ui->le_pwReg->text();
	QString confirmpw = this->ui->le_confirmpw->text();
	if (name.isEmpty()) {
		this->ui->lab_display->setText(u8"账户名不能为空");
	}
	else if (password.isEmpty()) {
		this->ui->lab_display->setText(u8"请输入密码");
	}
	else if (confirmpw.isEmpty()) {
		this->ui->lab_display->setText(u8"请确认密码");
	}
	int type = this->ui->cb_type->currentIndex() + 1;
	User U;
	switch (U.Register(name, password, confirmpw, type)) {
	case 0:
		this->ui->lab_display->setText(u8"账户已存在");
		break;
	case 1:
		this->ui->lab_display->setText(u8"注册成功");
		cancel();
		break;
	case 2:
		this->ui->lab_display->setText(u8"两次密码不同");
		break;
	default:
		break;
	}
}

void Regwindow::cancel() {
	emit sendsignal();
    this->close();
}
