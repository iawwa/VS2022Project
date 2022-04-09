// 两个对称矩阵之和与乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

#define N 20

void Display(int a[]) 
{
    int i = 0;
    int j = 0;
    for (;i < N;i++)
    {
        j = 0;
        cout << "|";
        for (;j < N;j++)
        {
            if (i >= j)
            {
                cout << a[i * (i + 1) / 2 + j]<<" ";
            }
            else 
            {
                cout << a[j * (j + 1) / 2 + i] <<" ";
            }
        }
        cout << "|";
        cout << endl;
    }
    cout << endl;
}

void Fin(int a[]) 
{
    int i=0, j=0, num=0;
    while (true)
    {
        cout << "输入下三角中不为零的元素(i,j,num)(输入小于零坐标即退出):" << endl;
        cin >> i >> j >> num;
        if (i < 0 || j < 0) break;
        if (i < j) 
        {
            cout << "i需要大于j." << endl;
        }
        else 
        { 
            a[i * (i + 1) / 2 + j] = num; 
        }
    }
}


int Get(int a[], int i, int j)
{
    if (i >= j) 
    {
        return a[i * (i + 1) / 2 + j];
    }
    else 
    {
        return a[j * (j + 1) / 2 + i];
    }
}

void Addition(int a[], int b[],int c[]) 
{
    int i = 0;
    while (i < (N * (N + 1) / 2)) 
    {
        c[i] = a[i] + b[i];
        i++;
    }
}

void multiplication(int a[], int b[], int c[])
{
    int i = 0,j=0,k=0;
    while (i <N)
    {
        j = 0;
        while (j <= i)
        {
            k = 0;
            while (k < N) 
            {
                c[i * (i + 1) / 2 + j] = c[i * (i + 1) / 2 + j]+Get(a,i,k)* Get(b, k, j);
                k++;
            }
            j++;
        }
        i++;
    }
}


int main()
{
    int A[(N+1)*N/2] = { 0 }, B[(N + 1) * N / 2] = {0};
    int C[(N + 1) * N / 2] = { 0 }, D[(N + 1) * N / 2] = { 0 };
    Fin(A);
    cout << "A:" << endl;
    Display(A);
    Fin(B);
    cout << "B" << endl;
    Display(B);
    cout << "A+B=" << endl;
    Addition(A, B, C);
    Display(C);
    cout << "A*B=" << endl;
    multiplication(A, B, D);
    Display(D);
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
