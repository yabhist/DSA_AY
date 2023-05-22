// The dance is called magnificent if the following is true:
// exactly m students participate in the dance;
// levels of all dancers are pairwise distinct;
// levels of every two dancers have an absolute difference strictly less than m
// count the number of magnificent dances mod 1e9+7

////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

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

const ll mod=1e9+7;
ll binpow_fermat(ll a, ll b, ll m) {
    // m is prime
    a %= m;
    ll res = 1;
    b=b%(m-1);
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll mod_inverse_prime(ll a, ll m)//m is prime
{
    return binpow_fermat(a,m-2,m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    
    ll life;
    cin>>life;
    while(life--){
        ll n,m;
        cin>>n>>m;
        vector<ll>a(n);
        vector<pair<ll,ll>>b;
        map<ll,ll>mp;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(auto i:mp){
            b.push_back({i.first,i.second});
        }
        vector<ll>prefmod(b.size());
        prefmod[0]=b[0].second%mod;
        for(ll i=1;i<b.size();i++){
            prefmod[i]=prefmod[i-1]*b[i].second%mod;
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(i+m-1<b.size() && b[i+m-1].first==b[i].first+m-1){
                ll tmp=(i==0)?1:mod_inverse_prime(prefmod[i-1],mod);
                ans=(ans+prefmod[i+m-1]*tmp%mod)%mod;
            }
        }
        cout<<ans<<'\n';
    }
};
// 1
// 12 3
// 5 2 1 1 4 3 5 5 5 2 7 5

// 11

/* 2nd method
const ll mod=1e9+7;
vector<ll>segtree;
 
void build_segtree(vector<ll>&a, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=a[low];
    }
    else
    {
        ll mid=low+(high-low)/2;
        build_segtree(a,low,mid,2*pos+1);
        build_segtree(a,mid+1,high,2*pos+2);
        segtree[pos]=segtree[2*pos+1]*segtree[2*pos+2]%mod;
    }
}
 
ll query(ll ql, ll qr, ll low, ll high, ll pos)
{
    if(low>=ql && high<=qr)
    {
        return segtree[pos];
    }
    if(high<ql || low>qr)
    {
        return 1;
    }
    ll mid=low+(high-low)/2;
    return query(ql,qr,low,mid,2*pos+1)*query(ql,qr,mid+1,high,2*pos+2)%mod;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    
    ll life;
    cin>>life;
    while(life--){
        ll n,m;
        cin>>n>>m;
        vector<ll>a(n),b,c;
        map<ll,ll>mp;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(auto i:mp){
            b.push_back(i.first);
            c.push_back(i.second);
        }
        segtree.assign(4ll*b.size(),0);
        build_segtree(c,0,c.size()-1,0);
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(i+m-1<b.size() && b[i+m-1]==b[i]+m-1){
                ans=(ans+query(i,i+m-1,0,c.size()-1,0))%mod;
            }
        }
        cout<<ans<<'\n';
    } 
};
*/

/*3rd method
const ll mod=1e9+7;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    ll life;
    cin>>life;
    while(life--){
        ll n,m;
        cin>>n>>m;
        vector<ll>a(n),b,c;
        map<ll,ll>mp;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(auto i:mp){
            b.push_back(i.first);
            c.push_back(i.second);
        }
        if(b.size()<m){
            cout<<0<<'\n';
            continue;
        }
        stack<pair<ll,ll>>s1,s2;
        for(ll i=0;i<m;i++){
            s1.push({c[i],c[i]*(s1.empty()?1:s1.top().second)%mod});
        }
        ll ans=0;
        for(ll i=m;i<=b.size();i++){
            if(b[i-1]-b[i-m] == m-1){
                ans=(ans+(s1.empty()?1:s1.top().second)*(s2.empty()?1:s2.top().second)%mod)%mod;
            }
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push({s1.top().first,s1.top().first*(s2.empty()?1:s2.top().second)%mod});
                    s1.pop();
                }
            }
            s2.pop();
            if(i!=b.size()) s1.push({c[i],c[i]*(s1.empty()?1:s1.top().second)%mod});
        }
        cout<<ans<<'\n';
    }
};
*/