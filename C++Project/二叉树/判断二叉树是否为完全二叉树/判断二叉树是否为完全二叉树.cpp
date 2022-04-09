
// 判断二叉树是否为完全二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define MaxSize 20

using namespace std;


//A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))

typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

void CreateBTree(BTNode*& b, string  str)
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k = 0, j = 0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':
			top++;
			St[top] = p;
			k = 1;
			break;
		case ')':
			top--;
			break;
		case ',':
			k = 2;
			break;
		default:
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:
					St[top]->lchild = p;
					break;
				case 2:
					St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void DisBTree(BTNode* b)
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DisBTree(b->lchild);
			if (b->rchild != NULL)
			{
				cout << ",";
			}
			DisBTree(b->rchild);
			cout << ")";
		}
	}
}

void judge_p_BTNode(BTNode *b,int &num)
{
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild != NULL)
			num++;
		if (b->lchild == NULL || b->rchild == NULL)
		{
			if (b->lchild != NULL)
				if (b->lchild->lchild != NULL || b->lchild->rchild != NULL)
					num++;
			if (b->rchild != NULL)
				if (b->rchild->lchild != NULL || b->rchild->rchild != NULL)
					num++;
		}
		judge_p_BTNode(b->lchild, num);
		judge_p_BTNode(b->rchild, num);
	}
}

int main()
{
	string str;
	BTNode* b;
	int num=0;
	cout << "input:" << endl;
	cin >> str;
	CreateBTree(b, str);
	judge_p_BTNode(b, num);
	if (num == 0)
		cout << "shi" << endl;
	else
		cout << "bushi" << endl;
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
