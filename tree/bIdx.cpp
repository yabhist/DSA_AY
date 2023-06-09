////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

// Given is a sequence of 
// N integers: 
// A1,A2,..,AN
// Find the number of (not necessarily contiguous) subsequences 
// Ai1,Ai2,...,Aik
// such that Ai1 ≤ Aik.
// Since the count can be enormous, print it modulo 998244353.

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

const ll mod=998244353;
struct binary_indexed_tree{
    ll N;
    vector<ll> bit;
    binary_indexed_tree(ll n):N(n){
        bit.resize(N+1,0);
    }
    ll addition(ll x,ll y){
        return (x+y)%mod;
    }
    void add(ll x, ll a){
        x++;
        for(x;x<=N;x+=(x&-x)) bit[x]=addition(bit[x],a);
    }
    ll sum(ll x){
        x++;
        ll res=0;
        for(x;x>0;x-=(x&-x)) res=addition(res,bit[x]);
        return res;
    }
};
ll binpow_fermat(ll a, ll b) {
    a %= mod;
    ll res = 1;
    b=b%(mod-1);
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll compress(vector<ll>&A){
    map<ll,ll>mp;
    for(ll i=0;i<A.size();i++){
        mp[A[i]]=0;
    }
    ll ct=0;
    for(auto &i:mp){
        i.second=ct++;
    }
    for(ll i=0;i<A.size();i++){
        A[i]=mp[A[i]];
    }
    return ct;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    
    // ll life;
    // cin>>life;
    // while(life--){
        
    // }
    const ll div=binpow_fermat(2,mod-2);
    ll N;
    cin>>N;
    vector<ll>A(N);
    for(ll i=0;i<N;i++){
        cin>>A[i];
    }
    ll n=compress(A);
    binary_indexed_tree bIdx(n);
    ll ans=0;
    for(ll i=0;i<N;i++){
        ans+=bIdx.sum(A[i])*binpow_fermat(2,i);
        ans%=mod;
        bIdx.add(A[i],binpow_fermat(div,i+1));
    }
    cout<<ans<<'\n';
};