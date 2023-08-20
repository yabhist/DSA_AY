#include<bits/stdc++.h>
using namespace std;
//my laptop is the best

vector<char> segmentedSieve(long long L, long long R) {
    // prime numbers in range [L,R] R-L+1~1e7 R(e.g. 1e12)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

int main()
{
    int mx=32000;
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

    /*
    vector<ll>pFactorOf(mx+1);
    iota(pFactorOf.begin(),pFactorOf.end(),0ll);
    for(int i=2;i*i<=mx;i++)
	{
		if((pFactorOf[i]==i))
		{
			for(int j=i*i;j<=mx;j+=i)
			{
				if(pFactorOf[j]==j) pFactorOf[j]=i;
			}
		}
	}
    */

    /* Linear Sieve
    const int N = 10000000;
    vector<int> lp(N+1);
    vector<int> pr;

    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    */
}