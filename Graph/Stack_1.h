#include <stdio.h>

#define __Elemtype int
#define __MaxSize 50
typedef struct 
{
	__Elemtype data[__MaxSize];
	int top;
}SqStack_1;

// 初始化栈
void InitStack_1(SqStack_1 &S)
{
	S.top = -1;
}

// 判栈空
bool SqStack_1Empty(SqStack_1 S)
{
	if(S.top == -1)
		return true;
	return false;
}

// 进栈
bool Push_1(SqStack_1 &S,__Elemtype e)
{
	if(S.top == __MaxSize-1)	
		return false;
	S.data[++S.top] = e;
	return true;
}

// 出栈
bool Pop_1(SqStack_1 &S,__Elemtype &e)
{
	if(S.top == -1)
		return false;
	e = S.data[S.top--];
	return true;
}

// 读栈顶元素
bool GetTop_1(SqStack_1 S,__Elemtype &e)
{
	if(S.top == -1)
		return false;
	e = S.data[S.top];
	return true;
}













