/*
 * ===================================================================
 *
 *       Filename:  T3.CPP
 *
 *           Link:  P18 T3
 *
 *        Created:  2019/08/02 21时11分44秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <stdio.h>
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

// 插入操作
bool ListInsert(SqList &L,int i,ElemType e)
{
	if(i < 1 || i > L.length+1)
		return false;
	if(L.length >= MAXSIZE)
		return false;
	for(int j = L.length;j >= i;j--)
		L.data[j] = L.data[j-1];	// 之后的元素后移
	L.data[i-1] = e;
	L.length++;
	return true;
}

// 判空操作
bool Empty(SqList L)
{
	if(L.length == 0)	
		return true;
	return false;
}

// 删除线性表中所有值为x的数据元素
// 时 O(N)
// 空 O(1)

bool Delete(SqList &L,int x)
{
	if(Empty(L))
		return false;
	int count = 0;
	for(int i = 0;i < L.length;i++)
	{
		if(L.data[i] != x)
		{
			L.data[i-count] = L.data[i];
		}
		else 
		{
			count++;
		}
	}
	L.length -= count;
	return true;
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

int main()
{
	SqList L;
	InitList(L);
	int n,x;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&x);
		ListInsert(L,i,x);
	}
	Delete(L,10);
	PrintList(L);
	return 0;
}

