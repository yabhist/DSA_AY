/*
You are given a simple undirected graph with nnodes and medges. Note that the graph is not necessarily connected. 
The nodes are labeled from 1to n.
We define a graph to be a Fish Graph if it contains a simple cycle with a special node u
belonging to the cycle. Apart from the edges in the cycle, the graph should have exactly 2
extra edges. Both edges should connect to node u, but they should not be connected to any other node of the cycle.

Determine if the graph contains a subgraph that is a Fish Graph, and if so, find any such subgraph.
*/


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

vector<vector<ll>>adj;
vector<bool>vis;
vector<ll>v;
ll from=-1,to=-1;
bool check(ll i){
    return (count(v.begin(),v.end(),i)==0);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    ll life;
    cin>>life;
    for(ll lf=1;lf<=life;lf++){
        ll n,m;
        cin>>n>>m;
        adj.assign(n,vector<ll>());
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<ll,ll>>ans;
        for(ll i=0;i<n;i++){
            if(adj[i].size()>=4){
                for(auto u:adj[i]){
                    from=i;
                    to=u;
                    v.clear();
                    vis.assign(n,0);
                    queue<ll>q;
                    vector<ll>parent(n,-1);
                    vector<pair<ll,ll>>ans;
                    q.push(to);
                    vis[to]=1;
                    while(!q.empty()){
                        auto tm=q.front();
                        q.pop();
                        for(auto j:adj[tm]){
                            if(tm==to && j==from){
                                continue;
                            }
                            if(!vis[j]){
                                vis[j]=1;
                                parent[j]=tm;
                                if(j==from){
                                    ll p=from;
                                    while(p!=to){
                                        ans.push_back({p,parent[p]});
                                        v.push_back(p);
                                        p=parent[p];
                                    }
                                    v.push_back(to);
                                    ans.push_back({from,to});
                                    vector<ll> extra = adj[i];
                                    extra.resize(4);
                                    partition(extra.begin(),extra.end(),check);
                                    extra.resize(2);
                                    for(ll j=0;j<2;j++){
                                        ans.push_back({from,extra[j]});
                                    }
                                    cout<<"YES\n"<<ans.size()<<'\n';
                                    for(auto j:ans){
                                        cout<<j.first+1<<' '<<j.second+1<<'\n';
                                    }cout<<'\n';
                                    goto earthquake;
                                }
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        cout<<"NO\n";
        earthquake:;
        
    }
    
    
    
}

/*
vector<vector<ll>>adj;
vector<bool>vis;
vector<ll>v,v2;
ll from=-1,to=-1;
void dfs(ll u){
    vis[u]=1;
    v2.push_back(u);
    if(u==to){
        v=v2;
        return;
    }
    for(auto i:adj[u]){
        if(u==from && i==to){
            continue;
        }
        if(!vis[i]){
            dfs(i);
            if(!v.empty()) return;
        }
    }
    v2.pop_back();
}
bool check(ll i){
    return (count(v.begin(),v.end(),i)==0);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    ll life;
    cin>>life;
    for(ll lf=0;lf<life;lf++){
        ll n,m;
        cin>>n>>m;
        // if(lf==42 && life==300){
        //     cout<<n<<' '<<m<<'\n';
        // }
        adj.assign(n,vector<ll>());
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            // if(lf==42 && life==300){
            //     cout<<u<<' '<<v<<'\n';
            // }
            
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // if(life==300){
        //     continue;
        // }
        vector<pair<ll,ll>>ans;
        for(ll i=0;i<n;i++){
            if(adj[i].size()>=4){
                for(auto u:adj[i]){
                    v2.clear();
                    v.clear();
                    vis.assign(n,0);
                    from=i;
                    to=u;
                    dfs(from);
        
                    if(!v.empty()){
                        vector<ll> extra = adj[i];
                        extra.resize(4);
                        
                        ll mn = v.size();
                        for(auto i : extra) {
                            auto it = find(v.begin(),v.end(),i);
                            if(it!=v.begin()+1) {
                                mn = min(mn,ll(it-v.begin())+1);
                            }
                        }
                        v.resize(mn);
                        partition(extra.begin(),extra.end(),check);
                        extra.resize(2);
                    
                        for(ll j=1;j<mn;j++){
                            ans.push_back({v[j],v[j-1]});
                        }
                        ans.push_back({v[0],v[mn-1]});
                        for(ll j=0;j<2;j++){
                            ans.push_back({from,extra[j]});
                        }
                        cout<<"YES\n"<<ans.size()<<'\n';
                        for(auto j:ans){
                            cout<<j.first+1<<' '<<j.second+1<<'\n';
                        }cout<<'\n';
                        goto earthquake;
                    }
                }
            }
        }
        cout<<"NO\n";
        earthquake:;
        
    }   
}
*/