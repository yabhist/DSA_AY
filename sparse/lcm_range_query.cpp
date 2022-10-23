#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5,k=20;
ll sparse[N][k];
ll __lcm(ll a, ll b)
{
    return (a*b)/(__gcd(a,b));
}
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
            sparse[i][j]=__lcm(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(int l, int r)
{
    ll ans=1;
    for(int j=k;j>=0;j--)
    {
        if((1<<j)<=r-l+1)
        {
            ans=__lcm(sparse[l][j],ans);
            l+=(1<<j);
        }
    }
    return ans;
}
int main()
{
    int arr[] = { 5,7,5,2,10,12,11,17,14,1,44 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    build_sparse(arr, n);
 
    cout << query(2, 5) << endl;
    cout << query(5, 10) << endl;
    cout << query(0, 10) << endl;
 
    return 0;

}