// 数制转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;
int N, res = 0;
int queen(int* arr, int r) {
    if (r == N)
        res++;
    else {
        for (int c = 0;c < N;c++) {
            arr[r] = c;
            bool can = true;//用于标记是否可以放皇后
            for (int c1 = 0;c1 < r;c1++) {                //不在同一行
                if (arr[r] == arr[c1] ||                //同一列的情况
                    abs(r - c1) == abs(arr[r] - arr[c1])) { //同一对角线的情况
                    can = false;
                    break;
                }
            }
            if (can)
                queen(arr, r + 1);
        }
    }
    return res;
}
int main() {
    N = 4;
    int arr[N];
    cout << queen(arr, 0);
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
