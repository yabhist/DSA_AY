#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>>sparse(10,vector<vector<int>>(10,vector<int>(4)));
void build_sparse(vector<vector<int>>&a , int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sparse[i][j][0]=a[i][j];
        }
    }
    for(int k=1;(1<<k)<=min(n,m);k++)
    {
        for(int i=0;i+(1<<k)<=n;i++)
        {
            for(int j=0;j+(1<<k)<=m;j++)
            {
                sparse[i][j][k]=min({sparse[i][j][k-1],sparse[i+(1<<(k-1))][j][k-1],sparse[i][j+(1<<(k-1))][k-1],sparse[i+(1<<(k-1))][j+(1<<(k-1))][k-1]});
            }
        }
    }
}
int query(int qi, int qj, int sz)
{
    int temp=sz;
    int k=-1;
    while(temp!=0)
    {
        k++;
        temp>>=1;
    }
    
    return min({sparse[qi][qj][k],sparse[qi+sz-(1<<k)][qj][k],sparse[qi][qj+sz-(1<<k)][k],sparse[qi+sz-(1<<k)][qj+sz-(1<<k)][k]});
    
}
int main()
{
    
    vector<vector<int>>a = { {1 ,9, 4, 6, 5, 8} , {10 ,9, 5, 8, 11, 6} , {24 ,32, 42, 8, 11, 8} , {12 ,93, 23, 1, 7, 32} , {1 ,29, 41, 39, 15, 4} };
    build_sparse(a,5,6);
    for(auto i:sparse)
    {
        for(auto j:i)
        {
            for(auto k:j)
            {
                cout<<k<<' ';
            }
            cout<<'\n';
        }
    }
    cout<<'\n';
    cout<<query(0,0,3)<<'\n';
    cout<<query(3,4,2)<<'\n';
    cout<<query(2,3,1)<<'\n';

}