// 采用普里姆算法求最小生成树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
#include"MatGraph.h"

using namespace std;

void Create_MatGraph(MatGraph &g) 
{
    int x, y, w;
    for (int i=0;i<MAXV;i++) 
    {
        for (int j = 0; j < MAXV; j++)
        {
            g.edges[i][j] = INF;
            if (i == j)
                g.edges[i][j] = 0;
        }
    }
    while(true)
    {
        cout << "input x,y,w:" << endl;
        cin >> x >> y >> w;
        if (x < 0 || y < 0)
        {
            break;
        }
        g.edges[x ][y ] = w;
        g.edges[y][x ] = w;
        //g.n += 2;
    }
}
void Prim(MatGraph g,int v=0) 
{
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV], i, j, k;
    for (i=0;i<g.n;i++) 
    {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    for (i=1;i<g.n;i++) 
    {
        MIN = INF;
        for (j = 0; j < g.n; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < MIN)
            {
                MIN = lowcost[j];
                k = j;
            }
        }
        cout << "边(" << closest[k] << "," << k << ")权为：" << MIN << endl;
        lowcost[k] = 0;
        for (j = 0; j < g.n; j++)
        {
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;
            }
        }
    }
}
void Display_Graph(MatGraph g) 
{
    for (int i=0;i<g.n;i++) 
    {
        cout << "|";
        for (int j=0;j<g.n;j++) 
        {
            cout <<setw(5) << g.edges[i][j] << " ";
        }
        cout << "|" << endl;
    }
}
int main()
{
    MatGraph a;
    Create_MatGraph(a);
    Display_Graph(a);
    Prim(a);
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
