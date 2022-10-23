#include<bits/stdc++.h>
using namespace std;
void add_mat(vector<vector<int> > A,vector<vector<int> > B,vector<vector<int> > &RES,int rres,int cres)
{
    int n=A.size();
    for (auto i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            RES[i+rres][j+cres] = A[i][j] + B[i][j];
}
vector<vector<int>> sq_matmul(vector<vector<int>>&A, vector<vector<int>>&B, int ra, int ca, int rb, int cb ,int size)
{
    vector<int>res(size,0);
    vector<vector<int>>RES(size,res);
    if(size==1)
    {
        RES[0][0]=A[ra][ca]*B[rb][cb];
    }
    else
    {
        int newsize=size/2;
        add_mat(sq_matmul(A,B,ra,ca,rb,cb,newsize),sq_matmul(A,B,ra,ca+newsize,rb+newsize,cb,newsize),RES,0,0);
        add_mat(sq_matmul(A,B,ra,ca,rb,cb+newsize,newsize),sq_matmul(A,B,ra,ca+newsize,rb+newsize,cb+newsize,newsize),RES,0,newsize);
        add_mat(sq_matmul(A,B,ra+newsize,ca,rb,cb,newsize),sq_matmul(A,B,ra+newsize,ca+newsize,rb+newsize,cb,newsize),RES,newsize,0);
        add_mat(sq_matmul(A,B,ra+newsize,ca,rb,cb+newsize,newsize),sq_matmul(A,B,ra+newsize,ca+newsize,rb+newsize,cb+newsize,newsize),RES,newsize,newsize);
    }
    return RES;
}
int main()
{
    vector<vector<int>>A={ { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 2, 2, 2, 2 } };
    vector<vector<int>>B={ { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 2, 2, 2, 2 } };
    vector<vector<int>>C=sq_matmul(A,B,0,0,0,0,4);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<C[i][j]<<' ';
        }
        cout<<'\n';
    }
}
