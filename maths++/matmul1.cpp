#include<bits/stdc++.h>
using namespace std;
int main()
{
    int M1[3][3]={{2,3,3},{6,1,5},{9,4,1}};
    int M2[3][3]={{4,3,2},{1,5,1},{2,2,2}};
    int M3[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            M3[i][j]=0;
            for(int k=0;k<3;k++)
            {
                M3[i][j]+=M1[i][k]*M2[k][j];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<M3[i][j]<<' ';
        }
        cout<<'\n';
    }
}