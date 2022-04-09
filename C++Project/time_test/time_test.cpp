// time_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
//编写停车场管理程序
#include<iostream>
#include<time.h>
#include<string.h>
using namespace std;
#define MaxSize 5
//车辆信息
typedef struct
{
	char* timeIn;
	char* timeOut;
	char no[10];
}ElemType;
//停放栈 或者有车需要出场时的让路栈
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
//排队等候序列
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitStack(SqStack*& s)
{
	s = (SqStack*) new SqStack;
	s->top = -1;
}
void DestroyStack(SqStack*& s)
{
	delete(s);
}
bool StackEmpty(SqStack* s)
{
	return s->top == -1;
}
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	s->data[s->top].timeIn = e.timeIn;
	s->data[s->top].timeOut = e.timeOut;
	return true;
}
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
void DestroyQueue(SqQueue*& q)
{
	free(q);
}
bool QueueEmpty(SqQueue* q)
{
	return (q->front == q->rear);
}
//进队列
bool enQueue(SqQueue*& q, ElemType e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
//出队列
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
//车辆入场
void Show_Car(SqStack*& stopping, SqQueue*& waiting)
{
	if (!StackEmpty(stopping))
	{
		int i = 0;
		cout << "在场停放车辆详情如下：" << endl;
		for (;i <= stopping->top;i++)
		{
			cout << "车牌号：" << stopping->data[i].no << "\t入场时间：" << stopping->data[i].timeIn << endl;
		}
	}
	if (!QueueEmpty(waiting))
	{
		cout << "在排队等候车辆详情如下：" << endl;
		for (int i = 0;i <= waiting->rear - waiting->front;i++)
		{
			cout << "车牌号：" << waiting->data[i].no << endl << "\t";
		}
		cout << endl;
	}
}
void Car_Entry(SqStack*& stopping, SqQueue*& waiting)
{
	ElemType car;
	car.timeIn = (char*)malloc(sizeof(char));
	car.timeOut = (char*)malloc(sizeof(char));
	time_t timeIn;
	time(&timeIn);	//入场时间
	car.timeIn = ctime(&timeIn);
	cout << "before if timeIn:" << car.timeIn;
	cout << "输入车牌号：";
	cin >> car.no;
	if (stopping->top == MaxSize - 1)
	{
		cout << "暂无空车位，请在等候区排队等候！" << endl;
		enQueue(waiting, car);
	}
	else
	{
		Push(stopping, car);
		cout << car.no << " 欢迎入场！" << endl;
		cout << "入场时间：" << car.timeIn << endl;
	}
}
//车辆出场
void Car_Exit(SqStack*& stopping, SqQueue*& waiting)
{
	SqStack* helping;
	InitStack(helping);
	char  exit_no[10];
	bool find = false;
	ElemType car;
	cout << "请输入要出场的车牌号：";
	cin >> exit_no;

	//查找要出场的车辆，找到之前退栈并进入helping栈，找到后直接从stopping中出栈
	while (!find && !StackEmpty(stopping))
	{
		if (strcmp(stopping->data[stopping->top].no, exit_no) != 0)
		{
			Pop(stopping, car);
			Push(helping, car);
		}
		else
		{
			find = true;
			time_t timeOut;			//记录出场时间
			time(&timeOut);
			stopping->data[stopping->top].timeOut = ctime(&timeOut);
			Pop(stopping, car);
			cout << "车牌号:" << car.no << endl << "入场时间：" << car.timeIn << "出场时间: " << car.timeOut << endl;
			break;
		}
	}
	//让路栈的汽车重新进栈stopping
	ElemType en_car;
	while (!StackEmpty(helping))
	{
		Pop(helping, en_car);
		Push(stopping, en_car);
	}
	//等候队列中的第一个出队列，并进栈
	if (!QueueEmpty(waiting))
	{
		deQueue(waiting, en_car);
		Push(stopping, en_car);
	}
}
//在场车辆停放详情

void Menu(SqStack*& stopping, SqQueue*& waiting)
{
	char choice = '\0';

	do {
		cout << "               *************目前停车场车位状况************" << endl;
		cout << "               停车场一共" << MaxSize << "个车位，当前停有" << stopping->top + 1 << "辆车,";
		cout << "等候区有" << waiting->rear - waiting->front << "辆车" << endl;
		cout << "               *******************************************" << endl;
		cout << "               1.车辆入场" << endl;
		cout << "               2.车辆出场" << endl;
		cout << "               3.停放车辆详情" << endl;
		cout << "               4.退出" << endl;
		cout << "               请输入功能序号：";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Car_Entry(stopping, waiting);
			break;
		case '2':
			Car_Exit(stopping, waiting);
			break;
		case '3':
			Show_Car(stopping, waiting);
		}
	} while (choice != '4');
}
int main()
{
	SqStack* stopping;
	SqQueue* waiting;
	InitStack(stopping);
	//InitStack(helping);
	InitQueue(waiting);

	time_t test;
	time(&test);

	Menu(stopping, waiting);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
