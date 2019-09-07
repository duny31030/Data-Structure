/*
 * ===================================================================
 *
 *       Filename:  TopologicalSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/06 11时55分25秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
#include "Stack_1.h"
using namespace std;

const int MAXVEX = 110;
int print[MAXVEX];

// 使用邻接表来存储图
// 边表结点
typedef struct EdgeNode
{
	int adjvex;				// 邻接点域,存储该顶点对应的下标
	int weight;				// 用于存储权值,对于非网图可以不需要
	struct EdgeNode *next;	// 链域,指向下一个邻接点
}EdgeNode;

// 顶点表结点
typedef struct VertexNode
{
	int in;					// 顶点入度
	int data;				// 顶点域,存储顶点信息
	EdgeNode *first;	// 边表头指针
}VNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes,numEdges;// 图中当前顶点数和边数
}AlGraph;

void InitGraph(AlGraph &G)
{
	G.numVertexes = 0;
	G.numEdges = 0;
	for(int i = 0;i < MAXVEX;i++)
	{
		G.adjList[i].in = G.adjList[i].data = 0;
		G.adjList[i].first = NULL;
	}
}

void AddEdges(AlGraph &G,int u,int v)
{	
	G.adjList[v].in++;
	EdgeNode *node = (EdgeNode *)malloc(sizeof(EdgeNode));
	node->next = G.adjList[u].first;
	G.adjList[u].first = node;
	node->adjvex = v;
}

// 拓扑排序
bool TopologicalSort(AlGraph G,int n)
{
	int i;
	SqStack_1 S;
	InitStack_1(S);
	for(i = 1;i <= n;i++)
	{
		if(G.adjList[i].in == 0)
			Push_1(S,i);
	}
	
	int count = 0;
	while(!SqStack_1Empty(S))
	{
		Pop_1(S,i);
		print[++count] = i;
		for(EdgeNode *p = G.adjList[i].first;p;p = p->next)
		{
			int tmp = p->adjvex;
			G.adjList[tmp].in--;
			if(!G.adjList[tmp].in)
				Push_1(S,tmp);
		}
	}
	if(count < G.numVertexes)
		return false;
	else 
		return true;
}

void pr(int n)
{
	printf("YES\n");
	for(int i = 1;i <= n;i++)
		printf("%d ",print[i]);
	printf("\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	AlGraph G;
    InitGraph(G);
	int n,m,i,u,v;
	scanf("%d %d",&n,&m);
	G.numVertexes = n;	G.numEdges = m;
	for(i = 1;i <= m;i++)
	{
		scanf("%d %d",&u,&v);
		AddEdges(G,u,v);
	}
	if(TopologicalSort(G,n))
		pr(n);
	else 
		printf("Ohhh~\n");

	return 0;
}

