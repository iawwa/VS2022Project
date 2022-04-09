// 并归排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high) 
{
    int i = low, j = mid + 1,k=0;
    int* tmp = new int[high - low + 1];
    while (i <= mid && j <= high) 
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            k++;
            i++;
        }
        else 
        {
            tmp[k] = arr[j];
            k++;
            j++;

        }
    }
    while (i <= mid) 
    {
        tmp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) 
    {
        tmp[k] = arr[j];
        k++;
        j++;
    }
    for (i = low, k = 0;i <= high;i++, k++)
    {
        arr[i] = tmp[k];
    }
    delete[]tmp;
}

void MergeSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int i = 0;
    int a[10] = { 1,52,65,32,45,15,26,25,35,326 };
    MergeSort(a, 0, 9);
    while (i <= 9)
    {
        cout << a[i] << " ";
        i += 1;
    }
    cout << endl;
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
