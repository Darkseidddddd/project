#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "User.h"
#include "UsefulFunction.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <windows.h>

using namespace std;

SOCKET Client;

User::User() {
	isNew = true;
	accountName[0] = '\0';
	password[0] = '\0';
}

User::User(const User &obj) {
	strcpy(accountName, obj.accountName);
	strcpy(password, obj.password);
	Type = obj.Type;
	isNew = obj.isNew;
}

void User::operator=(const User &U) {
	strcpy(accountName, U.accountName);
	strcpy(password, U.password);
	isNew = U.isNew;
	Type = U.Type;
}

int User::Register(QString account, QString password, QString confirmpw, int type) {				//����0���˻��Ѵ��ڣ�����1��ע��ɹ�������2���������벻һ�¡�
	User U;
	char *reg_account, *reg_password, *reg_confirmpw;
	QByteArray b1 = account.toLatin1();
	QByteArray b2 = password.toLatin1();
	QByteArray b3 = confirmpw.toLatin1();
	reg_account = b1.data();
	reg_password = b2.data();
	reg_confirmpw = b3.data();
	char fileName[maxNum] = "C:\\Users\\light\\Desktop\\User.csv";
	if (U.getContentInFile(fileName,reg_account) != -1) {
		return 0;
	}
	if (!strcmp(reg_password, reg_confirmpw)) {
		strcpy(U.accountName, reg_account);
		strcpy(U.password, reg_password);
		U.Type = type;
		U.isNew = true;
		U.writeIntoFile(fileName);
		return 1;
	}
	else
		return 2;
}

void new_client(char *account)
{
	//SOCKET Client;
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return; }

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}

	Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN Server;

	// Ҫ���ӵĻ�����Ϣ
	Server.sin_family = AF_INET;
	Server.sin_port = htons(8888);
	inet_pton(AF_INET, "127.0.0.1", &Server.sin_addr); //���ʮ���Ƶ�ַת���������ֽ���

	// �����˷�������
	int ret = connect(Client, (struct sockaddr*)&Server, sizeof(Server));

	if (ret == SOCKET_ERROR)
	{
		printf("����ʧ��\n");
		closesocket(Client);
		WSACleanup();
		return;
	}

	char recvBuf[128];
	char sendBuf[128];
	strcpy(sendBuf, account);
	//while (true)
	//{
		//printf("please input message:\n");
		//gets_s(sendBuf);
		//sprintf_s(sendBuf, "%s_%d", sendBuf, pos);
	//send(Client, sendBuf, strlen(sendBuf) + 1, 0);
	/*
	recv(Client, recvBuf, 128, 0);
	char ipServer[16];
	inet_ntop(AF_INET, &Server.sin_addr, ipServer, sizeof(ipServer));
	printf("%s said: %s\n", ipServer, recvBuf);
	*/
	//}

	//closesocket(Client);
	//WSACleanup();

}

int User::Login(QString name, QString pw) {			//��½�������û����ڷ���1���û������ڷ���0��������󷵻�2
	User U;
	char *login_name, *login_password;
	QByteArray b1 = name.toLatin1();
	QByteArray b2 = pw.toLatin1();
	login_name = b1.data();
	login_password = b2.data();
	char fileName[maxNum] = "C:\\Users\\light\\Desktop\\User.csv";
	int loginSucc = 0, lineNum;
	lineNum = U.getContentInFile(fileName, login_name);
	if (lineNum == -1) {
		//qDebug() << u8"�˻�������" << endl;
		return 0;
	}
	else {
		if (!strcmp(login_password, U.password)) {
			new_client(login_name);
			char sendBuf[128] = "1";
			char recvBuf[128];
			send(Client, sendBuf, strlen(sendBuf) + 1, 0);
			Sleep(500);
			send(Client, login_name, strlen(login_name) + 1, 0);
			recv(Client, recvBuf, 128, 0);
			int ret = recvBuf[0] - '0';
			if (ret == 0)
				return 3;
			strcpy(accountName, login_name);
			strcpy(password, login_password);
			Type = U.Type;
			isNew = U.isNew;
			//qDebug() << u8"��½�ɹ�" << endl;
			return 1;
		}
		else {
			//qDebug() << u8"�������" << endl;
			return 2;
		}
	}
	return 0;
}

int User::getContentInFile(char *fileName = NULL, char *content = NULL) {		//��ȡ�ļ��е���Ϣ����������������-1��ʾ������
	int i = 1, j = -1;
	if (fileName) {
		ifstream file;
		char line[1024] = { '\0' };
		file.open(fileName);
		if (file.is_open()) {
			while (file.getline(line, maxNum)) {
				strcpy(accountName, strtok(line, ","));
				if (!strcmp(accountName, content)) {
					strcpy(password, strtok(NULL, ","));
					Type = *strtok(NULL, ",") - '0';				//ת��Ϊint��
					isNew = (bool)(*strtok(NULL, ",") - '0');				//ǿ��ת��Ϊbool����
					j = i;
					break;
				}
				i++;
			}
			file.close();
		}
		else
			cout << "error!" << endl;
	}
	return j;
}

void User::writeIntoFile(char *fileName = NULL) {
	fstream file;
	file.open(fileName, ios::app);
	if (file.is_open()) {
		file << accountName << "," << password << "," << Type << "," << isNew << endl;
	}
	else
		cout << "error!" << endl;
}

void User::modifyContentInFile(char *fileName, int lineNum) {
	ifstream file;
	file.open(fileName);
	char line[maxNum] = { '\0' };
	string temp_str, temp;						//temp_str���ڴ��ļ���ÿһ�е����ݣ�temp���ڴ���Ҫ�ı��е�����
	char str[maxNum];
	temp = temp + charToString(accountName) + ',' + charToString(password) + ',';
	_itoa_s(Type, str, maxNum, 10);				//��10���Ƶ�����תΪ�ַ���
	temp = temp + charToString(str) + ',';
	ostringstream isNew_str;
	isNew_str << isNew;								//��bool����תΪ�ַ���
	temp = temp + string(isNew_str.str()) + '\n';
	cout << temp << endl;
	int i = 0;
	if (file.is_open()) {
		while (file.getline(line, sizeof(line))) {
			i++;
			if (i != lineNum)
				temp_str = temp_str + charToString(line) + '\n';		//����Ŀ����ʱ������temp_str��
			else
				temp_str += temp;										//������Ŀ����ʱ����Ҫ���ĵ����ݶ���temp_str��
		}
	}
	else
		cout << "error!" << endl;
	if (temp_str.empty())												//����ļ�Ϊ�գ���temp_strΪ�գ�ֱ�ӽ����ĵ����ݶ�������
		temp_str += temp;
	file.close();
	fstream ofile;
	ofile.open(fileName, ios::out);							//����ԭ�����ļ������������ĺ��µ�����д��
	ofile << temp_str;
	ofile.close();
}

Player::Player() {
	accountName[0] = '\0';
	playerName[0] = '\0';
	checkPoint = 0;
	experience = 0;
	level = 1;
}

Player::Player(const Player &obj) {
	strcpy(accountName, obj.accountName);
	strcpy(playerName, obj.playerName);
	checkPoint = obj.checkPoint;
	experience = obj.experience;
	level = obj.level;
}

void Player::operator=(const Player &P) {
	strcpy(accountName, P.accountName);
	strcpy(playerName, P.playerName);
	level = P.level;
	checkPoint = P.checkPoint;
	experience = P.experience;
}

int Player::getContentInFile(char *fileName = NULL, char *content = NULL) {				//��ȡ�ļ��е���Ϣ����������
	int i = 1, j = -1;
	if (fileName) {
		ifstream file;
		char line[1024] = { '\0' };
		file.open(fileName);
		if (file.is_open()) {
			while (file.getline(line, sizeof(line))) {
				strcpy(accountName, strtok(line, ","));
				strcpy(playerName, strtok(NULL, ","));
				if (!strcmp(accountName, content) || !strcmp(playerName, content)) {
					checkPoint = atoi(strtok(NULL, ","));
					experience = atoi(strtok(NULL, ","));
					level = atoi(strtok(NULL, ","));
					j = i;
					break;
				}
				i++;
			}
			file.close();
		}
		else
			cout << "error!" << endl;
	}
	return j;
}

void Player::writeIntoFile(char *fileName = NULL) {
	fstream file;
	file.open(fileName, ios::app);
	if (file.is_open())
		file << accountName << "," << playerName << "," << checkPoint << "," << experience << "," << level << endl;
	else
		cout << "error!" << endl;
	file.close();
}

void Player::modifyContentInFile(char *fileName, int lineNum) {
	ifstream file;
	file.open(fileName);
	char line[maxNum] = { '\0' };
	string temp_str, temp;
	char str[maxNum];
	_itoa_s(checkPoint, str, maxNum, 10);
	temp = temp + charToString(accountName) + ',' + charToString(playerName) + ',';
	temp = temp + charToString(str) + ',';
	_itoa_s(experience, str, maxNum, 10);
	temp = temp + charToString(str) + ',';
	_itoa_s(level, str, maxNum, 10);
	temp = temp + charToString(str) + '\n';
	//cout << temp << endl;
	int i = 0;
	if (file.is_open()) {
		while (file.getline(line, sizeof(line))) {
			i++;
			if (i != lineNum)
				temp_str = temp_str + charToString(line) + '\n';
			else
				temp_str += temp;
		}
	}
	else
		cout << "error" << endl;
	if (temp_str.empty())
		temp_str += temp;
	file.close();
	fstream ofile;
	ofile.open(fileName, ios::out);
	ofile << temp_str;
	ofile.close();
}

TestBuilder::TestBuilder() {
	accountName[0] = '\0';
	builderName[0] = '\0';
	wordCount = 0;
	level = 1;
}

TestBuilder::TestBuilder(const TestBuilder &obj) {
	strcpy(accountName, obj.accountName);
	strcpy(builderName, obj.builderName);
	wordCount = obj.wordCount;
	level = obj.level;
}

void TestBuilder::operator=(const TestBuilder &T) {
	strcpy(accountName, T.accountName);
	strcpy(builderName, T.builderName);
	level = T.level;
	wordCount = T.wordCount;
}

int TestBuilder::getContentInFile(char *fileName = NULL, char *content = NULL) {					//��ȡ�ļ��е� ��Ϣ����������
	int i = 1, j = -1;
	if (fileName) {
		ifstream file;
		char line[1024] = { '\0' };
		file.open(fileName);
		if (file.is_open()) {
			while (file.getline(line, sizeof(line))) {
				strcpy(accountName, strtok(line, ","));
				strcpy(builderName, strtok(NULL, ","));
				if (!strcmp(accountName, content) || !strcmp(builderName, content)) {
					wordCount = atoi(strtok(NULL, ","));
					level = atoi(strtok(NULL, ","));
					j = i;
					break;
				}
				i++;
			}
			file.close();
		}
		else
			cout << "error!" << endl;
	}
	return j;
}

void TestBuilder::writeIntoFile(char *fileName) {
	fstream file;
	file.open(fileName, ios::app);
	if (file.is_open())
		file << accountName << "," << builderName << "," << wordCount << "," << level << endl;
	else
		cout << "error!" << endl;
	file.close();
}

void TestBuilder::modifyContentInFile(char *fileName, int lineNum) {
	ifstream file;
	file.open(fileName);
	char line[maxNum] = { '\0' };
	string temp_str, temp;
	char str[maxNum];
	temp = temp + charToString(accountName) + ',' + charToString(builderName) + ',';
	_itoa_s(wordCount, str, maxNum, 10);
	temp = temp + charToString(str) + ',';
	_itoa_s(level, str, maxNum, 10);
	temp = temp + charToString(str) + '\n';
	//cout << temp << endl;
	int i = 0;
	if (file.is_open()) {
		while (file.getline(line, sizeof(line))) {
			i++;
			if (i != lineNum)
				temp_str = temp_str + charToString(line) + '\n';
			else
				temp_str += temp;
		}
	}
	else
		cout << "error" << endl;
	if (temp_str.empty())
		temp_str += temp;
	file.close();
	fstream ofile;
	ofile.open(fileName, ios::out);
	ofile << temp_str;
	ofile.close();
}


