#include<bits/stdc++.h>
using namespace std;
int top_down_aux(int p[], int n, int r[])
{
    if(r[n]>=0)
    {
        return r[n];
    }
    int ans;
    if(n==0)
    {
        ans=0;
    }
    else
    {
        ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,p[i]+top_down_aux(p,n-i,r));
        }
    }
    r[n]=ans;
    return ans;
}
int top_down(int p[],int n )
{
    int r[n+1];
    fill_n(r,n+1,INT_MIN);
    return top_down_aux(p,n,r);
}
int bottom_up(int p[], int n)
{
    int r[n+1];
    r[0]=0;
    for(int j=1;j<=n;j++)
    {
        int ans=INT_MIN;
        for(int i=1;i<=j;i++)
        {
            ans=max(ans,p[i]+r[j-i]);
        }
        r[j]=ans;
    }
    return r[n];
}
int main()
{
    int p[]={-1,1,5,8,9,10,17,17,20,24,30};
    cout<<top_down(p,4)<<'\n';
    cout<<bottom_up(p,4)<<'\n';
}