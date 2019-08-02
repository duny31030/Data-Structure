/*
 * ===================================================================
 *
 *       Filename:  Linear-List.c
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
#define INITSIZE 100
#define ElemType int 

// 静态分配
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

// 求表长，返回线性表的长度
int Length(SqList L)
{
	return L.length;
}

// 初始化表
bool InitList(SqList &L)
{
	for(int i = 0;i < MAXSIZE;i++)
		L.data[i] = 0;
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

int main()
{
    // ios
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        // freopen("out.txt","w:",stdout);
    #endif
	SqList L;
	InitList(L);
	printf("%d\n",Length(L));
	
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	printf("%d\n",Length(L));
	
	int e;
	ListDelete(L,1,e);
	printf("%d\n",Length(L));
	PrintList(L);
    
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


