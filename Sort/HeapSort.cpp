/*
 * ===================================================================
 *
 *       Filename:  HeapSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/08 18时28分19秒
 *
 *         Author:  duny31030 , duny31030@126.com
 *   Organization:  duny31030.top
 *
 * ===================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef int ElemType;


// 建立大根堆(小根堆同理)
void HeapSort(ElemType A[],int n);
void BuildHeapSort(ElemType A[],int n);
void AdjustDown(ElemType A[],int k,int n);
void AdjustUp(ElemType A[],int k,int n);
void swap(ElemType &a,ElemType &b);

void BuildHeapSort(ElemType A[],int n)
{
	for(int i = n/2;i >= 1;i--)
		AdjustDown(A,i,n);
	for(int i = n;i > 1;i--)
	{
		swap(A[i],A[1]);
		AdjustDown(A,1,i-1);
	}
}


// 向下调整堆
// 每次选择一个更小的孩子
// 然后将这个孩子上移
// 直至无法再进行移动
void AdjustDown(ElemType A[],int k,int n)
{
	A[0] = A[k];
	for(int i = k*2;i <= n;i*=2)
	{
		if(i<n && A[i] < A[i+1])
			i++;
		if(A[0] >= A[i])
			break;
		else 
			A[k] = A[i];
		k = i;
	}
	A[k] = A[0];
}

// 向上调整堆
// 此时堆必定为大根堆
// 所以并不需要跟自己的兄弟结点比较大小
// 可以直接与双亲比较然后调整
void AdjustUp(ElemType A[],int k)
{
	A[0] = A[k];
	int i = k/2;
	while(i>0 && A[i] < A[k])
	{
		A[k] = A[i];
		k = i;
		i = k/2;
	}
	A[i] = A[0];
}

void swap(ElemType &a,ElemType &b)
{
	int c = a;	a = b;	b = c;
}

int main()
{
    // ios
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        // freopen("out.txt","w:",stdout);
    #endif

    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

