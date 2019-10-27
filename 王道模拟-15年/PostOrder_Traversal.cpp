#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;

const int N = 1e4+100;

typedef struct BiTNode
{
	ElemType data;			// 数据域
	struct BiTNode *lchild;	// 左孩子指针
	struct BiTNode *rchild;	// 右孩子指针
}BTNode,*BiTree;
// 树的节点 为了方便测试与建树写成全局变量
BiTNode A,B,C,D,E,F,G,H;

// 非递归后序遍历二叉树
// 传入的参数为根节点
int PostOrder_Traversal(BTNode *b)
{
	// 首先建栈
	// 数组模拟
	BTNode *st[N];
	// 辅助节点,判断是否扫描完右子树
	BTNode *p;
	// 用于标记是否进入了右子树
	bool flag;
	// 栈顶
	int top = -1;
	do 
	{
		// 首先走到叶子节点
		while(b != NULL)
		{
			st[++top] = b;
			b = b->lchild;
		}
		p = NULL;
		flag = true;
		// 如果还未进入右子树
		// 且栈不为空
		while(top != -1 && flag)
		{
			b = st[top];
			// 如果右子树为空
			// 表示现在已经走到右下角了
			if(b->rchild == p)
			{
				printf("%c ",b->data);
				top--;
				p = b;
			}
			// 右子树不为空就往右子树走
			// 然后跳出while 
			// 一直往左下走到叶子节点再进入while
			else 
			{
				b = b->rchild;
				flag = 0;
			}
		}
	}
	while(top != -1);	// 如果栈非空
	return 0;
}

void BuildTree();
int main()
{
	BuildTree();
	PostOrder_Traversal(&A);
	return 0;
}

void BuildTree()
{
	A.data = 'A';	B.data = 'B';	C.data = 'C';	
	D.data = 'D';	E.data = 'E';	F.data = 'F';	
	G.data = 'G';	H.data = 'H';
	A.lchild = &B;	A.rchild = &D;	B.lchild = NULL;
	B.rchild = &C;	C.lchild = NULL;C.rchild = NULL;
	D.lchild = &E;	D.rchild = &H; 	E.lchild = &F;
	E.rchild = &G;	H.lchild = H.rchild = NULL;
	F.lchild = F.rchild = G.lchild = G.rchild = NULL;
}
