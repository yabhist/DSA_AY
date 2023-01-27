#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a={-1,1,5,3,7,8,6};
    int n=a.size()-1;
    int sum=accumulate(a.begin()+1,a.end(),0);
    vector<vector<bool>>dp(n+1,vector<bool>(1001));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int j=1;j<=sum;j++)
    {
        dp[0][j]=false;;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<a[i])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i]];
            }
        }
    }
    int x=17;
    vector<int>v1;
    if(dp[n][x])
    {
        for(int i=n;i>=1;i--)
        {
            if(x==0)
            {
                break;
            }
            if(x-a[i]>=0 && dp[i-1][x-a[i]])
            {
                v1.push_back(a[i]);
                x-=a[i];
            }  
        }
    }
    else
    {
        cout<<-1<<'\n';
        return 0;
    }
    for(auto i:v1)
    {
        cout<<i<<' ';
    }cout<<'\n';
}