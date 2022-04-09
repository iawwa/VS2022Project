// 检测括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MaxSize 30

using namespace std;

typedef struct 
{
    char a[MaxSize];
    int top;
}SqStack;

void Pop(SqStack *&q) 
{
    q->top=q->top- 1;
}

char GetHead(SqStack*& q)
{
    return q->a[q->top];
}

void Add(SqStack*& q,char e)
{
    q->top++;
    q->a[q->top] = e;
}

bool doit()
{
    SqStack* q;
    int i = 0;
    string s;
    q = (SqStack*)malloc(sizeof(SqStack));
    q->top = -1;
    cout << "输入表达式" << endl;
    cin >> s;
    while (s[i] != NULL)
    {
        if (s[i] == '(')
            Add(q, s[i]);
        else if (s[i] == ')')
            if (GetHead(q) == '(')
                Pop(q);
            else
                return false;
        else if (s[i] == '[')
            Add(q, s[i]);
        else if (s[i] == ']')
            if (GetHead(q) == '[')
                Pop(q);
            else
                return false;
        else if (s[i] == '{')
            Add(q, s[i]);
        else if (s[i] == '}' )
            if (GetHead(q) == '{')
                Pop(q);
            else
                return false;
        i++;  
    }
    if (q->top == -1)
    {
        return true;
    }
    return false;
}

int main()
{
    cout<<"配对情况:" << doit();
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
