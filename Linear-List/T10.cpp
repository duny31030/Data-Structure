/*
 * ===================================================================
 *
 *       Filename:  T10.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/09 22时18分08秒
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

void swap(int &x,int &y)
{
	int tmp = x;	x = y;	y = tmp;
}

bool Reverse(SqList &L,int s,int e)
{
	for(int i = s,j = e;i <= j;i++,j--)	swap(L.data[i],L.data[j]);
	return true;
}

bool slove(SqList &L,int p)
{
	Reverse(L,0,p-1);
	Reverse(L,p,L.length-1);
	Reverse(L,0,L.length-1);
	return true;
}

int main()
{


    return 0;
}

