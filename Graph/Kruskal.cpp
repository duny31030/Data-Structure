/*
 * ===================================================================
 *
 *       Filename:  Kruskal.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/05 13时46分50秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+100;

// 存储边
// 使用[1,n]来存储
struct node 
{
	int u;	// 起点
	int v;  // 终点
	int w;	// 边权
}E[N];

// cmp函数 排序的时候调用
// 效果是按照边权从小到大排序
bool cmp(struct node a,struct node b)
{
	return a.w < b.w;
}

int f[5010];	// 并查集 判环

// 并查集初始化函数
void initf()
{
	for(int i = 0;i < 5010;i++)	f[i] = i;
}

// 并查集查询
int find(int x)
{
	// 并查集循环查找+路径压缩
	while(x != f[x])	x = f[x] = f[f[x]];
	return x;
}

// Kruskal函数
// 传入的参数是边的数量,顶点的数量
int Kruskal(int n,int m)
{
	int cost = 0,count = 0,j = 1;
	int eu,ev;
	// 按照边权对所有的边进行排序
	sort(E+1,E+n+1,cmp);
	while(count < m-1 && j < n)
	{
		// cout << j << " " << E[j].u << " - " << E[j].v << " - " << E[j].w << endl;
		eu = find(E[j].u);	ev = find(E[j].v);
		++j;
		if(eu == ev)	continue;
		f[ev] = eu;
		cost += E[j-1].w;
		count++;
	}
	return cost;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,m;
	cin >> m >> n;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
	}
	initf();
	cout << Kruskal(n,m) << endl;

	return 0;
}

