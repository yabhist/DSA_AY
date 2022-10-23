#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool prime[101];
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for(int i=2;i*i<=100;i++)
    {
        for(int j=i*i;j<=100;j+=i)
        {
            prime[j]=false;
        }
    }
    for(int i=1;i<=100;i++)
    {
        if(prime[i])
        {
            cout<<i<<' ';
        }
    }
    cout<<'\n';
}