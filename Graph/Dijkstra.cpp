/*
 * ===================================================================
 *
 *       Filename:  Dijkstra.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/05 16时46分58秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+100;
const int INF = 0x3f3f3f3f;

// 使用邻接矩阵来存储图
int G[N][N];
int dist[N];
bool path[N];

void initG()
{
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			G[i][j] = i==j?0:INF;
}

void Dijkstra(int n,int v0)
{
	int mmin,now;
	for(int i = 1;i <= n;i++)	path[i] = 0;
	// 初始化dist[]
	for(int i = 1;i <= n;i++)	dist[i] = G[v0][i];	
	dist[v0] = 0;
	path[v0] = 1;
	for(int i = 1;i < n;i++)
	{
		mmin = INF;
		for(int j = 1;j <= n;j++)
		{
			if(!path[j] && dist[j] < mmin)
			{
				mmin = dist[j];
				now = j;
			}
		}
		path[now] = 1;
		for(int j = 1;j <= n;j++)
		{
			if(!path[j] && dist[j] > dist[now]+G[now][j])
			{
				dist[j] = dist[now]+G[now][j];
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	initG();
	int n,m,u,v,w;
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		G[u][v] = w;
	}
	Dijkstra(n,2);
	cout << dist[n] << endl;
    return 0;
}

