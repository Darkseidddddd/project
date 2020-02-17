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
POPU_NUM, #define, ����, ��ȺȾɫ����
BUF_SIZE, #define, ����, ��ʱbuffer�Ĵ�С
MAX_INT, #define, ����, int�����ֵ
GENERATE_PROB, #define, ����, ģ�⽻�����
VARIATION_PROB, #define, ����, �������
GROUP, #define, ����, ������ѡ���㷨��ȡһ��ĸ���

chro_len, int, Ⱦɫ�峤��
workpiece_num, int, ����������
work, int*, һά����, ������Ӧ�Ĺ�����
machine_num, int, ���л���������
work_time, int**, ��ά����, ���������Ӧ������ʱ��
work_machine, int**, ��ά����, ���������Ӧ�Ļ���
optimal_fitness, int, ��Ⱥ�����Ÿ������Ӧ��
popu_fitness, int*, һά����, ��Ⱥÿ���������Ӧ��
*/

/*
��Ⱥ��
chromosome, int**, ��ά����, Ⱦɫ��
chro_len, int, Ⱦɫ�峤��
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
	// ��ӡ�������
	void printIn();
	// ��ӡ��Ⱥ��Ϣ
	void printInfo();
	// ������Ӧ��
	void computeFitness();
	// ����
	void generate();
	// ����
	void variation();
	// ѡ��
	void select();
	// ��ʽ��������ļ�
	void saveToFile(int* file_name);
	// ���Ż�
	void optimize(int iter);
};
