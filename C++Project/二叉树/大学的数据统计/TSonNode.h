#pragma once
#ifndef _TSONNODE_H_
#define _TSONNODE_H_

//#include<vector>

typedef struct tsonode
{
	string data;
	struct tsonode *sons[3];
}TSonNode;


#endif // !_TSONNODE_H_