#pragma once
#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

#endif // !_BTREE_H_