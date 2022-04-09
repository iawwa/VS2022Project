// 数据结构_p144_实验一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MaxSize 30

using namespace std;

typedef struct 
{
    char data[MaxSize];
    int length;
}SqString;

void StrAssign(SqString &s,char cstr[])
{
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
    {
        s.data[i] = cstr[i];
    }
    s.length = i;
}

void StrCopy(SqString &s,SqString t) 
{
    int i;
    for (i = 0; i < t.length; i++)
    {
        s.data[i] = t.data[i];
    }
    s.length = t.length;
}

SqString ReduceStr(SqString s,int start,int num) 
{
    SqString m;
    int i;
    for (i = 0; i < s.length; i++)
    {

    }
    return m;
}

void DispStr(SqString s) 
{
    int i=0;
    if (s.length > 0)
    {
        while (i < s.length)
        {
            cout << s.data[i];
            i++;
        }
    }
    cout << endl;
}


int main()
{

     
    system("pasue");
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
