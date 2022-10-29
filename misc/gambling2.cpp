////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int life;
    cin>>life;
    while(life--)
    {
        int n;
        cin>>n;
        int a[n];
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<int>dp(n,1);
        int mx=0;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(a[i])!=mp.end())
            {
                dp[i]=max(dp[i],dp[mp[a[i]]]+1-(i-mp[a[i]]-1));
            }
            if(dp[i]>mx)
            {
                mx=dp[i];
                idx=i;
            }
            mp[a[i]]=i;
        }
        int r=idx,l=idx;
        int p=a[idx];
        while(mx)
        {
            if(a[l]==p)
            {
                mx--;
            }
            else
            {
                mx++;
            }
            l--;
        }
        cout<<p<<' '<<l+2<<' '<<r+1<<'\n';
    }
}
// 4
// 5
// 4 4 3 4 4
// 5
// 11 1 11 1 11
// 1
// 1000000000
// 10
// 8 8 8 9 9 6 6 9 6 6
// 4 1 5
// 11 1 1
// 1000000000 1 1
// 8 1 3