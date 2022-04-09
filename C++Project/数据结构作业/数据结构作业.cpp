// 数据结构作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
class Box 
{
public:
    int i,j,di;
    //Box& operator=(const Box &s)
    //{   
      //  i = s.i;
       // j = s.j;
      //  di = s.di;
     //   return *this;
   // }
};
typedef struct 
{
    Box data[40];
    int top;
}StType;
void Push(StType *&st,Box e)
{
    
    st->top = st->top + 1;
    st->data[st->top].i = e.i;
    st->data[st->top].j = e.j;
    st->data[st->top].di = e.di;
    
}
void Pop(StType *&st, Box &e)
{
    if (st->top != -1) 
    {
        e.i = st->data[st->top].i;
        e.j = st->data[st->top].j;
        e.di = st->data[st->top].di;
        st->top = st->top - 1;
    }
}
void mgpath(int xi, int yi, int xe, int ye)
{
    //int mg[6][6] = { {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},{1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1} };
    int mg[10][10] =
    {
        {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},{1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}
    };
    Box e,path[80][80];
    int a[30] = {},min=0,minlen;
    int i, j, di, i1, j1, k=0,m=0;
    bool find;
    StType* st;
    st =(StType*)malloc(sizeof(StType));
    st->top = -1;
    e.i = xi;
    e.j = yi;
    e.di = -1;
    Push(st,e);
    mg[xi][yi]=-1;
    while (st->top != -1)
    {
        i = st->data[st->top].i;
        j = st->data[st->top].j;
        di = st->data[st->top].di;

        if (i == xe && j == ye) //do it
        {
            m = 0;
            while (st->top != -1)
            {
                Pop(st, e);
                path[k][m].i = e.i;
                path[k][m].j = e.j;

                cout << "(" << path[k][m].i << "," << path[k][m].j << ")" << " ";//duode

                m++;

            }
            a[k] = m;
            st->top = m - 1;
            k = k + 1;
            //Pop(st, e);
           // mg[e.i][e.j] = 0;
            find = false;

            cout << endl;//duoyu

        }
        else 
        {
            find = false;
            while (di < 4 && find == false)
            {
                di++;
                switch (di)
                {
                case 0:
                    i1 = i - 1;
                    j1 = j;
                    break;
                case 1:
                    i1 = i;
                    j1 = j + 1;
                    break;
                case 2:
                    i1 = i + 1;
                    j1 = j;
                    break;
                case 3:
                    i1 = i;
                    j1 = j - 1;
                    break;
                }
                if (mg[i1][j1] == 0)
                {
                    find = true;
                }
            } 
        }
        if (find==true)
        {
            st->data[st->top].di = di;
            e.i = i1;
            e.j = j1;
            e.di = -1;
            Push(st, e);
            mg[i1][j1] = -1;
        }
        else
        {
            Pop(st, e);
            mg[e.i][e.j] = 0;
        }
    }

    cout << "-----------------------------------" << endl;//duoyu



    free(st);
    cout << "所有路径:" <<endl;
    min = k-1;
    minlen = a[k-1];
    while (k > 0)
    {
        if (a[k - 1] < minlen)
        {
            min = k - 1;
            minlen = a[k - 1];
        }
        while (a[k-1] > 0)
        {
            
            cout << path[k-1][a[k-1]-1].i << path[k - 1][a[k-1] - 1].j << " ";
            a[k-1] = a[k-1] - 1;
        }
        cout << endl;
        k = k - 1;
    }



    cout << "长度:" << minlen<<endl;
    cout << "最短路径:" << endl;
    while (minlen > 0)
    {

        cout << path[min][minlen - 1].i << path[min][minlen - 1].j << " ";
        minlen = minlen - 1;
    }
 

}
int main()
{
    mgpath(1, 1, 8,8 );
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
