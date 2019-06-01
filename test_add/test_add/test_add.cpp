#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
#define Size 10

class CPU
{
protected:
	char **memoryI;
	int *memoryN;
	int R1, R2, R3, PC;
	string IR;
public:
	CPU()
	{
		memoryI = new char*[Size];
		for (int i = 0; i < Size; i++)
		{
			memoryI[i] = new char[20];
		}
		memoryN = new int[Size];
		memoryN[1] = 1;
		R1 = 0;
		R2 = 0;
		R3 = 0;
		PC = 1;
	}
	~CPU()
	{
		for (int i = 0; i < Size; i++)
		{
			delete memoryI[i];
		}
		delete memoryI;
	}
	void getInstruct();
	void display();
	void modifyR(int n, int m);
	void replaceIns(int n, const char *str);
	int execIns();
	void clear();
};

void CPU::getInstruct()
{
	ifstream file;
	file.open("test.txt");
	if (file.is_open())
	{
		char line[1024] = { '\0' };
		int i = 1;
		while (file.getline(line, 1024))
		{
			strcpy(memoryI[i], line);
			//cout << memoryI[i] << endl;
			i++;
		}
	}
}

void CPU::display()
{
	cout << "PC=" << PC << ", ";
	cout << "IR=" << IR << ", ";
	cout << "AC=" << R1 << ", ";
	cout << "R2=" << R2 << ", ";
	cout << "R3=" << R3 << ", " << endl;
}

void CPU::modifyR(int n, int m)
{
	switch (n)
	{
	case 1:
		R1 = m;
		break;
	case 2:
		R2 = m;
		break;
	case 3:
		R3 = m;
		break;
	default:
		break;
	}
}

void CPU::replaceIns(int n, const char *str)
{
	strcpy(memoryI[n], str);
}

vector<string> split(string str, char pattern)
{
	vector<string> result;
	string::size_type pos;
	pos = str.find(pattern, 0);
	string s = str.substr(0, pos);
	result.push_back(s);
	s = str.substr(pos + 1, str.size());
	result.push_back(s);
	return result;
}

int CPU::execIns()
{
	IR = memoryI[PC];
	string ins = memoryI[PC];
	vector<string> ins_ = split(ins, '(');
	if (ins_[0] == "NOP")
	{
		return 0;
	}
	PC++;
	if (ins_[0] == "CLA")
	{
		R1 = 0;
		R2 = 0;
		R3 = 0;
	}
	else
	{
		vector<string> ins_R1 = split(ins_[1], ',');
		vector<string> ins_R2 = split(ins_R1[1], ')');
		//cout << ins_R1[0] << " " << ins_R2[0] << endl;
		if (ins_[0] == "JBE")
		{
			ins_R2 = split(ins_R1[1], ',');
			vector<string> ins_R3 = split(ins_R2[1], ')');
			int r;
			if (ins_R1[0] == "R1")
				r = R1;
			else if (ins_R1[0] == "R2")
				r = R2;
			else if (ins_R1[0] == "R3")
				r = R3;
			if (r <= atoi(ins_R2[0].c_str()))
			{
				PC = atoi(ins_R3[0].c_str());
			}
		}
		else if (ins_[0] == "NOT")
		{
			ins_R1 = split(ins_[1], ')');
			if (ins_R1[0] == "R1")
				R1 = ~R1;
			else if (ins_R1[0] == "R2")
				R2 = ~R2;
			else if (ins_R1[0] == "R3")
				R3 = ~R3;
		}
		else if (ins_[0] == "ADD" || ins_[0] == "SUB" || ins_[0] == "AND" || ins_[0] == "OR")
		{
			int r;
			if (ins_R1[0] == "R1")
				r = R1;
			else if (ins_R1[0] == "R2")
				r = R2;
			else if (ins_R1[0] == "R3")
				r = R3;
			if (ins_R2[0] == "R1")
			{
				if (ins_[0] == "ADD")
					R1 += r;
				else if (ins_[0] == "SUB")
					R1 -= r;
				else if (ins_[0] == "AND")
					R1 &= r;
				else
					R1 |= r;
			}
			else if (ins_R2[0] == "R2")
			{
				if (ins_[0] == "ADD")
					R2 += r;
				else if (ins_[0] == "SUB")
					R2 -= r;
				else if (ins_[0] == "AND")
					R2 &= r;
				else
					R2 |= r;
			}
			else if (ins_R2[0] == "R3")
			{
				if (ins_[0] == "ADD")
					R3 += r;
				else if (ins_[0] == "SUB")
					R3 -= r;
				else if (ins_[0] == "AND")
					R3 &= r;
				else
					R3 |= r;
			}
		}
		else if (ins_[0] == "LAD")
		{
			int n = atoi(ins_R2[0].c_str());
			if (ins_R1[0] == "R1")
				R1 = memoryN[n];
			else if (ins_R1[0] == "R2")
				R2 = memoryN[n];
			else if (ins_R1[0] == "R3")
				R3 = memoryN[n];
		}
		else if (ins_[0] == "STOR")
		{
			int n = atoi(ins_R2[0].c_str());
			if (ins_R1[0] == "R1")
				memoryN[n] = R1;
			else if (ins_R1[0] == "R2")
				memoryN[n] = R2;
			else if (ins_R1[0] == "R3")
				memoryN[n] = R3;
		}

	}
	return 1;
}

void CPU::clear()
{
	R1 = 0;
	R2 = 0;
	R3 = 0;
	PC = 1;
	IR.clear();
}

void add()
{
	CPU my;
	my.getInstruct();
	string ins;
	int ret = 1;
	while (getline(cin, ins) && ret)
	{
		if (ins == "next" || ins == "Next")
		{
			ret = my.execIns();
			my.display();
		}
		else if (ins == "restart" || ins == "Restart")
			my.clear();
		else
		{
			vector<string> str = split(ins, ' ');
			int r = atoi(str[0].c_str());
			if (str[1] == "R1")
				my.modifyR(1, r);
			else if (str[1] == "R2")
				my.modifyR(2, r);
			else if (str[1] == "R3")
				my.modifyR(3, r);
			else
			{
				my.replaceIns(r, str[1].data());
			}
			my.display();
		}
	}
	cout << "END" << endl;
}

int main()
{
	add();
	system("pause");
	return 0;
}