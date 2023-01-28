#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>a(n+1,vector<int>(m+1)),pref(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
        }
    }
    for(auto i:pref)
    {
        for(auto j:i)
        {
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    int i1=2,j1=3;
    int i2=5,j2=5;
    cout<<pref[i2][j2]-pref[i1-1][j2]-pref[i2][j1-1]+pref[i1-1][j1-1];
}
// 5 6
// 1 9 4 6 5 8
// 10 9 5 8 11 6
// 24 42 32 8 11 1
// 23 1 9 69 13 3
// 13 22 60 12 14 17