/*
 * ===================================================================
 *
 *       Filename:  T2.cpp
 *
 *           Link:  P18 T2
 *
 *        Created:  2019/08/02 21时07分28秒
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

// 将所有元素逆置
bool Reverse(SqList &L)
{
	if(Empty(L))
		return false;
	int len = (L.length+1)/2;
	int tmp = 0;
	for(int i = 0;i < len;i++)
	{
		tmp = L.data[i];
		L.data[i] = L.data[L.length-i-1];
		L.data[L.length-i-1] = tmp;
	}
	return true;
}

int main()
{
    return 0;
}

