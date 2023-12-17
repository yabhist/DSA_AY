// You are given an array a, consisting of n distinct integers a1,a2,…,an.
// Define the beauty of an array p1,p2,…pk as the minimum amount of time needed to 
// sort this array using an arbitrary number of range-sort operations. In each range-sort operation, 
// you will do the following:Choose two integers l and r (1≤l<r≤k).
// Sort the subarray pl,pl+1,…,pr in r−l seconds.
// Please calculate the sum of beauty over all subarrays of array a




/*
Brahman
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <complex>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x) ;cerr << '\n';
#else
#define debug(x);
#endif

typedef long long ll;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(bool t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


template<const ll& MOD>
struct Mint {
    using T = typename decay<decltype(MOD)>::type; T v;
    Mint(ll v = 0) { if(v < 0) v = v % MOD + MOD; if(v >= MOD) v %= MOD; this->v = T(v); }
    Mint(uint64_t v) { if (v >= MOD) v %= MOD; this->v = T(v); }
    Mint(int v): Mint(ll(v)) {}
    Mint(unsigned v): Mint(uint64_t(v)) {}
    explicit operator int() const { return v; }
    explicit operator ll() const { return v; }
    explicit operator uint64_t() const { return v; }
    friend istream& operator>>(istream& in, Mint& m) { ll v_; in >> v_; m = Mint(v_); return in; }
    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.v; }

    static T inv(T a, T m) {
        T g = m, x = 0, y = 1;
        while(a != 0) {
            T q = g / a;
            g %= a; swap(g, a);
            x -= q * y; swap(x, y);
        } return x < 0? x + m : x;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif // x must be less than 2^32 * m
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x), quot, rem;
        asm("divl %4\n" : "=a" (quot), "=d" (rem) : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    Mint inv() const { return Mint(inv(v, MOD)); }
    Mint operator-() const { return Mint(v? MOD-v : 0); }
    Mint& operator++() { v++; if(v == MOD) v = 0; return *this; }
    Mint& operator--() { if(v == 0) v = MOD; v--; return *this; }
    Mint operator++(int) { Mint a = *this; ++*this; return a; }
    Mint operator--(int) { Mint a = *this; --*this; return a; }
    Mint& operator+=(const Mint& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    Mint& operator-=(const Mint& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    Mint& operator*=(const Mint& o) { v = fast_mod(uint64_t(v) * o.v); return *this; }
    Mint& operator/=(const Mint& o) { return *this *= o.inv(); }
    friend Mint operator+(const Mint& a, const Mint& b) { return Mint(a) += b; }
    friend Mint operator-(const Mint& a, const Mint& b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint& a, const Mint& b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint& a, const Mint& b) { return Mint(a) /= b; }
    friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend bool operator!=(const Mint& a, const Mint& b) { return a.v != b.v; }
    friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }
    friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }
    friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }
    friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }
    Mint operator^(ll p) {
        if(p < 0) return inv() ^ -p;
        Mint a = *this, res{1}; while(p > 0) {
            if(p & 1) res *= a;
            p >>= 1; if(p > 0) a *= a;
        } return res;
    }
};

ll MOD = (ll)1e9 + 7;
// ll MOD = 998244353;

using mint = Mint<MOD>;

vector<mint> fact,ifact;

mint C(ll n, ll k) {
  if (n<0 || k < 0 || k > n) {
    return 0;
  }
  while ((ll) fact.size() < n + 1) {
    if (fact.empty()) {
      fact = ifact = {1};
      continue;
    }
    fact.push_back(fact.back() * (ll) fact.size());
    ifact.push_back(1 / fact.back());
  }
  return fact[n] * ifact[k] * ifact[n - k];
}


vector<vector<ll>>sparse;
ll n;
ll LGN;
vector<ll>a;
void build_sparse()
{
    for(ll i=0;i<n;i++)
    {
        sparse[i][0]=a[i];
    }
    for(ll j=1;(1ll<<j)<=n;j++)
    {
        for(ll i=0;i+(1ll<<j)<=n;i++)
        {
            sparse[i][j]=max(sparse[i][j-1] , sparse[i+(1ll<<(j-1))][j-1]);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    ll life;
    cin>>life;
    while(life--){
        cin>>n;
        a.assign(n,0);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        LGN=log2l(n);
        sparse.assign(n,vector<ll>(LGN+1));
        build_sparse();

        vector<pair<ll,ll>>res(n,pair<ll,ll>{-1,n});
        stack<ll>st;
        for( ll i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>a[i])
            {
                res[st.top()].second=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for( ll i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]>a[i])
            {
                res[st.top()].first=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }

        ll ct=0;
        for(ll i=0;i<n;i++){
            ll j=res[i].first;
            for(ll k=LGN;k>=0;k--){
                if(j>=(1ll<<k)-1 && sparse[j-(1ll<<k)+1][k]<a[i]){
                    j-=(1ll<<k);
                }
            }
            ct+=(res[i].first-j)*(res[i].second-i);
        }

        ll tm=0;
        ll tm2=0;
        for(ll i=n;i>=1;i--){
            tm2+=i*tm;
            tm++;
        }
        cout<<tm2-ct<<'\n';
    }
}

