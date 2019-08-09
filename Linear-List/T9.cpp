/*
 * ===================================================================
 *
 *       Filename:  T9.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/09 21时54分49秒
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

// 删除操作
bool ListDelete(SqList &L,int i)
{
	if(i < 1 || i > L.length)
		return false;
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

int BS(SqList &L,int s)
{
	int low = 0,high = L.length-1,mid;
	while(low < high)
	{
		mid = (low+high)/2;
		if(L.data[mid] == s)
			return mid;		// 查找成功
		else 
			if(L.data[mid] > s)
				high = mid-1;
			else low = mid+1;
	}
	return -1;
}

// 找到第一个大于s的位置
int BS2(SqList &L,int s)
{
	int low = 0,high = L.length-1,mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(L.data[mid] > s)
			high = mid-1;
		else 
			low = mid+1;
	}
	return mid;
}

void swap(int &x,int &y)
{
	int tmp = x;	x = y;	y = tmp;
}



// 查找数值为s的元素
// 找到后将其与后继位置的元素互换
// 找不到则将其插入线性表并使线性表仍然有序
bool Binary_Search(SqList &L,int s)
{
	int at = BS(L,s);
	if(at != -1)	// 查找成功 
	{
		// 保证该元素有后继位置
		if(at != L.length-1)
			swap(L.data[at],L.data[at+1]);
	}
	else 
	{
		int len = L.length;
		at = BS2(L,s);
		for(int i = len;i > at;i--)	L.data[i] = L.data[i-1];
		L.data[at] = s;
		L.length++;
		return false;
	}
	return true;
}


int main()
{
	int s = 5;
	SqList L;
	for(int i = 1;i < 10;i++)	ListInsert(L,i,i);
	ListDelete(L,5);
	if(Binary_Search(L,s) == true)
		printf("YES!!\n");
	else 
	{
		PrintList(L);
	}
    return 0;
}

