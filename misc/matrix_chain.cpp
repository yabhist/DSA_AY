#include<bits/stdc++.h>
using namespace std;
void opt_cost(int p[], int n, vector<vector<int>>&s, vector<vector<int>>&m)
{
    for(int i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    for(int l=2;l<=n-1;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
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
    if(i==j)
    {
        cout<<'A'<<i;
    }
    else
    {
        cout<<'(';
        print_sol(s,i,s[i][j]);
        print_sol(s,s[i][j]+1,j);
        cout<<')';
    }
}
int main()
{
    int p[]={5,10,3,12,5,50,6};
    vector<vector<int>>m(7,vector<int>(7,INT_MAX)),s(7,vector<int>(7,INT_MAX));
    opt_cost(p,7,s,m);
    cout<<m[1][6]<<'\n';
    print_sol(s,1,6);
}