#include<bits/stdc++.h>
using namespace std;
int M1[2][3]={{2,3,1},{6,1,3}};
int M2[3][2]={{4,3},{1,5},{5,2}};
int M3[2][2]={0};
void matmul()
{
    static int i=0,j=0,k=0;
    if(i>=2)
    {
        return;
    }
    
    if(j<2)
    {
        if(k<3)
        {
            M3[i][j]+=M1[i][k]*M2[k][j];
            k++;
            matmul();
        }
        k=0;
        j++;
        matmul();
    }
    j=0;
    i++;
    matmul();
}
int main()
{
    matmul();
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<M3[i][j]<<' ';
        }
        cout<<'\n';
    }
}