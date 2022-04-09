// Vector_learning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//寻找数组的中心索引

#include <iostream>
#include<vector>

using namespace std;



int pivotIndex(vector<int>& nums)
{
    int i = 0, k = 0;
    int sum1 = 0;
    int sum2 = 0;
    while (i < nums.size())
    {
        for (k = 0, sum1 = 0, sum2 = 0; k < nums.size(); k++)
        {
            if (k < i)
                sum1 += nums[k];
            else if (k > i)
                sum2 += nums[k];
            else
                continue;
        }
        if (sum1 == sum2)
        {
            return i;
        }
        i++;
    }
    return -1;
}


int main()
{
    vector<int> h = { 1,2,4,3 };
    cout << pivotIndex(h);
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
