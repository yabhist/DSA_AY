#include<bits/stdc++.h>
using namespace std;
void recur(int s[], int f[], int k, int n)
{
    int m=k+1;
    while(m<=n && s[m]<f[k])
    {
        m++;
    }
    if(m<=n)
    {
        cout<<'a'<<m<<' ';
        recur(s,f,m,n);
    }
    else
    {
        return ;
    }
}
void iterative(int s[],int f[], int n)
{
    cout<<"a1"<<' ';
    int k=1;
    for(int m=2;m<=n;m++)
    {
        if(s[m]>=f[k])
        {
            cout<<'a'<<m<<' ';
            k=m;
        }
    }
    return;
}
void recur1(int s[], int f[], int k, int n)
{
    int m=k-1;
    while(m>=1 && f[m]>s[k])
    {
        m--;
    }
    if(m>=1)
    {
        recur1(s,f,m,n);
        cout<<'a'<<m<<' ';
    }
    else
    {
        return ;
    }
}
int main()
{
    int s[]={-1,1,3,0,5,3,5,6,8,8,2,12};
    int f[]={0,4,5,6,7,9,9,10,11,12,14,16};
    recur(s,f,0,11);
    cout<<'\n';
    iterative(s,f,11);
    cout<<'\n';

    int s1[]={-1,0,1,2,3,3,5,5,6,8,8,12,100};
    int f1[]={0,6,4,14,5,9,7,9,10,11,12,16,100};
    recur1(s1,f1,12,11);
    cout<<'\n';
}