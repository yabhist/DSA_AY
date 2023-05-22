////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/  

#include<bits/stdc++.h>
using namespace std;

typedef int I;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

#define int long long
const int mx=1e6;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>>store(mx+5);
    for(int k=1;k<=mx;k++)
    {
        for(int i=k;i<=mx;i+=k)
        {
            store[i].push_back(k);
        }
    }
    int ans=0;
    for(int i=1;i<=mx;i++){
        ans+=store[i].size();
    }
    cout<<ans<<'\n';
    for(int i=1;i<=100;i++)
    {
        cout<<i<<'\n';
        for(auto j:store[i])
        {
            cout<<j<<' ';
        }cout<<'\n';
    }
}