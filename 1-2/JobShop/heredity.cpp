#ifndef _HEREDITY_H_
#define _HEREDITY_H_
#include "heredity.h"





void Population::optimize(int iter)
{
	for (int i = 0; i < iter; i++)
	{
		this->generate();
		this->variation();
		this->computeFitness();
		this->select();
	}
}

void Population::saveToFile(int* file_name)
{
	int i = 0;
	while (i < POPU_NUM)
	{
		if (this->popu_fitness[i] == this->optimal_fitness)
		{
			cout << "最优的个体染色体为：";
			for (int j = 0; j < this->chro_len; j++)
				cout << this->chromosome[i][j] << " ";
			cout << endl;
			break;
		}
		i++;
	}
	// 每台机器上工作的工件及工序
	int** machine_work, ** machine_process;
	machine_work = new int* [this->machine_num];
	machine_process = new int* [this->machine_num];
	for (int j = 0; j < this->machine_num; j++)
	{
		machine_work[j] = new int[this->workpiece_num];
		memset(machine_work[j], -1, sizeof(int) * this->workpiece_num);
		machine_process[j] = new int[this->workpiece_num];
		memset(machine_process[j], -1, sizeof(int) * this->workpiece_num);
	}
	// 每个工件对应的工序数
	int* work_;
	work_ = new int[this->workpiece_num];
	memcpy(work_, this->work, sizeof(int) * this->workpiece_num);
	// 每一台机器可以使用的时间
	int* machine_use_time;
	machine_use_time = new int[this->machine_num];
	memset(machine_use_time, 0, sizeof(int) * this->machine_num);
	// 每一个工件已经执行的工序中最后一道工序结束时间
	int* pre_process_time;
	pre_process_time = new int[this->workpiece_num];
	memset(pre_process_time, 0, sizeof(int) * this->workpiece_num);
	// 每一个工件的工序的开始及结束时间
	int** work_process_start, ** work_process_end;
	work_process_start = new int* [this->workpiece_num];
	work_process_end = new int* [this->workpiece_num];
	for (int j = 0; j < this->workpiece_num; j++)
	{
		work_process_start[j] = new int[this->machine_num];
		work_process_end[j] = new int[this->machine_num];
	}
	// 机器执行顺序
	int* machine_exec;
	machine_exec = new int[this->machine_num];
	memset(machine_exec, 0, sizeof(int) * this->machine_num);
	for (int j = 0; j < this->chro_len; j++)
	{
		// 当前工件号
		int work_now = this->chromosome[i][j] - 1;
		// 当前工序
		int process_now = this->work[work_now] - work_[work_now];
		work_[work_now]--;
		// 当前工序所需机器
		int machine_now = this->work_machine[work_now][process_now];
		// 当前工序所需时间
		int process_to_use = this->work_time[work_now][process_now];
		machine_work[machine_now][machine_exec[machine_now]] = work_now;
		machine_process[machine_now][machine_exec[machine_now]] = process_now;
		machine_exec[machine_now]++;
		// 如果当前工序的前一道工序已经执行完了，则直接在当前机器可以使用时间后加上当前工序所需时间；否则等待前一道工序完成后执行。
		if (machine_use_time[machine_now] >= pre_process_time[work_now])
		{
			work_process_start[work_now][process_now] = machine_use_time[machine_now];
			machine_use_time[machine_now] += process_to_use;
		}
		else
		{
			work_process_start[work_now][process_now] = pre_process_time[work_now];
			machine_use_time[machine_now] = pre_process_time[work_now] + process_to_use;
		}
		work_process_end[work_now][process_now] = machine_use_time[machine_now];
		pre_process_time[work_now] = machine_use_time[machine_now];
	}
	for (int m = 0; m < this->machine_num; m++)
	{
		cout << "M" << m << " ";
		for (int n = 0; n < this->workpiece_num; n++)
		{
			if (machine_work[m][n] != -1)
			{
				// 当前工件
				int work_now = machine_work[m][n];
				// 工件对应的工序
				int process_now = machine_process[m][n];
				// 开始时间
				int start = work_process_start[work_now][process_now];
				// 结束时间
				int end = work_process_end[work_now][process_now];
				cout << "(" << start << "," << work_now << "-" << process_now << "," << end << ") ";
			}
		}
		cout << endl;
	}
}

void Population::select()
{
	srand((int)time(NULL));
	int** chromosome_;
	chromosome_ = new int* [POPU_NUM];
	for (int i = 0; i < POPU_NUM; i++)
		chromosome_[i] = new int[this->chro_len];
	int opt_fitness;
	int n = 0;
	int popu_opt_fitness = MAX_INT;
	while (n < POPU_NUM)
	{
		opt_fitness = MAX_INT;
		for (int i = 0; i < GROUP; i++)
		{
			int r = rand() % (POPU_NUM + this->offspring_len);
			if (r >= POPU_NUM)
			{
				r %= POPU_NUM;
				if (this->offspring_fitness[r] < opt_fitness)
				{
					opt_fitness = this->offspring_fitness[r];
					memcpy(chromosome_[n], this->offspring_chromosome[r], sizeof(int) * this->chro_len);
				}
			}
			else
			{
				if (this->popu_fitness[r] < opt_fitness)
				{
					opt_fitness = this->popu_fitness[r];
					memcpy(chromosome_[n], this->chromosome[r], sizeof(int) * this->chro_len);
				}
			}
			popu_opt_fitness = popu_opt_fitness <= opt_fitness ? popu_opt_fitness : opt_fitness;
		}
		memcpy(this->chromosome[n], chromosome_[n], sizeof(int) * this->chro_len);
		n++;
	}
	this->optimal_fitness = popu_opt_fitness;
	this->offspring_len = 0;
}

int Population::getOptimalFitness()
{
	return this->optimal_fitness;
}

void Population::variation()
{
	srand((int)time(NULL));
	for (int i = 0; i < POPU_NUM + this->offspring_len; i++)
	{
		int prob = rand() % 100 + 1;
		if (prob <= VARIATION_PROB * 100)
		{
			int j = 0;
			while (j++ < 2)
			{
				int r = rand() % this->chro_len;
				int rr;
				while ((rr = rand() % this->chro_len) == r);
				if (i < POPU_NUM)
				{
					//this->is_variation[i] = 1;
					int temp = this->chromosome[i][r];
					this->chromosome[i][r] = this->chromosome[i][rr];
					this->chromosome[i][rr] = temp;
				}
				else
				{
					int temp = this->offspring_chromosome[i % POPU_NUM][r];
					this->offspring_chromosome[i % POPU_NUM][r] = this->offspring_chromosome[i % POPU_NUM][rr];
					this->offspring_chromosome[i % POPU_NUM][rr] = temp;
				}
			}
		}
	}
}

void Population::generate()
{
	srand((int)time(NULL));
	// 产生的子代数量
	int offspring_len_ = 0;
	for (int i = 0; i < POPU_NUM; i++)
	{
		int prob = rand() % 100 + 1;
		if (prob <= GENERATE_PROB * 100)
		{
			memcpy(this->offspring_chromosome[offspring_len_], this->chromosome[i], sizeof(int) * this->chro_len);

			// 1/2的概率保留染色体上半段或下半段
			int r = rand() % 2;
			int start = r * this->chro_len / 2;
			int end = start + (this->chro_len + 1) / 2;
			memset(this->offspring_chromosome[offspring_len_] + start, -1, sizeof(int) * (end - start));
			// 另一半段染色体重新打乱组合
			for (int j = start; j < end; j++)
			{
				int rr = rand() % (end - start);
				while (this->offspring_chromosome[offspring_len_][rr + start] != -1)
					rr = (rr + 1) % (end - start);
				this->offspring_chromosome[offspring_len_][rr + start] = this->chromosome[i][j];
			}
			offspring_len_++;
		}

	}
	this->offspring_len = offspring_len_;
}

void Population::printInfo()
{
	cout << "种群大小：" << POPU_NUM << endl;
	cout << "染色体长度：" << this->chro_len << endl;
	cout << "最优个体的适应度：" << this->optimal_fitness << endl;
	int offspring_len_ = 0;
	for (int i = 0; i < POPU_NUM + this->offspring_len; i++)
	{
		if (i < POPU_NUM)
		{
			cout << "第" << i + 1 << "个个体的适应度为：" << this->popu_fitness[i] << " 对应的染色体为：";
			for (int j = 0; j < this->chro_len; j++)
				cout << chromosome[i][j] << " ";
		}
		else
		{
			cout << "第" << i % POPU_NUM + 1 << "个子代个体的适应度为：" << this->offspring_fitness[i % POPU_NUM] << " 对应的染色体为：";
			for (int j = 0; j < this->chro_len; j++)
				cout << this->offspring_chromosome[i % POPU_NUM][j] << " ";
		}
		cout << endl;
	}
}

void Population::printIn()
{
	cout << "工件数：" << this->workpiece_num << endl;
	cout << "机器数：" << this->machine_num << endl;
	cout << "总工序数：" << this->chro_len << endl;
	for (int i = 0; i < this->workpiece_num; i++)
	{
		for (int j = 0; j < this->machine_num; j++)
			cout << work_machine[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < this->workpiece_num; i++)
	{
		for (int j = 0; j < this->machine_num; j++)
			cout << work_time[i][j] << " ";
		cout << endl;
	}
}

void Population::computeFitness()
{
	int optimal_fitness_ = MAX_INT;
	// 遍历整个种群
	for (int i = 0; i < POPU_NUM + this->offspring_len; i++)
	{
		int* work_;
		work_ = new int[this->workpiece_num];
		memcpy(work_, this->work, sizeof(int) * this->workpiece_num);
		// 每一台机器可以使用的时间
		int* machine_use_time;
		machine_use_time = new int[this->machine_num];
		memset(machine_use_time, 0, sizeof(int) * this->machine_num);
		// 每一个工件已经执行的工序中最后一道工序结束时间
		int* pre_process_time;
		pre_process_time = new int[this->workpiece_num];
		memset(pre_process_time, 0, sizeof(int) * this->workpiece_num);
		for (int j = 0; j < this->chro_len; j++)
		{
			// 当前工件号
			int work_now;
			if (i < POPU_NUM)
				work_now = this->chromosome[i][j] - 1;
			else
				work_now = this->offspring_chromosome[i % POPU_NUM][j] - 1;
			// 当前工序
			int process_now = this->work[work_now] - work_[work_now];
			work_[work_now]--;
			// 当前工序所需机器
			int machine_now = this->work_machine[work_now][process_now];
			// 当前工序所需时间
			int process_to_use = this->work_time[work_now][process_now];
			// 如果当前工序的前一道工序已经执行完了，则直接在当前机器可以使用时间后加上当前工序所需时间；否则等待前一道工序完成后执行。
			if (machine_use_time[machine_now] >= pre_process_time[work_now])
				machine_use_time[machine_now] += process_to_use;
			else
				machine_use_time[machine_now] = pre_process_time[work_now] + process_to_use;
			pre_process_time[work_now] = machine_use_time[machine_now];
		}
		int total_time = 0;
		// 保存所有个体的适应度
		for (int j = 0; j < this->machine_num; j++)
			total_time = machine_use_time[j] > total_time ? machine_use_time[j] : total_time;
		if (i < POPU_NUM)
			this->popu_fitness[i] = total_time;
		else
			this->offspring_fitness[i % POPU_NUM] = total_time;
		optimal_fitness_ = total_time < optimal_fitness_ ? total_time : optimal_fitness_;
	}
	// 更新种群的最优个体的适应度
	this->optimal_fitness = optimal_fitness_;
}

void Population::Initial()
{
	// 初始化父代染色体和子代染色体
	this->chromosome = new int* [POPU_NUM];
	this->offspring_chromosome = new int* [POPU_NUM];
	for (int i = 0; i < POPU_NUM; i++)
	{
		this->chromosome[i] = new int[this->chro_len];
		this->offspring_chromosome[i] = new int[this->chro_len];
	}
	this->offspring_len = 0;
	int* work_;
	work_ = new int[this->workpiece_num];
	srand((int)time(NULL));
	for (int i = 0; i < POPU_NUM; i++)
	{
		memcpy(work_, this->work, sizeof(int) * this->workpiece_num);
		for (int j = 0; j < this->chro_len; j++)
		{
			int r = rand() % this->workpiece_num;
			if (work_[r] > 0)
			{
				this->chromosome[i][j] = r + 1;
				work_[r]--;
			}
			else
			{
				int r_ = 0;
				while (work_[r] == 0)
				{
					if (r_ == this->workpiece_num)
					{
						cout << "error!" << endl;
						exit(0);
					}
					r = (r + 1) % this->workpiece_num;
					r_++;
				}
				this->chromosome[i][j] = r + 1;
				work_[r]--;
			}
		}
	}
	delete[] work_;
	this->popu_fitness = new int[POPU_NUM];
	memset(this->popu_fitness, 0, sizeof(int) * POPU_NUM);
	this->offspring_fitness = new int[POPU_NUM];
	memset(this->offspring_fitness, 0, sizeof(int) * POPU_NUM);
	this->optimal_fitness = 0;

}

/*
构造函数，构造种群及其大小
*/
Population::Population(char* file_name)
{
	ifstream infile;
	infile.open(file_name, ios::in);
	if (!infile.is_open())
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	this->chro_len = 0;
	char buf[BUF_SIZE];
	infile.getline(buf, sizeof(buf));
	char* token = strtok(buf, " ");
	// 获取工件的数量及工序的数量
	this->workpiece_num = atoi(token);
	this->machine_num = atoi(strtok(NULL, " "));
	// 记录每个工件对应的工序数
	this->work = new int[workpiece_num];
	memset(this->work, 0, sizeof(int) * this->workpiece_num);
	// 记录每个工件的每道工序所需的时间及机器
	this->work_time = new int* [this->workpiece_num];
	this->work_machine = new int* [this->workpiece_num];
	for (int i = 0; i < this->workpiece_num; i++)
	{
		this->work_time[i] = new int[this->machine_num];
		memset(this->work_time[i], -1, sizeof(int) * this->machine_num);
		this->work_machine[i] = new int[this->machine_num];
		memset(this->work_machine[i], -1, sizeof(int) * this->machine_num);
	}
	int i = 0;
	while (infile.getline(buf, sizeof(buf)))
	{
		int j = 0;
		while (true)
		{
			if (j == 0)
				token = strtok(buf, " ");
			else
				token = strtok(NULL, " ");
			if (token == NULL)
				break;
			this->work_machine[i][j] = atoi(token);
			this->work_time[i][j] = atoi(strtok(NULL, " "));
			this->chro_len++;
			this->work[i]++;
			j++;
		}
		i++;
	}
	infile.close();
}

/*
析构函数，释放内存
*/
Population::~Population()
{
	for (int i = 0; i < this->workpiece_num; i++)
	{
		delete[] this->work_time[i];
		delete[] this->work_machine[i];
	}
	delete[] this->work_time;
	delete[] this->work_machine;
	for (int i = 0; i < POPU_NUM; i++)
		delete[] this->chromosome[i];
	delete[] this->chromosome;
	delete[] this->work;
}
#endif // !_HEREDITY_H_
