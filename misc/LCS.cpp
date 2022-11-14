#include<bits/stdc++.h>
using namespace std;
void lcs_len(char x[],int m, char y[],int n,vector<vector<char>>&b,vector<vector<int>>&c)
{
    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(int i=0;i<=n;i++)
    {
        c[0][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
}
void print_lcs(vector<vector<char>>&b, char x[], int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]=='d')
    {
        print_lcs(b,x,i-1,j-1);
        cout<<x[i]<<' ';
    }
    else if(b[i][j]=='u')
    {
        print_lcs(b,x,i-1,j);
    }
    else
    {
        print_lcs(b,x,i,j-1);
    }
    return;
}
int main()
{
    char x[]={'\0','A','B','C','B','D','A','B'};
    char y[]={'\0','B','D','C','A','B','A'};
    vector<vector<int>>c(8,vector<int>(7));
    vector<vector<char>>b(8,vector<char>(7));
    lcs_len(x,7,y,6,b,c);
    cout<<c[7][6]<<'\n';
    print_lcs(b,x,7,6);
}