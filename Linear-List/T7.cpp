/*
 * ===================================================================
 *
 *       Filename:  T7.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/03 16时24分37秒
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

// 初始化线性表
bool InitList(SqList &L)
{
	L.length = 0;
	return true;
}

// 判空操作
bool Empty(SqList L)
{
	if(L.length == 0)	
		return true;
	return false;
}

// 打印线性表
void PrintList(SqList L)
{
	int size = L.length;
	for(int i = 0;i < size;i++)
	{
		printf("%d",L.data[i]);
		if(i%10 == 0 && i)
			printf("\n");
		else if(i != size-1)
			printf("  -> ");
	}
}

// 将两个有序顺序表合并为一个新的有序顺序表
// 并由函数返回结果顺序表
// 时 O(n+m)
// 空 O(1)
bool Merge(SqList L1,SqList L2,SqList &L)
{
	if(L1.length + L2.length > MAXSIZE)
		return false;
	int i,j,k;
	for(i = 0,j = 0,k = 0;i < L1.length && j < L2.length;)
	{
		if(L1.data[i] <= L2.data[j])
			L.data[k++] = L1.data[i++];
		else 
			L.data[k++] = L2.data[j++];
	}
	while(i < L1.length)
		L.data[k++] = L1.data[i++];
	while(j < L2.length)
		L.data[k++] = L2.data[j++];
	L.length = L1.length+L2.length;
	return true;
}

int main()
{
	SqList L;
	SqList L1,L2;
	InitList(L);
	L1.length = 0;
	L2.length = 2;
	L1.data[0] = 1;	L1.data[1] = 3;	L1.data[2] = 4;
	L2.data[0] = 2;	L2.data[1] = 5;
	Merge(L1,L2,L);
	PrintList(L);
    return 0;
}

