// 二叉树的序列化和反序列化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 假设二叉树的每个结点值为单个字符（不含‘#’，这里用‘#’字符表示对应空结点）。所谓序列化就是对二叉树进行先序遍历产生一个
//字符序列的过程，与一般先序遍历不同的是，这里还要记录空结点。
//例如,对于如图7.35所示所示的一颗二叉树，一般先序遍历是“ABDEGCFHI”，而这里的先序
//序列序列化结果是“ABD##E#G##C#FH##I##”,相当于在二叉树中标记上所有的空结点，如图7.36所示（也称为拓展二叉树），
//然后进行先序遍历.
//所谓反序列化就是通过先序序列化的结果串str构建对应的二叉树，其过程是用i从头到尾
//扫描str，采用先序方法，当i超界时返回NULL；否则当遇到‘#’字符时返回NULL，当遇到其它字符时创建一个结点，
//然后递归构造它的左右子树。可以证明，采用先序遍历实现的二叉树序列化和反序列化的结果是唯一的。
//（1）创建二叉链b：
//（2）采用括号表示输出二叉链b：
//（3）对二叉链b进行先序遍历，产生先序序列化序列str：
//（4）输出先序序列化序列：
//（5）由str构建二叉链b1（反序列化）：
//（6）采用括号表示输出二叉链b1：
//（7）销毁二叉链b和b1：

#include <iostream>
#include"BTNode.h"

using namespace std;

void BTNode_Create(BTNode*& b,string a)
{
    int i = 0;
    BTNode* q;
    b = NULL;
    q = b;
    while (a[i] != '\0')
    {
        if (a[i] == '#')
        {

        }
        else 
        {
            q->data = a[i];
        }


    }
}

void BTNode_Create_rec(BTNode *&b,string a,int i=0) //递归
{
    if (i<a.size()) 
    {
        BTNode* q;
        q = (BTNode*)malloc(sizeof(BTNode));
        b = q;
        if (a[i] == '#')
        {
            b->data = NULL;
        }
        else
        {
            b->data = a[i];
        }
        BTNode_Create_rec(b->lchild, a, i + 1);
        BTNode_Create_rec(b->rchild, a, i + 2);
    }
}

void BTNode_Display_front(BTNode* b)
{
    if (b == NULL)
        cout << '#';
    else
    {
        cout << b->data;
        BTNode_Display_front(b->lchild);
        BTNode_Display_front(b->rchild);
    }
}

int main()
{
    string a;
    cin >> a;
    BTNode* q;
    BTNode_Create_rec(q, a);
    BTNode_Display_front(q);
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
