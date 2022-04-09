// 数据结构_p145_实验题4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define MaxSize 100

using namespace std;

typedef struct 
{
    char data[MaxSize];
    int lenth;
}SqString;

void StrAssign(SqString &a,string b) 
{
    int i = 0;
    while (b[i] != '\0')
    {
        a.data[i] = b[i];
        i++;
    }
    a.lenth = i;
}

void enc(SqString a,SqString &b)
{ 
    char key[26] = { 'n','g','z','q','t','c','o','b','m','u','h','e','l', 'k','p','d','a','w','x','f','y','i','v','r','s','j' };
    int i=0;
    while (i<a.lenth)
    {
        b.data[i] = key[a.data[i] - 97];
        i++;
    }
    b.lenth=a.lenth;
}

void dec(SqString a, SqString& b)
{  
    char key[26] = { 'q','h','f','p','l','t','b','k','v','z','n','m','i', 'a','g','o','d','x','y','e','j','w','r','s','u','c' };
    int i = 0;
    while (i < a.lenth)
    {
        b.data[i] = key[a.data[i] - 97];
        i++;
    }
    b.lenth = a.lenth;
}

void Display(SqString a) 
{
    int i=0;
    while (i < a.lenth)
    {
        cout << a.data[i];
        i++;
    }
    cout << endl;
}

int main()
{
    string b;
    SqString a,c,d;
    cout << "输入你要加密的字符串:" <<endl;
    cin >> b;
    StrAssign(a, b);
    enc(a, c);
    cout << "加密串：";
    Display(c);
    dec(c, d);
    cout << "解密串:";
    Display(d);
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
