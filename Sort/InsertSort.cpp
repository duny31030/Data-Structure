/*
 * ===================================================================
 *
 *       Filename:  InsertSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/16 22时51分02秒
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

// 插入排序 [1-n]
void InsertSort(ElemType A[],int n)
{
	int i,j;
	for(i = 2;i <= n;i++)
	{
		if(A[i] < A[i-1])
		{
			A[0] = A[i];
			for(j = i;A[0] < A[j-1];j--)
				A[j] = A[j-1];
			A[j-1] = A[0];
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

