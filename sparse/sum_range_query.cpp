#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5,k=18;
ll sparse[N][k];
void build_sparse(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        sparse[i][0]=a[i];
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            sparse[i][j]=sparse[i][j-1]+sparse[i+(1<<(j-1))][j-1];
        }
    }
}
ll query(int l, int r)
{
    ll ans=0;
    for(int j=k;j>=0;j--)
    {
        if((1<<j)<=r-l+1)
        {
            ans+=sparse[l][j];
            l+=(1<<j);
        }
    }
    return ans;
}
int main()
{
    int arr[] = { 3, 7, 2, 5, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    build_sparse(arr, n);
 
    cout << query(0, 5) << endl;
    cout << query(3, 5) << endl;
    cout << query(2, 4) << endl;
 
    return 0;

}