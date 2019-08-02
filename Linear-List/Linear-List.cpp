/*
 * ===================================================================
 *
 *       Filename:  Linear-List.cpp
 *
 *        Remarks:  线性表的静态分配实现
 *
 *        Created:  2019/07/31 19时31分55秒
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

// 求表长，返回线性表的长度
int Length(SqList L)
{
	return L.length;
}

// 按值查找,返回元素e的位置
// 若查找失败则返回0
int LocateElem(SqList L,ElemType e)
{
	for(int i = 0;i < L.length;i++)
		if(L.data[i] == e)
			return i+1;
	return 0;
}

// 按位查找,返回第i个元素的位置
// 若查找失败则返回-1
int GetElem(SqList L,int i)
{
	if(i < 1 || i > L.length)
		return -1;
	return L.data[i-1];
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

// 删除操作
bool ListDelete(SqList &L,int i,ElemType &e)
{
	if(i < 1 || i > L.length)
		return false;
	e = L.data[i-1];
	for(int j = i-1;j < L.length-1;j++)
		L.data[j] = L.data[j+1];
	L.data[L.length--] = 0;
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

// 判空操作
bool Empty(SqList L)
{
	if(L.length == 0)	
		return true;
	return false;
}
