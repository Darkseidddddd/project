#include <iostream>
#include "User.h"
#include "UsefulFunction.h"
using namespace std;
/*
User Game_1() {						//��Ϸ�ĵ�һ�׶Σ���½�ɹ����򷵻��˻����������˳�
	int choice = 0;
	User U;
	while (choice != 3) {
		Page1();
		choice = get_choice(1, 3);
		if (choice == 1) {
			Page2();
			choice = get_choice(1, 2);
			char fileName[maxNum] = "C:\\Users\\light\\Desktop\\User.csv";
			U.Register(choice);
			U.writeIntoFile(fileName);
			choice = 1;
		}
		else if (choice == 2) {
			if (U.Login())
				return U;
		}
	}
	strcpy(U.accountName, NULL);
	return U;
}
*/