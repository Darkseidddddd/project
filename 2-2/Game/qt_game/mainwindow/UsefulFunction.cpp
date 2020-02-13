#include <iostream>
#include <string.h>
#include <QString>
using namespace std;


void Page1(void) {							//欢迎界面
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Exit" << endl;
}

void Page2(void) {							//注册选择类型界面
	cout << "Select your user type:" << endl;
	cout << "1. Player" << endl;
	cout << "2. TestBuilder" << endl;
}

int get_choice(int a, int b) {		//获得一个正确输入的[a,b]之间的整型值
	int choice;
	while (1) {
		cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Input error, please input again." << endl;
			Page1();
			cin >> choice;
		}
		if (choice >= a && choice <= b) {
			cin.ignore();
			break;
		}
		cout << "Input error, please input again." << endl;
	}
	return choice;
}

string charToString(char *s) {				//char型字符串转为string型
	string temp;
	for (int i = 0; s[i] != '\0'; i++)
		temp += s[i];
	return temp;
}

char *QstringToChar(QString S) {
	QByteArray b = S.toLatin1();
	char *ch;
	ch = b.data();
	return ch;
}

int sum(int n) {
	int i = 1, s = 0;
	for (; i <= n; i++)
		s += i;
	return s;
}