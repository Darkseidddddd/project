#include "heredity.h"


int main(void)
{
	char file_name[BUF_SIZE] = "D:/learn/JobShop/data/input4.txt";
	int iter = 10000;
	// 初始化
	Population population(file_name);
	population.printIn();
	population.Initial();
	// 开始优化
	clock_t start, end;
	start = clock();
	population.optimize(iter);
	end = clock();
	population.computeFitness();
	population.printInfo();
	cout << "运行时间：" << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;
	population.saveToFile(NULL);
	return 0;
}