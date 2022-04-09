// 停车场.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define n 20

//class Car 

typedef struct
{
    int car[n];
    int top;
}P;

typedef struct 
{
    int car[n];
    int f,h;
}R;

void AddR(R *&r,int e) 
{
    r->h = (r->h + 1) % n;
    r->car[r->h] = e;
}

void PopR(R *&r)
{
    
    r -> h--;
    if (r < 0)
    {
        r = r + 20;
    }
}

void DoR(R*& r) 
{
    r->f++;
    if (r->f > n - 1)
    {
        r->f = r->f - n;
    }
}

void AddP(P*& p,int e)
{
    if (p->top < n - 1)
    {
        p->top++;
        p->car[p->top] = e;
    }
}

void PopP(P*& p)
{
    if (p->top > -1)
    {
        p->top--;
    }
}

void RtoP(P*& p,int m, R*& r)
{
    while (m > 0)
    {
        AddP(p,r->car[r->h]);
        r->h--;
        if (r < 0)
        {
            r = r + 20;
        }
        m--;
    }
    
}

int PtoR(P *&p,int m,R *&r) 
{
    int num=0;
    while (p->top != m - 1)
    {
        AddR(r, p->car[p->top]);
        p->top--;
        num++;
    }
    return num;
}

void Dis_P(P *&p)
{
    int i = p->top;
    cout << "停车场情况：";
    while (i != -1) 
    {
        cout << p->car[i]<<" ";
        i--;
    }
    cout << endl;
}

void Cont() 
{
    P* p;
    int m;
    p = (P*)malloc(sizeof(P));
    p->top = -1;
    R* r;
    r = (R*)malloc(sizeof(R));
    r->f =r->h= 0;

    while (true) 
    {
        cout << "输入你想要的演示:" << endl;
        cout << "1:车进停车场:" << endl;
        cout << "2:停车场出指定车：" << endl;
        cout << "3:车进候车道" << endl;
        cout << "4：停车场最外面出车" << endl;
        cout << "5：便道后方出车" << endl;
        cout << "6：便道前出车" << endl;
        cout << "7：显示停车场情况" << endl;
        cout << "8：退出" << endl;
        cin >> m;
        if (m == 1) 
        {
            cout << "输入进入车辆代号(int):" << endl;
            cin >> m;
            AddP(p, m);
        }
        else if (m == 2) 
        {
            cout << "输入要出去车辆位置:" << endl;
            cin >> m;
            m = PtoR(p, m, r);
            Dis_P(p);
            PopP(p);
            Dis_P(p);
            RtoP(p, m, r);
            Dis_P(p);
        }
        else if (m == 3)
        {
            cout << "输入进入车辆代号(int):" << endl;
            cin >> m;
            AddR(r, m);
        }
        else if (m == 4)
        {
            PopP(p);
        }
        else if (m == 5)
        {
            PopR(r);
        }
        else if (m == 6)
        {
            DoR(r);
        }
        else if (m == 7)
        {
            Dis_P(p);
        }
        else if (m == 8)
        {
            break;
        }
        
    }
}

int main()
{
    Cont();
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
