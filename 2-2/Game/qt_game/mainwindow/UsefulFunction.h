#pragma once
#ifndef USEFULFUNCTION_H
#define USEFULFUNCTION_H
#include <string.h>
#include <iostream>
#include <QString>
using namespace std;

extern void Page1(void);
extern void Page2(void);
extern int get_choice(int a, int b);
extern string charToString(char *s);
extern char *QstringToChar(QString S);
extern int sum(int n);

#endif // !USEFULFUNCTION_H
