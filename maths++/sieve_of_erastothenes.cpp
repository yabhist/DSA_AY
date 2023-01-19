#include<bits/stdc++.h>
using namespace std;
int main()
{
    int mx=1e5;
    bool prime[mx+1];
    memset(prime,true,sizeof(prime));
    prime[0]=false,prime[1]=false;
    for(int i=2;i*i<=mx;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=mx;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    int ct=0;
    for(int i=1;i<=mx;i++)
    {
        if(prime[i])
        {
            ct++;
            cout<<i<<' ';
        }
    }
    cout<<'\n';
    cout<<ct<<'\n';
}