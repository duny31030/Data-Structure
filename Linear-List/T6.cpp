/*
 * ===================================================================
 *
 *       Filename:  T6.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/03 16时05分34秒
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

// 从顺序表中删除其值重复的元素,使表中所有元素的值均不同
// 时 O(N)
// 空 O(1)
bool Delete(SqList &L)
{
	if(Empty(L))
		return false;
	int i,j;
	for(i = 1,j = 0;i < L.length;i++)
	{
		if(L.data[i] != L.data[j])
			L.data[++j] = L.data[i];
	}
	L.length = j+1;
	return true;
}

int main()
{

	return 0;
}

