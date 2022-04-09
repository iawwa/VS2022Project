// 二叉树中单分支结点数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int num=0;

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


void Find_odd(BTNode *b) 
{
    if (b != NULL)
    {
        if ((b->lchild != NULL && b->rchild == NULL) || (b->lchild == NULL && b->rchild != NULL))
            num++;
        Find_odd(b->lchild);
        Find_odd(b->rchild);
    }
}

void Find_odd(BTNode* b,int &num)
{
	if (b != NULL)
	{
		if ((b->lchild != NULL && b->rchild == NULL) || (b->lchild == NULL && b->rchild != NULL))
			num++;
		Find_odd(b->lchild,num);
		Find_odd(b->rchild,num);
	}
}

int main()
{
	int num1 = 0;
    string str;
    BTNode* b;
    cout << "input:" << endl;
    cin >> str;
    CreateBTree(b, str);
	Find_odd(b);
	Find_odd(b,num1);
	DisBTree(b);
	cout << endl<<"num1=" << num1 << endl;
    cout << "num=" << num;
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
