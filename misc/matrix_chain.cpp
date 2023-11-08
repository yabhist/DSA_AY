#include<bits/stdc++.h>
using namespace std;
void opt_cost(int p[], int n, vector<vector<int>>&s, vector<vector<int>>&m)
{
    for(int i=0;i<n-1;i++)
    {
        m[i][i+1]=0;
    }
    for(int l=3;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                int q=m[i][k] + m[k][j] + p[i]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}
void print_sol(vector<vector<int>>&s, int i, int j)
{
    if(j-i==1)
    {
        cout<<'A'<<i+1;
    }
    else
    {
        cout<<'(';
        print_sol(s,i,s[i][j]);
        print_sol(s,s[i][j],j);
        cout<<')';
    }
}
int main()
{
    int p[]={5,10,3,12,5,50,6};
    vector<vector<int>>m(7,vector<int>(7,INT_MAX)),s(7,vector<int>(7,INT_MAX));
    opt_cost(p,7,s,m);
    cout<<m[0][6]<<'\n';
    print_sol(s,0,6);
}