#ifndef BTNode
#pragma once
#define BTNode

typedef struct  haha
{
	char data;//事实上这里可以用一个对象来应对不同情况
	struct haha* lchild;//左右子节点
	struct haha* rchild;//由于此时BTNode未定义所以需用struct haha 声明指针
}BTNode;

void CreateBTree(BTNode*& b, string  str)
{
	BTNode* St[MaxSize], * p;
	int top = -1, k, j = 0;
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






#endif 





