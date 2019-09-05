/*
 * ===================================================================
 *
 *       Filename:  Prim.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/05 15时10分09秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
const int INF = 0x3f3f3f3f;

// 使用邻接矩阵来存储边权
int G[N][N];
// 标记已经加入最小生成树的顶点
bool v1[N];
// 存储目前可以达到的顶点的最小花费(边权)
int v2[N];

// 在输入之前初始化图并且此时未选中任何顶点
// 所以初始化v1数组
void initG(int n)
{
	for(int i = 0;i <= n;i++)	v1[i] = 0;
	for(int i = 0;i <= n;i++)	
		for(int j = 0;j <= n;j++)	
			G[i][j] = i==j?0:INF;
}

// 传入的参数是图的顶点数
int Prim(int n)
{
	int cost = 0,tot = 1,mmin,now;
	for(int i = 1;i <= n;i++)	v2[i] = G[1][i];
	v1[1] = 1;
	while(tot < n)
	{
		mmin = INF;
		tot++;
		for(int i = 1;i <= n;i++)
		{
			if(v2[i] < mmin && !v1[i])
			{
				mmin = v2[i];
				now = i;
			}
		}
		cost += mmin;
		for(int i = 1;i <= n;i++)
		{
			// "备胎"必须是没有选中的顶点
			// 花费(边权)应该比现在需要花费的小才进行更新
			if(!v1[i] && v2[i] > G[now][i])
				v2[i] = G[now][i];
		}
		v1[now] = 1;
	}
	return cost;
}

int main()
{
	freopen("in.txt","r",stdin);
	initG(100);
	int n,m,u,v,w;
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}
	cout << Prim(n) << endl;
}

