/*
 * ===================================================================
 *
 *       Filename:  T4.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/03 15时52分38秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 50
typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

// 判空操作
bool Empty(SqList L)
{
	if(L.length == 0)	
		return true;
	return false;
}

// 有序顺序表中删除值在s与t之间的所有元素(s<t)
// 如果s和t不合理或者顺序表为空,则显示出错信息并退出运行
// 时 O(N)
// 空 O(1)
bool Delete(SqList &L,int s,int t)
{
	if(Empty(L))
	{
		printf("顺序表为空!\n");
		return false;
	}
	if(s >= t)
	{
		printf("s和t不合理!\n");
		return false;
	}
	int i,j,k;
	for(i = 0;L.data[i] <= s && i < L.length;i++);
	for(j = i,k = 0;L.data[j] < t && j < L.length;j++,k++);
	for(;j < L.length;j++)
		L.data[j-k] = L.data[j];
	return true;
}


int main()
{

    return 0;
}

