#include <iostream>
#include "User.h"
#include "game_Player.h"
#include "game_TestBuilder.h"
using namespace std;

void Game_2(User U) {
	switch (U.Type)
	{
	case 1:
	{
		Player P;
		char fileName[maxNum] = "C:\\Users\\light\\Desktop\\Player.csv";
		P.getContentInFile(fileName, U.accountName);
		game_Player(P);
	}
	case 2:
	{
		TestBuilder T;
		char fileName[maxNum] = "C:\\Users\\light\\Desktop\\TestBuilders.csv";
		T.getContentInFile(fileName, U.accountName);
		game_TestBuilder(T);
	}
	default:
		break;
	}
}

