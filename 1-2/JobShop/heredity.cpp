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
			cout << "���ŵĸ���Ⱦɫ��Ϊ��";
			for (int j = 0; j < this->chro_len; j++)
				cout << this->chromosome[i][j] << " ";
			cout << endl;
			break;
		}
		i++;
	}
	// ÿ̨�����Ϲ����Ĺ���������
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
	// ÿ��������Ӧ�Ĺ�����
	int* work_;
	work_ = new int[this->workpiece_num];
	memcpy(work_, this->work, sizeof(int) * this->workpiece_num);
	// ÿһ̨��������ʹ�õ�ʱ��
	int* machine_use_time;
	machine_use_time = new int[this->machine_num];
	memset(machine_use_time, 0, sizeof(int) * this->machine_num);
	// ÿһ�������Ѿ�ִ�еĹ��������һ���������ʱ��
	int* pre_process_time;
	pre_process_time = new int[this->workpiece_num];
	memset(pre_process_time, 0, sizeof(int) * this->workpiece_num);
	// ÿһ�������Ĺ���Ŀ�ʼ������ʱ��
	int** work_process_start, ** work_process_end;
	work_process_start = new int* [this->workpiece_num];
	work_process_end = new int* [this->workpiece_num];
	for (int j = 0; j < this->workpiece_num; j++)
	{
		work_process_start[j] = new int[this->machine_num];
		work_process_end[j] = new int[this->machine_num];
	}
	// ����ִ��˳��
	int* machine_exec;
	machine_exec = new int[this->machine_num];
	memset(machine_exec, 0, sizeof(int) * this->machine_num);
	for (int j = 0; j < this->chro_len; j++)
	{
		// ��ǰ������
		int work_now = this->chromosome[i][j] - 1;
		// ��ǰ����
		int process_now = this->work[work_now] - work_[work_now];
		work_[work_now]--;
		// ��ǰ�����������
		int machine_now = this->work_machine[work_now][process_now];
		// ��ǰ��������ʱ��
		int process_to_use = this->work_time[work_now][process_now];
		machine_work[machine_now][machine_exec[machine_now]] = work_now;
		machine_process[machine_now][machine_exec[machine_now]] = process_now;
		machine_exec[machine_now]++;
		// �����ǰ�����ǰһ�������Ѿ�ִ�����ˣ���ֱ���ڵ�ǰ��������ʹ��ʱ�����ϵ�ǰ��������ʱ�䣻����ȴ�ǰһ��������ɺ�ִ�С�
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
				// ��ǰ����
				int work_now = machine_work[m][n];
				// ������Ӧ�Ĺ���
				int process_now = machine_process[m][n];
				// ��ʼʱ��
				int start = work_process_start[work_now][process_now];
				// ����ʱ��
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
	// �������Ӵ�����
	int offspring_len_ = 0;
	for (int i = 0; i < POPU_NUM; i++)
	{
		int prob = rand() % 100 + 1;
		if (prob <= GENERATE_PROB * 100)
		{
			memcpy(this->offspring_chromosome[offspring_len_], this->chromosome[i], sizeof(int) * this->chro_len);

			// 1/2�ĸ��ʱ���Ⱦɫ���ϰ�λ��°��
			int r = rand() % 2;
			int start = r * this->chro_len / 2;
			int end = start + (this->chro_len + 1) / 2;
			memset(this->offspring_chromosome[offspring_len_] + start, -1, sizeof(int) * (end - start));
			// ��һ���Ⱦɫ�����´������
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
	cout << "��Ⱥ��С��" << POPU_NUM << endl;
	cout << "Ⱦɫ�峤�ȣ�" << this->chro_len << endl;
	cout << "���Ÿ������Ӧ�ȣ�" << this->optimal_fitness << endl;
	int offspring_len_ = 0;
	for (int i = 0; i < POPU_NUM + this->offspring_len; i++)
	{
		if (i < POPU_NUM)
		{
			cout << "��" << i + 1 << "���������Ӧ��Ϊ��" << this->popu_fitness[i] << " ��Ӧ��Ⱦɫ��Ϊ��";
			for (int j = 0; j < this->chro_len; j++)
				cout << chromosome[i][j] << " ";
		}
		else
		{
			cout << "��" << i % POPU_NUM + 1 << "���Ӵ��������Ӧ��Ϊ��" << this->offspring_fitness[i % POPU_NUM] << " ��Ӧ��Ⱦɫ��Ϊ��";
			for (int j = 0; j < this->chro_len; j++)
				cout << this->offspring_chromosome[i % POPU_NUM][j] << " ";
		}
		cout << endl;
	}
}

void Population::printIn()
{
	cout << "��������" << this->workpiece_num << endl;
	cout << "��������" << this->machine_num << endl;
	cout << "�ܹ�������" << this->chro_len << endl;
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
	// ����������Ⱥ
	for (int i = 0; i < POPU_NUM + this->offspring_len; i++)
	{
		int* work_;
		work_ = new int[this->workpiece_num];
		memcpy(work_, this->work, sizeof(int) * this->workpiece_num);
		// ÿһ̨��������ʹ�õ�ʱ��
		int* machine_use_time;
		machine_use_time = new int[this->machine_num];
		memset(machine_use_time, 0, sizeof(int) * this->machine_num);
		// ÿһ�������Ѿ�ִ�еĹ��������һ���������ʱ��
		int* pre_process_time;
		pre_process_time = new int[this->workpiece_num];
		memset(pre_process_time, 0, sizeof(int) * this->workpiece_num);
		for (int j = 0; j < this->chro_len; j++)
		{
			// ��ǰ������
			int work_now;
			if (i < POPU_NUM)
				work_now = this->chromosome[i][j] - 1;
			else
				work_now = this->offspring_chromosome[i % POPU_NUM][j] - 1;
			// ��ǰ����
			int process_now = this->work[work_now] - work_[work_now];
			work_[work_now]--;
			// ��ǰ�����������
			int machine_now = this->work_machine[work_now][process_now];
			// ��ǰ��������ʱ��
			int process_to_use = this->work_time[work_now][process_now];
			// �����ǰ�����ǰһ�������Ѿ�ִ�����ˣ���ֱ���ڵ�ǰ��������ʹ��ʱ�����ϵ�ǰ��������ʱ�䣻����ȴ�ǰһ��������ɺ�ִ�С�
			if (machine_use_time[machine_now] >= pre_process_time[work_now])
				machine_use_time[machine_now] += process_to_use;
			else
				machine_use_time[machine_now] = pre_process_time[work_now] + process_to_use;
			pre_process_time[work_now] = machine_use_time[machine_now];
		}
		int total_time = 0;
		// �������и������Ӧ��
		for (int j = 0; j < this->machine_num; j++)
			total_time = machine_use_time[j] > total_time ? machine_use_time[j] : total_time;
		if (i < POPU_NUM)
			this->popu_fitness[i] = total_time;
		else
			this->offspring_fitness[i % POPU_NUM] = total_time;
		optimal_fitness_ = total_time < optimal_fitness_ ? total_time : optimal_fitness_;
	}
	// ������Ⱥ�����Ÿ������Ӧ��
	this->optimal_fitness = optimal_fitness_;
}

void Population::Initial()
{
	// ��ʼ������Ⱦɫ����Ӵ�Ⱦɫ��
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
���캯����������Ⱥ�����С
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
	// ��ȡ���������������������
	this->workpiece_num = atoi(token);
	this->machine_num = atoi(strtok(NULL, " "));
	// ��¼ÿ��������Ӧ�Ĺ�����
	this->work = new int[workpiece_num];
	memset(this->work, 0, sizeof(int) * this->workpiece_num);
	// ��¼ÿ��������ÿ�����������ʱ�估����
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
�����������ͷ��ڴ�
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
