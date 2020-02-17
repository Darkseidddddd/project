#include "heredity.h"


int main(void)
{
	char file_name[BUF_SIZE] = "D:/learn/JobShop/data/input4.txt";
	int iter = 10000;
	// ��ʼ��
	Population population(file_name);
	population.printIn();
	population.Initial();
	// ��ʼ�Ż�
	clock_t start, end;
	start = clock();
	population.optimize(iter);
	end = clock();
	population.computeFitness();
	population.printInfo();
	cout << "����ʱ�䣺" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	population.saveToFile(NULL);
	return 0;
}