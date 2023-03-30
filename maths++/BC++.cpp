#include<bits/stdc++.h>
using namespace std;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int binpow_totient(int a ,int b, int m, int tot)
{
    // a, m coprime
    // tot is phi(m)
    a %= m;
    long long res = 1;
    b=b%tot;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int mod_inverse(int a, int m, int tot)// a,m coprime
{
    //tot is phi(m)
    return binpow_totient(a,tot-1,m,tot);
}

int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
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
    extended_euclidean(v, m, x, y);
    x = (x % m + m) % m;
    for (int i = n - 1; i >= 0; --i) {
        b[i] = static_cast<long long>(x) * b[i] % m;
        x = static_cast<long long>(x) * a[i] % m;
    }
    return b;
}

int BC_mod_prime_power(int n, int k, int m, int p, int b)//p prime and <=max(n,n-k), m=p^b
{
    vector<int>magic(n+1);
    for(int i=1;i<=n;i++)
    {
        int tmp=i;
        if(tmp%p==0)
        {
            int ct=0;
            while(tmp%p==0)
            {
                tmp/=p;
                ct++;
            }
            magic[i]=ct;
        }
    }

    vector<int>c(n+1);
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i-1]+magic[i];
    }
    if(c[n]-c[k]-c[n-k]>=b)
    {
        return 0;
    }

    vector<int>g(n+1);
    g[0]=1;
    for(int i=1;i<=n;i++)
    {
        g[i]=g[i-1]*i;
        for(int j=0;j<magic[i];j++)
        {
            g[i]/=p;
        }
        g[i]%=m;
    }

    vector<int>ppow(b);
    ppow[0]=1;
    for(int i=1;i<b;i++)
    {
        ppow[i]=ppow[i-1]*p;
    }

    return g[n] * ppow[c[n]-c[k]-c[n-k]] % m * mod_inverse(g[k]*g[n-k]%m ,m ,phi(m)) % m;

    // vector<int>pre_g_invs=invs(g,m);
    // return g[n] * ppow[c[n]-c[k]-c[n-k]] % m * pre_g_invs[k] % m * pre_g_invs[n-k] % m;
}

struct Congruence {
    int a, m;
};

int chinese_remainder_theorem(vector<Congruence> const& congruences) {
    int M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    int solution = 0;
    for (auto const& congruence : congruences) {
        int a_i = congruence.a;
        int M_i = M / congruence.m;
        int N_i = mod_inverse(M_i, congruence.m, phi(congruence.m));
        solution = (solution + a_i * M_i % M * N_i % M) % M;
    }
    return solution;
}

int BC_mod_arbitrary(int n, int k, int m)
{
    vector<Congruence>congruences;
    for(int i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            int tmp=1;
            int ct=0;
            while(m%i==0)
            {
                m/=i;
                tmp*=i;
                ct++;
            }
            congruences.push_back({BC_mod_prime_power(n,k,tmp,i,ct),tmp});
        }
    }
    if(m>1)
    {
        congruences.push_back({BC_mod_prime_power(n,k,m,m,1),m});
    }

    return chinese_remainder_theorem(congruences);
}

int main()
{
    cout<<BC_mod_prime_power(20,2,64,2,6)<<'\n';
    cout<<BC_mod_prime_power(15,6,27,3,3)<<'\n';
    cout<<BC_mod_arbitrary(20,2,12)<<'\n';
}