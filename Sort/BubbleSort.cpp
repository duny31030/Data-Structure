/*
 * ===================================================================
 *
 *       Filename:  BubbleSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/08 17时18分03秒
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

void swap(ElemType &a,ElemType &b)
{
	ElemType c;
	c = a;	a = b;	b = c;
}

// 冒泡排序
void BubbleSort(ElemType A[],int n)
{
	bool flag = true;
	for(int i = 1;i < n && flag;i++)
	{
		flag = false;
		for(int j = n;j > i;j--)
		{
			if(A[j] < A[j-1])
			{
				swap(A[j],A[j-1]);
				flag = true;
			}
		}
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
	ElemType A[10];
	rep(i,1,9)	A[i] = 10-i;
	BubbleSort(A,9);
	rep(i,1,9)	printf("%d ",A[i]);
	printf("\n");
    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

