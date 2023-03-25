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

vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

vector<int> phi_1_to_n_divisor_sum(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
    return phi;
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

int binpow_totient_not_coprime(int a, int b, int m, int tot)
{
    // a, m not coprime
    // tot is phi(m) (phi(m) is always >= log2(m))
    // b>=log2(m)
    a %= m;
    long long res = 1;
    b=tot+(b%tot);
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
    