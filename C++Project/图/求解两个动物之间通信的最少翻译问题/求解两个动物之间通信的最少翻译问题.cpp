// 求解两个动物之间通信的最少翻译问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#define INF 32767
#define MAXV 3
#include"AdjGraph.h"
using namespace std;

void ShortPath(AdjGraph *G,int u,int v)
{
    int num = 1;
    ArcNode* p;
    int w, i;
    QUEUE qu[MAXV];
    int front = -1, rear = -1;
    int visited[MAXV];
    for (i = 0; i < G->n; i++)
        visited[i] = 0;
    rear++;
    qu[rear].data = u;
    qu[rear].parent = -1;
    visited[u] = 1;
    while (front!=rear)
    {
        front++;
        w = qu[front].data;
        if (w == v)
        {
            i = front;
            while (qu[i].parent!=-1)
            {
                cout << qu[i].data<<"-";
                num++;
                i = qu[i].parent;
            }
            cout << qu[i].data<<" ";
            cout << "num:" << num - 2 << endl;
            num = 0;
            return;
        }
        p = G->adjlist[w].firstarc;
        while (p!=NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                visited[p->adjvex] = 1;
                rear++;
                qu[rear].data = p->adjvex;
                qu[rear].parent = front;
            }
            p = p->nextarc;
        }
    }
}

void CreateAdj(AdjGraph*& G, int A[][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)
    {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                //mallocArcNode(G,i,j,A);
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void ReadFileA(AdjGraph *&G)
{
    int a[MAXV][MAXV];
    int n, m,k=0,a1,a2;
    int i = 0,num=0;
    for (n = 0; n < MAXV; n++)
    {
        for (m = 0; m < MAXV; m++)
        {
            a[n][m] = INF;
            if (n == m)
                a[n][m] = 0;
        }
    }
    fstream infile;
    infile.open("test.txt");
    infile >> n >> m;
    while (i<m)
    {
        infile >> a1 >> a2;
        a[a1][a2] = 1;
        a[a2][a1] = 1;
        i++;
    }
    CreateAdj(G,a, n, i*2);
    infile >>k;
    i = 0;
    while (i<k)
    {
        infile >> a1 >> a2;
        cout << "(start:" << a1 << ",end:" << a2 << "):";
        ShortPath(G, a2, a1);
        i++;
    }
}

void DestroyAdj(AdjGraph *&G) 
{
    int i;
    ArcNode *pre, * p;
    for(i=0;i<G->n;i++)
    {
        pre = G->adjlist[i].firstarc;
        if (pre!=NULL) 
        {
            p = pre->nextarc;
            while (p!=NULL)
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

void menu() 
{
    AdjGraph* G;
    ReadFileA(G);
    DestroyAdj(G);
}

int main()
{
    menu();
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
