/*
 * ===================================================================
 *
 *       Filename:  T5.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/03 16时01分53秒
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

// 顺序表(未必有序)中删除值在s与t之间的所有元素(s<t)(包含s和t)
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
	if(s > t)
	{
		printf("s和t不合理!\n");
		return false;
	}
	int i,j = 0;
	for(i = 0;i < L.length;i++)
	{
		if(L.data[i] > t || L.data[i] < s)
		{
			L.data[i-j] = L.data[i];
		}
		else 
			j++;
	}
	L.length -= j;
	return true;
}

int main()
{

	return 0;
}

