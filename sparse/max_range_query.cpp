#include<bits/stdc++.h>
using namespace std;
#define MAX 500
int sparse[MAX][MAX];

void build_sparse(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        sparse[i][0]=a[i];
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            sparse[i][j]=max(sparse[i][j-1] , sparse[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l, int r)
{
    int j = (int)log2(r-l+1);
    return max(sparse[l][j] , sparse[r-(1<<j)+1][j]);
}
int main()
{
    
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    build_sparse(a, n);
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;

}