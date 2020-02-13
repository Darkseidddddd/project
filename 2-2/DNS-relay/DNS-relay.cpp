#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <thread>
#include <time.h>
#include <iostream>
#include <fstream>

//using namespace std;
#define THREAD_POOL 10
#define BUF_SIZE 1024
#define NAME_SIZE 30
#define A 1
#define CNAME 5

typedef struct {
	unsigned short id; //会话标识
	unsigned char qr; //  查询/响应标志，0为查询，1为响应
	unsigned char opcode;
	unsigned char aa; //  表示授权回答
	unsigned char tc; // 表示可截断的 
	unsigned char rd; // 表示期望递归
	unsigned char ra; // 表示可用递归
	unsigned char z; //保留值
	unsigned char rcode; //应答码
	//unsigned char cd : 1;
	//unsigned char ad : 1;
	unsigned short q_count; // 表示查询问题区域节的数量 
	unsigned short ans_count; // 表示回答区域的数量
	unsigned short auth_count; // 表示授权区域的数量
	unsigned short add_count; // 表示附加区域的数量
} DNS_HEADER;

/*
**DNS报文中查询问题区域
*/
typedef struct {
	unsigned char *name;
	unsigned short qtype;//查询类型
	unsigned short qclass;//查询类
} DNS_QUESTION;

typedef struct {
	unsigned char *name;
	DNS_QUESTION *ques;
} QUERY;

/*
**DNS报文中回答区域的常量字段
*/
//编译制导命令
#pragma pack(push, 1)//保存对齐状态，设定为1字节对齐
struct R_DATA {
	unsigned short type; //表示资源记录的类型
	unsigned short _class; //类
	unsigned int ttl; //表示资源记录可以缓存的时间
	unsigned short data_len; //数据长度
};
#pragma pack(pop) //恢复对齐状态

/*
**DNS报文中回答区域的资源数据字段
*/
typedef struct {
	unsigned char *name;//资源记录包含的域名
	unsigned short type; //表示资源记录的类型
	unsigned short _class; //类
	unsigned int ttl; //表示资源记录可以缓存的时间
	unsigned short data_len; //数据长度
	char *rdata;
} RES_RECORD;

class Packet
{
public:
	DNS_HEADER *header;
	DNS_QUESTION *question;
	RES_RECORD *record;
public:
	Packet();
	void getDNSHEADER(char *buf);
	void getDNSQUESTION(char *buf);
	char *getDNAME();
	void getDNSANSWER(char *buf);

	void printDNSHEADER();
	void printDNSQUESTION();
};

Packet::Packet()
{
	header = new DNS_HEADER;
	question = new DNS_QUESTION;
	record = new RES_RECORD;
}

void Packet::printDNSHEADER()
{
	//printf("id = %d\n", header->id);
	
	printf("qr = %d\n", header->qr);
	printf("opcode = %d\n", header->opcode);
	printf("aa = %d\n", header->aa);
	printf("tc = %d\n", header->tc);
	printf("rd = %d\n", header->rd);
	printf("ra = %d\n", header->ra);
	printf("z = %d\n", header->z);
	printf("rcode = %d\n", header->rcode);
	printf("qdcount = %d\n", header->q_count);
	printf("ancount = %d\n", header->ans_count);
	printf("nscount = %d\n", header->auth_count);
	printf("arcount = %d\n", header->add_count);
}

void Packet::printDNSQUESTION()
{
	if (question->qtype == 1)
		printf("qtype = A\n");
	else if (question->qtype == 28)
		printf("qtype = AAAA\n");
	else if (question->qtype == 5)
		printf("qtype = CNAME\n");
	printf("qclass = IN\n", question->qclass);
}

void Packet::getDNSHEADER(char *buf)
{
	unsigned short *ptr = (unsigned short*)buf;
	//获取id
	header->id = htons(*ptr);
	//printf("id = %d-%d\n", htons(*ptr), ntohs(*ptr));
	//获取flag
	unsigned short flag = htons(*(++ptr));
	header->qr = (unsigned char)((flag & 0x8000) >> 15);
	header->opcode = (unsigned char)((flag & 0x7000) >> 11);
	header->aa = (unsigned char)((flag & 0x0400) >> 10);
	header->tc = (unsigned char)((flag & 0x0200) >> 9);
	header->rd = (unsigned char)((flag & 0x0100) >> 8);
	header->ra = (unsigned char)((flag & 0x0080) >> 7);
	header->z = (unsigned char)((flag & 0x0070) >> 4);
	header->rcode = (unsigned char)(flag & 0x000f);
	header->q_count = htons(*(ptr + 1));
	header->ans_count = htons(*(ptr + 2));
	header->auth_count = htons(*(ptr + 3));
	header->add_count = htons(*(ptr + 4));
}

void Packet::getDNSQUESTION(char *buf)
{
	unsigned short *ptr = (unsigned short*)buf;
	question->name = (unsigned char*)(ptr + 6);
	unsigned char *ptr_ = (unsigned char*)(ptr + 6);
	int i = 0;
	while (question->name[i++] != 0);
	question->qtype = htons(*(unsigned short*)(ptr_ + i));
	question->qclass = htons(*(unsigned short*)(ptr_ + i + 2));
}

char *Packet::getDNAME()
{
	char *dname;
	dname = new char[NAME_SIZE];
	int i = 0;
	while (question->name[i] != 0) {
		if (question->name[i] <= 30 && question->name[i] > 0 && i != 0)
			dname[i-1] = '.';
		else
			dname[i-1] = question->name[i];
		i++;
	}
	dname[i-1] = '\0';
	return dname;
}

void Packet::getDNSANSWER(char *buf)
{
	unsigned short *ques = (unsigned short*)buf + 6;
	unsigned char *ques_ = (unsigned char*)ques;
	int i = 0;
	while (ques_[i++]);
	unsigned short *qtype = (unsigned short*)(ques_ + i);
	unsigned short *ans = qtype + 2;
	unsigned short *ans_type = ans + 1;
	unsigned short ans_type_ = htons(*ans_type);
	if (ans_type_ == A) {
		unsigned int *ans_ip = (unsigned int*)(ans_type + 5);
		struct in_addr addr;
		memcpy(&addr, ans_ip, 4);
		printf("addr = %s\n", inet_ntoa(addr));
	} else if (ans_type_ == CNAME){
		unsigned short *len = ans_type + 4;
		//printf("len = %d\n", htons(*len));
		unsigned char *rdata = (unsigned char*)(len + 1);
		unsigned short *ans2 = (unsigned short*)(rdata + htons(*len));
		//unsigned short *ans2_len = (unsigned short*)(ans2 + 6);
		//printf("ans2_len = %d\n", htons(*ans2_len));
		unsigned int *ans2_ip = (unsigned int*)(ans2 + 6);
		//printf("ip = %d\n", *ans2_ip);
		struct in_addr addr;
		memcpy(&addr, ans2_ip, 4);
		//printf("addr = %s\n", inet_ntoa(addr));
		record->rdata = new char[4];
		strcpy(record->rdata, inet_ntoa(addr));
	}
	//record->name = new unsigned char[NAME_SIZE];
}

class dnsrelay
{
public:
	int length;
	char **domain;
	char **ip;
public:
	dnsrelay();
	void loadDNSRELAY(char *fileName);
	void printDNSRELAY();
	char *searchIP(char *dname);
	void addDNSRELAY(char *new_dname, char *new_ip);
};

dnsrelay::dnsrelay()
{
	domain = new char*[400];
	ip = new char*[400];
	for (int j = 0; j < 400; j++) {
		domain[j] = new char[50];
		ip[j] = new char[50];
	}
}

void dnsrelay::loadDNSRELAY(char *fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (file.is_open()) {
		char line[BUF_SIZE];
		int i = 0;
		while (file.getline(line, BUF_SIZE)) {
			strcpy(ip[i], strtok(line, " "));
			strcpy(domain[i++], strtok(NULL, " "));
		}
		//domain[i][0] = '\0';
		//ip[i][0] = '\0';
		length = i;
		file.close();
		printf("Load successfully\n");
	}
}

void dnsrelay::printDNSRELAY()
{
	int i;
	for (i = 0; i < length; i++) {
		std::cout << ip[i] << " " << domain[i] << std::endl;
	}
}

char *dnsrelay::searchIP(char *dname) 
{
	int i;
	for (i = 0; i < length; i++) {
		if (!strcmp(domain[i], dname))
			return ip[i];
	}
	return NULL;
}

void dnsrelay::addDNSRELAY(char *new_dname, char *new_ip)
{
	strcpy(domain[length], new_dname);
	strcpy(ip[length++], new_ip);
	//domain[length][0] = '\0';
	//ip[length][0] = '\0';
}

void modifyDNSHEADER1(unsigned short *buf)
{
	*(buf + 1) = htons(0x8183);		//1000 0000 1000 0011
	*(buf + 2) = htons(0x0001);		//0000 0000 0000 0001
	*(buf + 3) = htons(0x0000);
	*(buf + 4) = htons(0x0001);
}

void modifyDNSHEADER2(unsigned short *buf)
{
	*(buf + 1) = htons(0x8180);		//1000 0000 1000 0000
	*(buf + 2) = htons(0x0001);		//0000 0000 0000 0001
	*(buf + 3) = htons(0x0001);
	*(buf + 4) = htons(0x0000);
}

void modifyDNSANSWER(unsigned short *buf, char *ip)
{
	//unsigned char* query = (unsigned char*)((unsigned short*)&buf + 6);
	unsigned short *ptr = (unsigned short*)buf;
	unsigned char *query = (unsigned char*)(ptr + 6);
	int i = 0;
	while (query[i++]);
	unsigned short *ptr_ = (unsigned short*)(query + i);
	unsigned short *ans = ptr_ + 2;
	*ans = htons(0xc00c);		//1100 0000 0000 1100 高两位为1，偏移12，指向query的域名
	*(ans + 1) = htons(0x0001);
	*(ans + 2) = htons(0x0001);
	unsigned int *ttl = (unsigned int*)(ans + 3);
	*ttl = htons(0x000000ff);
	unsigned short *rdlength = (unsigned short*)(ttl + 1);
	*rdlength = htons(0x0004);
	unsigned int *rdata = (unsigned int*)(rdlength + 1);
	//std::cout << ip << std::endl;
	//printf("addr = %d\n", inet_addr(ip));
	*rdata = inet_addr(ip);
	//printf("addr = %d\n", *rdata);
}

void printTime()
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	printf("%d:%d:%d\n", 8 + p->tm_hour, p->tm_min, p->tm_sec);
}

void printInfo(int argc, char **argv, class Packet dns_packet)
{
	if (argc >= 2) {
		printTime();
		printf("id = %d\n", dns_packet.header->id);
		if (!strcmp(argv[1], "-dd")) {
			dns_packet.printDNSHEADER();
			dns_packet.printDNSQUESTION();
		}
		char *dname = dns_packet.getDNAME();
		std::cout << "Domain: " << dname << std::endl;
	}
}

void DNS(SOCKET arg, SOCKADDR_IN client_addr, int argc, char **argv)
{
	char *ip, *fileName;
	ip = new char[30];
	fileName = new char[30];
	strcpy(ip, "10.3.9.5");
	strcpy(fileName, "dnsrelay.txt");
	if (argc > 2) {
		strcpy(ip, argv[2]);
	}
	std::cout << "名字服务器为: " << ip << std::endl;
	if (argc > 3) {
		strcpy(fileName, argv[3]);
	}
	std::cout << "配置文件为: " << fileName << std::endl;
	//printf("thread: %d\n", pos);
	
	SOCKET destSvr = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN dest;
	dest.sin_family = AF_INET;
	dest.sin_port = htons(53);
	inet_pton(AF_INET, ip, &dest.sin_addr);
	int len = sizeof(sockaddr);
	bind(destSvr, (struct sockaddr*)&dest, len);

	char recvBuf[BUF_SIZE];
	int sockConn = arg;
	int i = 0;
	
	class Packet dns_packet;
	struct QUESTION *qinfo = NULL;

	class dnsrelay dns_relay;
	dns_relay.loadDNSRELAY(fileName);
	//dns_realy.printDNSRELAY();
	/*
	char *temp;
	temp = new char[30];
	strcpy(temp, "bupt");
	char *temp2 = dns_realy.searchIP(temp);
	std::cout << temp2 << std::endl;
	*/
	
	while (true)
	{
		// 从客户端接收消息
		//printf("wait receive client message[%d] :\n", i++);
		int d = sizeof(dest);
		//printf("wait 1\n");
		int ret1 = recvfrom(sockConn, recvBuf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, &len);
		//printf("get 1\n");
		//int ret2 = recvfrom(sockConn, recvBuf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, &len);
		dns_packet.getDNSHEADER(recvBuf);
		dns_packet.getDNSQUESTION(recvBuf);

		printInfo(argc, argv, dns_packet);

		char *dname = dns_packet.getDNAME();
		char *send_ip = dns_relay.searchIP(dname);
		printf("type = %d\n", dns_packet.question->qtype);
		if (send_ip && dns_packet.question->qtype == 1) {
			if (!strcmp(send_ip, "0.0.0.0")) {
				printf("拦截域名\n");
				unsigned short *buf;
				buf = (unsigned short*)&recvBuf;
				modifyDNSHEADER1(buf);
				//unsigned short *temp = (unsigned short*)&recvBuf + 1;
				//*temp = htons(0x8183);
				modifyDNSANSWER(buf, send_ip);
				char *sendbuf = recvBuf;
				sendto(sockConn, (char*)sendbuf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, len);
			} else {
				printf("本地域名\n");
				//std::cout << send_ip << std::endl;
				unsigned short *buf;
				buf = (unsigned short*)&recvBuf;
				modifyDNSHEADER2(buf);
				modifyDNSANSWER(buf, send_ip);
				char *sendbuf = recvBuf;
				sendto(sockConn, (char*)sendbuf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, len);
			}
		} else {
			printf("中继\n");
			//dns_packet.printDNSHEADER();
			//dns_packet.printDNSQUESTION();

			//printf("dname = %s\n", dname);
			
			char ipClient[16];
			inet_ntop(AF_INET, &client_addr.sin_addr, ipClient, sizeof(ipClient));
			//printf("%s said\n", ipClient);

			char *buf = recvBuf;

			sendto(destSvr, (char*)buf, BUF_SIZE, 0, (struct sockaddr*)&dest, d);
			//int r1 = recvfrom(sockConn, recvBuf, BUF_SIZE, 0, (struct sockaddr*)&dest, &d);
			//int r1 = recvfrom(sockConn, recvBuf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, &len);
			//printf("r1 = %d\n", r1);
			//printf("wait 2\n");
			int r2 = recvfrom(destSvr, recvBuf, BUF_SIZE, 0, (struct sockaddr*)&dest, &d);
			//printf("get 2\n");
			//printf("r2 = %d\n", r2);
			dns_packet.getDNSHEADER(recvBuf);
			dns_packet.getDNSANSWER(recvBuf);
			//if (dns_packet.header->rcode == 0)
				//dns_relay.addDNSRELAY(dname, dns_packet.record->rdata);

			//printf("get_ip = %s\n", dns_packet.record->rdata);
			//dns_packet.printDNSHEADER();
			
			char *sendbuf = recvBuf;
			sendto(sockConn, (char*)sendbuf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, len);
			// 解析客户端地址信息

			// 向客户端发送消息
			//gets_s(sendBuf);
			//sendto(sockConn, sendBuf, strlen(sendBuf) + 1, 0, (struct sockaddr*)&client_addr, len);
		
		}
	}
}

int main(int argc, char **argv)
{
	/**********************************************************************/
	/*
	WSAStartup必须是应用程序或DLL调用的第一个Windows Sockets函数。
	它允许应用程序或DLL指明Windows Sockets API的版本号及获得特定Windows Sockets实现的细节。
	应用程序或DLL只能在一次成功的WSAStartup()调用之后才能调用进一步的Windows Sockets API函数。
	*/
	//printf("argc = %d", argc);
	//std::cout << *argv << std::endl;
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) { return 0; }

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		WSACleanup();
		return 0;
	}
	/***********************************************************************/

	// 申请存储线程的数组
	std::thread threads[THREAD_POOL];
	int thread_num = 0;

	/***********************************************************************/
	/*                        socket通讯                                   */
	// 申请套接字
	SOCKET Svr = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addr;

	// 要绑定的基础信息
	addr.sin_family = AF_INET;
	addr.sin_port = htons(53);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  //自动获取IP地址

	// 进行绑定
	int len = sizeof(sockaddr);
	bind(Svr, (struct sockaddr*)&addr, len);

	SOCKADDR_IN addrClient;

	threads[thread_num++] = std::thread(DNS, Svr, addrClient, argc, argv);
	//threads[thread_num++] = std::thread(DNS, Svr, addrClient, thread_num);
	//thread_num++;

	for (int i = 0; i < thread_num; i++)
		threads[i].join();
	//DNS(Svr, 1);
	closesocket(Svr);
	WSACleanup();
	return 0;
}
