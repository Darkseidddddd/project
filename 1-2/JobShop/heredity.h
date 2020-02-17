#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

#define POPU_NUM 60
#define BUF_SIZE 1024
#define MAX_INT 999999
#define GENERATE_PROB 1
#define VARIATION_PROB 0.5
#define GROUP 20

/*
POPU_NUM, #define, 常量, 种群染色体数
BUF_SIZE, #define, 常量, 临时buffer的大小
MAX_INT, #define, 常量, int型最大值
GENERATE_PROB, #define, 常量, 模拟交配概率
VARIATION_PROB, #define, 常量, 变异概率
GROUP, #define, 常量, 竞标赛选择算法抽取一组的个数

chro_len, int, 染色体长度
workpiece_num, int, 工件的数量
work, int*, 一维数组, 工件对应的工序数
machine_num, int, 所有机器的数量
work_time, int**, 二维数组, 工件工序对应的所需时间
work_machine, int**, 二维数组, 工件工序对应的机器
optimal_fitness, int, 种群中最优个体的适应度
popu_fitness, int*, 一维数组, 种群每个个体的适应度
*/

/*
种群类
chromosome, int**, 二维数组, 染色体
chro_len, int, 染色体长度
*/
class Population
{
private:
	int* work;
	int** chromosome, ** work_time, ** work_machine;
	int chro_len, workpiece_num, machine_num;
	int optimal_fitness;
	int* popu_fitness;
	int** offspring_chromosome;
	int offspring_len;
	int* offspring_fitness;
public:
	Population(char* file_name);
	~Population();
	int getOptimalFitness();
	void Initial();
	// 打印输入情况
	void printIn();
	// 打印种群信息
	void printInfo();
	// 计算适应度
	void computeFitness();
	// 交配
	void generate();
	// 变异
	void variation();
	// 选择
	void select();
	// 格式化输出到文件
	void saveToFile(int* file_name);
	// 最优化
	void optimize(int iter);
};
