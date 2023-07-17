////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

// You are given a tree T with N vertices. Edge i (1≤i≤N−1) connects vertices u i​  and v i​ , and has a weight of w i​ .
// Process Q queries in order. 
// There are two kinds of queries as follows.
// 1 i w : Change the weight of edge i to w.
// 2 u v：Print the distance between vertex u and vertex v.
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

vector<vector<vector<ll>>>adj;
vector<ll>a;
vector<ll> bit;
ll N;
ll N_;
ll addition(ll x,ll y){
    return (x+y);
}
void add(ll x, ll val){
    x++;
    for(x;x<=N;x+=(x&-x)) bit[x]=addition(bit[x],val);
}
ll sum(ll x){
    x++;
    ll res=0;
    for(x;x>0;x-=(x&-x)) res=addition(res,bit[x]);
    return res;
}
vector<ll>segtree;
ll query(ll ql, ll qr, ll low, ll high, ll pos)
{
    if(ql>high || qr<low)
    {
        return 1e18;
    }
    if(low>=ql && high<=qr)
    {
        return segtree[pos];
    }
    ll mid=(low+high)/2;
    return min(query(ql,qr,low,mid,2*pos+1),query(ql,qr,mid+1,high,2*pos+2));
}
void update(ll i, ll val, ll low, ll high, ll pos)
{
    if(low==high)
    {
        segtree[pos]=val;
    }
    else
    {
        ll mid=(low+high)/2;
        if(i<=mid)
        {
            update(i,val,low,mid,2*pos+1);
        }
        else
        {
            update(i,val,mid+1,high,2*pos+2);
        }
        segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
    }
}
map<ll,ll>mp,mp_seg;
void dfs(ll u, ll p){
    for(auto i:adj[u]){
        if(i[0]==p) continue;
        if(!mp_seg.count(u)) mp_seg[u]=a.size();
        update(a.size(),mp_seg[u],0,N_-1,0);
        a.push_back(u);
        add(a.size()-1,i[1]);
        mp[i[2]]=a.size()-1;
        dfs(i[0],u);
        add(a.size()-1,-i[1]);
        mp[-i[2]]=a.size()-1;
    }
    if(!mp_seg.count(u)) mp_seg[u]=a.size();
    update(a.size(),mp_seg[u],0,N_-1,0);
    a.push_back(u);
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
    ll n;
    cin>>n;
    N=2*n-2;
    N_=2*n-1;
    adj.assign(n,vector<vector<ll>>());
    bit.assign(N+1,0);
    segtree.assign(4*N_+1,0);
    vector<ll>edg(n);
    for(ll i=1;i<=n-1;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edg[i]=w;
        adj[u].push_back({v,w,i});
        adj[v].push_back({u,w,i});
    }
    dfs(0,-1);
    
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        ll x;
        cin>>x;
        if(x==1){
            ll i,w;
            cin>>i>>w;
            add(mp[i],w-edg[i]);
            add(mp[-i],-(w-edg[i]));
            edg[i]=w;
        }
        else{
            ll u,v;
            cin>>u>>v;
            u--,v--;
            ll ql=min(mp_seg[u],mp_seg[v]);
            ll qr=max(mp_seg[u],mp_seg[v]);
            ll lca=query(ql,qr,0,N_-1,0);
            
            ll ans=0;
            if(mp_seg[u]-1>=0) ans+=sum(mp_seg[u]-1);
            if(mp_seg[v]-1>=0) ans+=sum(mp_seg[v]-1);
            if(lca-1>=0) ans-=2*sum(lca-1);
            cout<<ans<<'\n';
        }
    }
}