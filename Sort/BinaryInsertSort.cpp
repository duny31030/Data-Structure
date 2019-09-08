/*
 * ===================================================================
 *
 *       Filename:  BinaryInsertSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/09/08 17时28分17秒
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

// 折半插入排序
void BinaryInsertSort(ElemType A[],int n)
{
	int i,j,low,high,mid;
	for(i = 2;i <= n;i++)
	{
		A[0] = A[i];
		low = 1,high = i-1;
		while(low <= high)
		{
			mid = (low+high)/2;
			if(A[mid] > A[0])
				high = mid-1;
			else 
				low = mid+1;
		}
		for(j = i;j > mid;j--)
			A[j] = A[j-1];
		A[j] = A[0];
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
	int A[10];
	rep(i,1,9)	A[i] = 10-i+2;
	BinaryInsertSort(A,9);
	rep(i,1,9)	printf("%d ",A[i]);
	printf("\n");

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

