// 由遍历序列构造二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include <iostream>
//#include<vector>
#define MaxSize 100
#include"Btree.h"

using namespace std;

void DestroyBTree(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}

BTNode* CreateBT1(char *pre,char *in,int n) 
{
	BTNode *b;
	char *p;
	int k;
	if (n <= 0) return NULL;
	b = (BTNode *)malloc(sizeof(BTNode));
	b->data = *pre;
	for (p = in; p < in + n; p++)
	{
		if (*p == *pre)
			break;
	}
	k = p - in;
	b->lchild = CreateBT1(pre + 1, in, k);
	b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);
	return b;
}

BTNode* CreateBT2(char* post, char* in, int n)
{
	BTNode* b;
	char r, * p;
	int k;
	if (n <= 0)
		return NULL;
	r = *(post + n - 1);
	b = (BTNode*)malloc(sizeof(BTNode));
	b->data = r;
	for (p = in; p < in + n; p++)
		if (*p == r) break;
	k = p - in;
	b->lchild = CreateBT2(post, in, k);
	b->rchild = CreateBT2(post + k, p + 1, n - k - 1);
	return b;
}

void DIsBTNode(BTNode *b) 
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DIsBTNode(b->lchild);
			if (b->rchild != NULL)
				cout << ",";
			DIsBTNode(b->rchild);
			cout << ")";
		}
	}
}

void DIsBTNode_In(BTNode* b,int k=0)
{
	if (b != NULL)
	{
		k++;
		int i = 0;
		while (i <= k)
		{
			cout << " ";
			i++;
		}
		cout << b->data;
		while (i <= 20)
		{
			cout << "-";
			i++;
		}
		cout << endl;
		DIsBTNode_In(b->lchild,k);
		DIsBTNode_In(b->rchild,k);	
	}
}

int main()
{
	//vector<char>  a = {'A','B','D','E','H','J','K','L','M','N','C','F','G','I'}
	//char a[15] ="ABDEHJKLMNCFGI";
	//char b[15] = "DBJHLKMNEAFCGI";
	//char c[15] = "DJLNMKHEBFIGCA";
	char a[14] = { 'A','B','D','E','H','J','K','L','M','N','C','F','G','I' };
	char b[14] = { 'D','B','J','H','L','K','M','N','E','A','F','C','G','I' };
	char c[14] =  { 'D','J','L','N','M','K','H','E','B','F','I','G','C','A'};
	BTNode *B,*C;
	B = CreateBT1(a, b, 14);
	DIsBTNode(B);
	cout << endl;
	DIsBTNode_In(B);
	cout << endl;
	C = CreateBT2(c, b, 14);
	DIsBTNode(C);
	cout << endl;
	DIsBTNode_In(C);
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
