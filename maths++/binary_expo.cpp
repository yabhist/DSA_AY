#include<bits/stdc++.h>
using namespace std;
//
long long binpow(long long a, long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
long long binpow_recur(long long a, long long b)
{
    if(b==0)
    {
        return 1;
    }
    long long res=binpow_recur(a,b/2);
    if(b&1)
    {
        return res*res*a;
    }
    return res*res;
}
long long binpow_fermat(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    b=b%(m-1);
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
long long two_mult_mod_recur(long long a, long long b, long long m)
{
    b%=m;
    if(a==0)
    {
        return 0;
    }
    long long res=two_mult_mod_recur(a/2,b,m);
    if(a&1)
    {
        res=(((res*2)%m)+b)%m;//2*res does not cause overflow
    }
    else
    {
        res=(res*2)%m;
    }
    return res;
}
long long two_mult_mod(long long a, long long b, long long m)
{
    b%=m;
    long long res=0;
    while(a)
    {
        if(a&1)
        {
            res=(res+b)%m;
        }
        b=(2*b)%m;
        a>>=1;
    }
    return res;
}
int main()
{
    cout<<binpow(3,7)<<'\n';
    cout<<binpow_recur(3,7)<<'\n';
    cout<<binpow_fermat(15,75,37)<<'\n';
    cout<<two_mult_mod(100,54,87)<<'\n';
    cout<<two_mult_mod_recur(9e18,9e18,1531)<<'\n';
}