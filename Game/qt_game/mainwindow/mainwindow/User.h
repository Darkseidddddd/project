#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <qstring.h>
#include <math.h>

#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <stdlib.h>

#define nameMax 100
#define pwMax 150
#define maxNum 1024
#define Ex(x) (pow(x-1, 3)+60)/5*(pow(x-1, 2)+60)			//定义升级所需经验值
#define ex(x) (pow(x-1, 3)+60)/5+1000/x						//定义通过一关获得的经验值
#define userFile "C:\\Users\\light\\Desktop\\User.csv"
#define playerFile "C:\\Users\\light\\Desktop\\Player.csv"
#define testBuilderFile "C:\\Users\\light\\Desktop\\TestBuilder.csv"
using namespace std;

extern SOCKET Client;

class User {							//用户类
public:
	char accountName[nameMax];
	char password[pwMax];
	int Type;
	bool isNew;
public:
	User();
	User(const User &obj);
	void operator=(const User &U);
	int Register(QString account, QString password, QString confirmpw, int type);
	int Login(QString name, QString pw);
	virtual int getContentInFile(char *fileName, char *content);
	virtual void writeIntoFile(char *fileName);
	virtual void modifyContentInFile(char *fileName, int lineNum);
};

class Player : public User {			//闯关者类
public:
	char playerName[nameMax];
	int checkPoint, experience, level;
public:
	Player();
	Player(const Player &obj);
	void operator=(const Player &P);
	int getContentInFile(char *fileName, char *content);
	void writeIntoFile(char *fileName);
	void modifyContentInFile(char *fileName, int lineNum);
};

class TestBuilder : public User {		//出题者类
public:
	char builderName[nameMax];
	int wordCount, level;
public:
	TestBuilder();
	TestBuilder(const TestBuilder &obj);
	void operator=(const TestBuilder &T);
	int getContentInFile(char *fileName, char *content);
	void writeIntoFile(char *fileName);
	void modifyContentInFile(char *fileName, int lineNum);
};


#endif // !USER_H
