#include<bits/stdc++.h>
using namespace std;
int ineff_mat_ch(int p[],vector<vector<int>>m, int n, int i, int j)
{
    if(i==j)
    {
        return 0;
    }
    m[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int q=ineff_mat_ch(p,m,n,i,k)+ineff_mat_ch(p,m,n,k+1,j)+p[i-1]*p[k]*p[j];
        if(q<m[i][j])
        {
            m[i][j]=q;
        }
    }
    return m[i][j];
}
int lookup_chain(int p[], vector<vector<int>>&m, int n ,int i, int j)
{
    if(m[i][j] < INT_MAX)
    {
        return m[i][j];
    }
    if(i==j)
    {
        m[i][j]=0;
    }
    else
    {
        for(int k=i;k<j;k++)
        {
            int q=lookup_chain(p,m,n,i,k)+lookup_chain(p,m,n,k+1,j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j])
            {
                m[i][j]=q;
            }
        }
    }
    return m[i][j];
}
int main()
{
    int p[]={5,10,3,12,5,50,6};
    vector<vector<int>>m(7,vector<int>(7,INT_MAX));
    cout<<ineff_mat_ch(p,m,7,1,6)<<'\n';
    cout<<lookup_chain(p,m,7,1,6)<<'\n';
}