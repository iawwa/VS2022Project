#pragma once
#ifndef _ADJGRAPH_H_
#define _ADJGRAPH_H_
typedef struct ANode 
{
	int adjvex;
	struct ANode* nextarc;
	int weight=1;
}ArcNode;
typedef struct Vnode 
{
	//InfoType info;
	ArcNode* firstarc;
}VNode;
typedef struct haha
{
	VNode adjlist[MAXV];
	int n, e;
}AdjGraph;
typedef struct 
{
	int data;
	int parent;
}QUEUE;
#endif // _ADJGRAPH_H_
