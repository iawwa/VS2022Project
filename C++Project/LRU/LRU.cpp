// LRU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#define N 3
using namespace std;
int main()
{
    int ym[] = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
    int lru[N] = { 1,0,7 };
    int len[N] = { 0,0,0 };
    int allchagetimes = 0;
    for (int t = 0; t < N; t++)
    {
        cout << lru[t] << "  ";
    }
    cout << endl;

    for (int i = 3; i < 20; i++)
    {
        int flag = 0;
        int j = 0;
        int sum = 0;
        for (; j < N; j++)
        {
            if (ym[i] == lru[j])
            {
                flag = 1;
                break;
            }
            else if (ym[i] != lru[j])
            {
                sum++;
                if (sum == 3)
                {
                    flag = 0;
                    break;
                }
            }


        }

        if (flag == 1)
        {
            int temp = lru[0];
            if (j == 0)
            {

            }
            else if (j == 1)
            {
                lru[0] = lru[j];

                lru[2] = lru[2];
                lru[1] = temp;
            }

            else if (j == 2)
            {
                lru[0] = lru[j];

                lru[2] = lru[1];
                lru[1] = temp;

            }

        }
        else if (flag == 0)
        {
            allchagetimes++;
            lru[2] = lru[1];
            lru[1] = lru[0];
            lru[0] = ym[i];


        }

        for (int t = 0; t < N; t++)
        {
            cout << lru[t] << "  ";
        }
        cout << endl;
    }

    cout << "缺页" << allchagetimes + 3 << "次，置换" << allchagetimes << "次" << endl;
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
