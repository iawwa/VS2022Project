// 实现二叉树的各种基本运算的算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define MaxSize 100

using namespace std;

typedef struct  haha
{
	char data;//事实上这里可以用一个对象来应对不同情况
	struct haha* lchild;//左右子节点
	struct haha* rchild;//由于此时BTNode未定义所以需用struct haha 声明指针
}BTNode;

void CreateBTree(BTNode*& b, string  str)
{
	BTNode* St[MaxSize], * p=NULL;
	int top = -1, k=0, j = 0;
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

void DestroyBTree(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
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

int BTHeight(BTNode* b)
{
	int l = 0, r = 0;
	if (b != NULL)
	{
		l = BTHeight(b->lchild);
		r = BTHeight(b->rchild);
		return (l > r) ? (l + 1) : (r + 1);
	}
	else
		return 0;
}

BTNode* FindNode(BTNode*& b, char x)
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
	{
		return b;
	}
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
		{
			return p;
		}
		else
		{
			return FindNode(b->rchild, x);
		}
	}
}

void menu() 
{
	int key;
	char m;
	BTNode* b, * p;
	b = p = NULL;
	string exp;
	while (true) 
	{
		cout << endl;
		cout << "输入序号以完成特定功能" <<endl;
		cout << "(1)创建一个二叉树 （输入字符串）:" << endl;
		cout << "(2)输出二叉树：" << endl;
		cout << "(3)输出某节点的孩子节点：" <<endl;
		cout << "(4)输出二叉树高度：" << endl;
		cout << "(5)释放二叉树：" << endl;
		cin >> key;
		if (key == 1)
		{
			cout << "输入二叉树的括号表示串:" << endl;
			cin >> exp;
			CreateBTree(b, exp);
		}
		else if (key == 2)
		{
			DisBTree(b);
		}
		else if (key == 3)
		{
			cout << "输入该结点值:" << endl;
			cin >> m;
			p = FindNode(b, m);
			cout << p->lchild->data << " " << p->rchild->data << endl;
		}
		else if (key == 4)
		{
			cout << "高度:" << BTHeight(b);
		}
		else if (key == 5)
		{
			DestroyBTree(b);
		}
		else 
		{
			break;
		}
	}
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
