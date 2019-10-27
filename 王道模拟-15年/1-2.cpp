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

/*
 * 题面
 * 假设二叉树采用二叉链表存储结构，设计一个算法，求出根节点到给定节点之间的路径
 * 要求：
 *	1. 给出算法的基本设计思想
 *	2. 写出二叉树采用的存储结构代码
 *	3. 根据设计思想，采用C或C++语言描述算法，关键之处给出注释
 */

/*
 * 1. 由二叉树后序遍历的特点我们可以知道
 *    当遍历到某一个节点时,栈中所有节点都是该节点的祖先
 *    而从栈底到栈顶正式从根节点到该节点的路径
 *    所以在非递归后序遍历算法的基础上稍作修改就可完成
 */

/* 
 * 2.
 */
typedef struct BiTNode
{
	ElemType data;						// 数据域
	struct BiTNode *lchild,*rchild;		// 左、右孩子指针
}BTNode,*BiTree;

/*
 * 3.
 */

// 采用传入的两个参数为：
// 二叉树的根节点
// 二叉树的目标节点
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
		// p指向当前节点的前一个已访问节点
		p = NULL;
		// 设置b的访问标记为已访问
		flag = 1;
		while(top != -1 && flag)
		{
			// 取栈顶元素
			b = st[top];
			// 如果右子树已访问过或者右子树为空
			if(b->rchild == p)
			{
				// 如果找到了目标节点
				if(b == s)
				{
					// 输出路径
					for(i = 0;i <= top;++i)
						printf("%d ",st[i]->data);
					return 1;
				}
				else 
				{
					top--;
					// p指向刚才访问的节点
					p = b;
				}
			}
			else 
			{
				// b指向右子树
				b = b->rchild;
				// 设置未被访问标记
				flag = 0;
			}
		}
	}
	while(top != -1);	// 栈不空时循环
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

