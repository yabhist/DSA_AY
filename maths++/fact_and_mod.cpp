#include<bits/stdc++.h>
using namespace std;

const int NMAX=2e5,mod=998244353;
int factmod[NMAX],invmod[NMAX],invfactmod[NMAX];

int BC(int n, int k)
{
    return factmod[n] * invfactmod[k] % mod * invfactmod[n-k] % mod;
}

int binpow_fermat(int a, int b, int m) {
    a %= m;
    int res = 1;
    b=b%(m-1);
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int mod_inverse(int a, int m)
{
    return binpow_fermat(a,m-2,m);
}

int factorial_mod(int n, int p) {
    //If you need to call the function multiple times, then you can do the precomputation outside of the function
    //p relatively small than n
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

int multiplicity_factorial(int n, int p) {
    int count = 0;
    do {
        n /= p;
        count += n;
    } while (n);
    return count;
}

std::vector<int> invs(const std::vector<int> &a, int m) {
    //we are given an array and we want to find modular inverse for all numbers in it (all of them are invertible)
    int n = a.size();
    if (n == 0) return {};
    std::vector<int> b(n);
    int v = 1;
    for (int i = 0; i != n; ++i) {
        b[i] = v;
        v = static_cast<long long>(v) * a[i] % m;
    }
    int x, y;
    //extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

int main()
{
    factmod[0]=invmod[0]=invfactmod[0]=factmod[1]=invmod[1]=invfactmod[1]=1;
    for(int i=2;i<NMAX;i++) factmod[i] = factmod[i-1] * i % mod;
    for(int i=2;i<NMAX;i++) invmod[i] = mod - mod / i * invmod[mod%i] % mod;
    for(int i=2;i<NMAX;i++) invfactmod[i] = invfactmod[i-1] * invmod[i] % mod;
}
