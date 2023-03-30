#include<bits/stdc++.h>
using namespace std;

int C1(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}

int C2(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

/*
const int NMAX = 100;
int C[NMAX + 1][NMAX + 1];
*/


int main()
{
    /*
    C[0][0] = 1;
    for (int n = 1; n <= NMAX; ++n) 
    {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
        {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
            //C[n][k]%=mod;
        }
    }
    */
}