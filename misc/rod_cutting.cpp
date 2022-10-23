#include<bits/stdc++.h>
using namespace std;
int inefficient(int p[],int n)
{
    if(n==0)
    {
        return 0;
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,p[i]+inefficient(p,n-i));
    }
    return ans;
}
int main()
{
    int p[]={-1,1,5,8,9,10,17,17,20,24,30};
    cout<<inefficient(p,4);
}