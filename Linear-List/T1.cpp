/*
 * ===================================================================
 *
 *       Filename:  T1.cpp
 *
 *           Link:  P18 T1
 *
 *        Created:  2019/08/02 20时35分08秒
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

// 判空操作
bool Empty(SqList L)
{
	if(L.length == 0)	
		return true;
	return false;
}

// 删除最小值的元素并返回这个元素的值
// 空出的位置由最后一个元素填补
// 若顺序表为空则显示出错信息并退出
// 时 O(N)
// 空 O(1)
bool DeleteMin(SqList &L,ElemType &e)
{
	if(Empty(L))
	{
		printf("表为空！！！\n");
		return false;
	}
	int mmax = 0x3f3f3f3f;
	int at = 0;
	for(int i = 0;i < L.length;i++)
	{
		if(mmax > L.data[i])
		{
			mmax = L.data[i];
			at = i;
		}
	}
	e = L.data[at];
	L.data[at] = L.data[L.length-1];
	return true;
}

int main()
{
    return 0;
}

