#pragma once
#ifndef _MATGRAPH_H_
#define _MATGRAPH_H_
#define MAXV 6
#define INF 32767
typedef struct ls
{
	int edges[MAXV][MAXV];
	int n=6;
	int e = 10;
}MatGraph;
#endif // !_TSONNODE_H_