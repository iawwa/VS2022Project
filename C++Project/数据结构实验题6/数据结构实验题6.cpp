// 数据结构实验题6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#define MaxSize 5
typedef struct
{
    int num[MaxSize];
    int front, rear;
}SqQueue;
void Queue(SqQueue *&q,int e)
{      
    
    q->rear = (q->rear + 1) % MaxSize;
    q->num[q->rear] = e;
}
void Pop(SqQueue *&q,int &e)
{
    
    e = q->num[q->front];
    q->front = (q->front + 1) % MaxSize;
};
void Display(SqQueue *q)
{
    int i = q->front;
    if (q->rear >= q->front)
    {
        while (i <= q->rear)
        {
            cout << q->num[i]<<" ";
            i++;
        }
    }
    else
    {
        while (i<MaxSize)
        {
            cout << q->num[i]<<" ";
            i++;
        }
        i = 0;
        while (i <= q->rear)
        {
            cout << q->num[i]<<" ";
            i++;
        }
    }
    cout << endl;
}
void Finish(SqQueue*& q) 
{
    //q->front++;
    if (q->rear >= q->front)
    {
        while (q->front<=q->rear)
        {
            cout << q->num[q->front] << " ";
            q->front++;
        }
    }
    else
    {
        while (q->front < MaxSize)
        {
            cout << q->num[q->front] << " ";
            q->front++;
        }
        q->front = 0;
        while (q->front <= q->rear)
        {
            cout << q->num[q->front] << " ";
            q->front++;
        }
    }
    cout << endl;
    free(q);
}
void Menu()
{
    SqQueue* q;
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = 0;
    q->rear = -1;
    while (true)
    {
        int m;
        cout << "1:排队--输入排队病人的病历号，加入到病人排队队列中；" << endl;
        cout << "2:就诊 --病人排队队列中最前面的病人就诊，并将其从队列中删除； "<<endl;
        cout << "3：查看排队--从队首到队尾列出所有的排队病人的病历号；"<<endl;
        cout << "4：不在排队，余下依次就诊--从队首到队尾列出所有的排队病人的病历号，并退出运行。"<<endl;
        cout << "5：下班--退出运行。"<<endl;
        cout << "输入你的操作序号：" << endl;
        cin >> m;
        if (m == 1) 
        {
            cout << "输入病历号:";
            cin >> m;
            Queue(q,m);
        }
        else if (m == 2) { Pop(q, m); }
        else if (m == 3) { Display(q); }
        else if (m == 4) { Finish(q); }
        else if (m == 5) { break; }
        else { continue; }
    }
}
int main()
{
    Menu();
    system("pause");
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
