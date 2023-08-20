#include<bits/stdc++.h>
using namespace std;
/*
const int NMAX=2e5,mod=998244353;
int factmod[NMAX+5],invmod[NMAX+5],invfactmod[NMAX+5];

int BC(int n, int k)
{
    return factmod[n] * invfactmod[k] % mod * invfactmod[n-k] % mod;
}
*/

int factorial_mod(int n, int p) {
    //If you need to call the function multiple times, then you can do the precomputation outside of the function
    //p relatively small than n
    //p is prime
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

int multiplicity_factorial(int n, int p) {// p is prime
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}

int multiplicity_factorial_composite(int n, int k)
{
    vector<pair<int,int>>v;
    for(int i=2;i*i<=k;i++)
    {
        if(k%i==0)
        {
            int ct=0;
            while(k%i==0)
            {
                k/=i;
                ct++;
            }
            v.push_back({i,ct});
        }
    }
    if(k>1)
    {
        v.push_back({k,1});
    }
    
    int ans=1e9;
    for(int i=0;i<v.size();i++)
    {
        ans=min(ans,multiplicity_factorial(n,v[i].first)/v[i].second);
    }
    return (ans==1e9)?0:ans;
}

int main()
{
    //mod is coprime with each from 1 to NMAX
    /*
    factmod[0]=invmod[0]=invfactmod[0]=factmod[1]=invmod[1]=invfactmod[1]=1;
    for(int i=2;i<=NMAX;i++) factmod[i] = factmod[i-1] * i % mod;
    for(int i=2;i<=NMAX;i++) invmod[i] = mod - mod / i * invmod[mod%i] % mod;
    for(int i=2;i<=NMAX;i++) invfactmod[i] = invfactmod[i-1] * invmod[i] % mod;

    factmod[0] = 1;
    for(int i = 1; i <= NMAX; i++) factmod[i] = factmod[i - 1] * i % mod;
    invfactmod[NMAX] = binpow_mod(factmod[NMAX], mod - 2);
    for(int i = NMAX - 1; i >= 0; i--) invfactmod[i] = invfactmod[i + 1] * (i + 1) % mod;
    */

    cout<<multiplicity_factorial_composite(6,4)<<'\n';
    cout<<multiplicity_factorial_composite(1,4)<<'\n';
    cout<<multiplicity_factorial_composite(3,4)<<'\n';
}
