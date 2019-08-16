/*
 * ===================================================================
 *
 *       Filename:  QucikSort.cpp
 *
 *           Link:  
 *
 *        Created:  2019/08/16 17时48分52秒
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


int Partition(ElemType A[],int low,int high) 
{
	ElemType pivot = A[low];
	while(low < high) 
	{
		while(low<high && A[high] >= pivot) --high;
		printf("high = %d  ",high);
		A[low] = A[high];
		while(low<high && A[low] <= pivot) ++low;
		printf("low = %d  \n",low);
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void Print(ElemType A[])
{
	for(int i = 1;i <= 5;i++)
		printf("%d ",A[i]);
	printf("\n");
}

void QucikSort(ElemType A[],int low,int high) 
{
	if(low < high) 
	{
		Print(A);
		int pivotpos = Partition(A,low,high);
		QucikSort(A,low,pivotpos-1);
		QucikSort(A,pivotpos+1,high);
	}
	// Print(A);
}


int main()
{
    // ios
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
        // freopen("out.txt","w:",stdout);
    #endif

    ElemType A[20];
	A[1] = 100;	A[2] = 9;	A[3] = 103;	A[4] = 87;	A[5] = 8;
	A[6] = 12;	A[7] = 30;	A[8] = 44;	A[9] = 55;	A[10] = 2;
	QucikSort(A,1,5);
	Print(A);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

