/*
You are given a string S of length N consisting of lowercase English letters.
Process Q queries described below in the order they are given.
There are two types of queries:

1 x c : Change the x-th character of S to the lowercase English letter c.
2 L R : If the substring formed by the L-th through R-th characters of S is a palindrome, 
print Yes; otherwise, print No.
/*

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

// ll MOD = (ll)1e9 + 7;
ll MOD = 998244353;

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

struct roll{
    ll hl;
    ll hr;
    ll pw;
};
vector<ll>mod={998244353, 1000000007, 1000000009, 1000000021, 1000000033};
vector<roll> op(vector<roll> lhs, vector<roll> rhs){
    vector<roll>res(5);
    for(ll i=0;i<5;i++){
        res[i].hl=(lhs[i].hl * rhs[i].pw + rhs[i].hl) % mod[i];
        res[i].hr=(lhs[i].hr + lhs[i].pw * rhs[i].hr) % mod[i];
        res[i].pw=(lhs[i].pw * rhs[i].pw) % mod[i];
    }
    return res;
}
vector<vector<roll>> segtree;
vector<ll>base(5);
void build_segtree(string&a,ll low, ll high, ll pos)
{
    if(low==high)
    {
        vector<roll>res(5);
        for(ll i=0;i<5;i++){
            res[i].hl=a[low];
            res[i].hr=a[low];
            res[i].pw=base[i];
        }
        segtree[pos]=res;
    }
    else
    {
        ll mid=(low+high)/2;
        build_segtree(a,low,mid,2*pos+1);
        build_segtree(a,mid+1,high,2*pos+2);
        segtree[pos]=op(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
vector<roll> query(ll ql, ll qr, ll low, ll high, ll pos)
{
    if(ql>high || qr<low)
    {
        vector<roll>res(5);
        for(ll i=0;i<5;i++){
            res[i]={0,0,1};
        }
        return res;
    }
    if(low>=ql && high<=qr)
    {
        return segtree[pos];
    }
    ll mid=(low+high)/2;
    return op(query(ql,qr,low,mid,2*pos+1),query(ql,qr,mid+1,high,2*pos+2));
}
void update(ll i, char c, ll low, ll high, ll pos)
{
    if(low==high)
    {
        vector<roll>res(5);
        for(ll i=0;i<5;i++){
            res[i].hl=c;
            res[i].hr=c;
            res[i].pw=base[i];
        }
        segtree[pos]=res;
    }
    else
    {
        ll mid=(low+high)/2;
        if(i<=mid)
        {
            update(i,c,low,mid,2*pos+1);
        }
        else
        {
            update(i,c,mid+1,high,2*pos+2);
        }
        segtree[pos]=op(segtree[2*pos+1],segtree[2*pos+2]);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    // ll lives;
    // cin>>lives;
    // for(ll lf=1;lf<=lives;lf++){
        
    // }
    
    mt19937_64 rng(time(0));
    for (int i = 0; i < 5; i++) base[i] = rng() % mod[i];

    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    segtree.assign(4*n+1,vector<roll>());
    build_segtree(s,0,n-1,0);
    for(ll i=0;i<q;i++){
        ll a;
        cin>>a;
        if(a==1){
            ll x;
            cin>>x;
            x--;
            char c;
            cin>>c;
            update(x,c,0,n-1,0);
        }
        else{
            ll l,r;
            cin>>l>>r;
            l--,r--;
            vector<roll> ans=query(l,r,0,n-1,0);
            for(ll i=0;i<5;i++){
                if(ans[i].hl!=ans[i].hr){
                    cout<<"No\n";
                    goto end;
                }
            }
            cout<<"Yes\n";
            end:;
        }
    }
    
}

