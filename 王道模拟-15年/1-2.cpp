/*
 * ===================================================================
 *
 *       Filename:  1-2.cpp
 *
 *           Link:  王道模拟卷-15年 卷一42.题
 *
 *        Created:  2019/10/23 10时05分40秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;

#define ElemType int
#define MaxSize 100

typedef struct BiTNode
{
	ElemType data;						// 数据域
	struct BiTNode *lchild,*rchild;		// 左、右孩子指针
}BTNode,*BiTree;

int AncestoPath(BTNode *b,BTNode *s)
{
	BTNode *st[MaxSize];
	BTNode *p;
	int i,flag,top = -1;
	do{
		while(b!=NULL){
			st[++top] = b;
			b = b->lchild;
		}
		p = NULL;
		flag = 1;
		while(top != -1 && flag){
			b = st[top];
			if(b->rchild == p){
				if(b == s){
					for(i = 0;i <= top;++i)
						printf("%d ",st[i]->data);
					return 1;
				}
				else {
					top--;
					p = b;
				}
			}
			else {
				b = b->rchild;
				flag = 0;
			}
		}
	}
	while(top != -1);
	return 0;
}

int main()
{
    // ios
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        // freopen("out.txt","w:",stdout);
    #endif
	BiTNode A,B,C,D,E,F,G,H;
	A.data = 1;
	B.data = 2;
	C.data = 3;
	D.data = 4;
	E.data = 5;
	F.data = 6;
	G.data = 7;
	H.data = 8;
	A.lchild = &B;
	A.rchild = &D;
	B.lchild = NULL;
	B.rchild = &C;
	C.lchild = NULL;
	C.rchild = NULL;
	D.lchild = &E;
	D.rchild = &H;
	H.lchild = H.rchild = NULL;
	E.lchild = &F;
	E.rchild = &G;
	F.lchild = F.rchild = G.lchild = G.rchild = NULL;
    AncestoPath(&A,&H);

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

