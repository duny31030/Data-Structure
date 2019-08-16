/*
 * ===================================================================
 *
 *       Filename:  ShellSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/16 23时00分55秒
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

// 希尔排序
void ShellSort(ElemType A[],int n)
{
	// 与直接插入排序相比，做了以下修改
	// 1. 前后记录位置的增量是dk，不是1
	// 2. A[0]只是暂存单元，不是哨兵，当j<0时，插入位置已到
	for(int dk = n/2;dk >= 1;dk/=2)
	{
		for(int i = dk+1,j;i <= n;i++)
		{
			if(A[i] < A[i-dk])
			{
				A[0] = A[i];
				for(j = i;j-dk>0 && A[0] <A[j-dk];j-=dk)
					A[j] = A[j-dk];
				A[j] = A[0];
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

    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

