#include<bits/stdc++.h>
using namespace std;
void add_mat(vector<vector<int> > A,vector<vector<int> > B,vector<vector<int> >& RES,int split)
{
    for (auto i = 0; i < split; i++)
        for (auto j = 0; j < split; j++)
            RES[i][j] = A[i][j] + B[i][j];
}
vector<vector<int>> sq_matmul(vector<vector<int>>A, vector<vector<int>>B)
{
    int col=A[0].size();
    vector<int>res(col,0);
    vector<vector<int>>RES(col,res);
    if(col==1)
    {
        RES[0][0]=A[0][0]*B[0][0];
    }
    else
    {
        int split=col/2;
        vector<int>res1(split,0);
        vector<vector<int>>RES00(split,res1);
        vector<vector<int>>RES01(split,res1);
        vector<vector<int>>RES10(split,res1);
        vector<vector<int>>RES11(split,res1);

        vector<vector<int>>A00(split,res1);
        vector<vector<int>>A01(split,res1);
        vector<vector<int>>A10(split,res1);
        vector<vector<int>>A11(split,res1);
        vector<vector<int>>B00(split,res1);
        vector<vector<int>>B01(split,res1);
        vector<vector<int>>B10(split,res1);
        vector<vector<int>>B11(split,res1);

        for(int i=0;i<split;i++)
        {
            for(int j=0;j<split;j++)
            {
                A00[i][j]=A[i][j];
                A01[i][j]=A[i][j+split];
                A10[i][j]=A[i+split][j];
                A11[i][j]=A[i+split][j+split];

                B00[i][j]=B[i][j];
                B01[i][j]=B[i][j+split];
                B10[i][j]=B[i+split][j];
                B11[i][j]=B[i+split][j+split];
            }
        }
        add_mat(sq_matmul(A00,B00),sq_matmul(A01,B10),RES00,split);
        add_mat(sq_matmul(A00,B01),sq_matmul(A01,B11),RES01,split);
        add_mat(sq_matmul(A10,B00),sq_matmul(A11,B10),RES10,split);
        add_mat(sq_matmul(A10,B01),sq_matmul(A11,B11),RES11,split);

        for(int i=0;i<split;i++)
        {
            for(int j=0;j<split;j++)
            {
                RES[i][j]=RES00[i][j];
                RES[i][j+split]=RES01[i][j];
                RES[i+split][j]=RES10[i][j];
                RES[i+split][j+split]=RES11[i][j];
            }
        }
    }
    return RES;
}
int main()
{
    vector<vector<int>>A={ { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 2, 2, 2, 2 } };
    vector<vector<int>>B={ { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 2, 2, 2, 2 } };
    vector<vector<int>>C=sq_matmul(A,B);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<C[i][j]<<' ';
        }
        cout<<'\n';
    }
}
