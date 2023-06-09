////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

// You are given a connected simple undirected graph G with N vertices numbered 1 to N and N edges. 
// The i-th edge connects Vertex ui​  and Vertex vi​  bidirectionally.

// Answer the following Q queries.

// Determine whether there is a unique simple path from Vertex x i​  to Vertex y i​  
// (a simple path is a path without repetition of vertices).

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

vector<vector<ll>>adj;
vector<ll>parent,Size,deg;

void make(ll v)
{
    parent[v]=v;
    Size[v]=1;
}
ll find(ll v)
{
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
bool Union(ll a, ll b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(Size[a]<Size[b])swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
        Size[b]=0;
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    cout<<fixed<<setprecision(10);
    
    // ll life;
    // cin>>life;
    // while(life--){
        
    // }
    ll n;
    cin>>n;
    adj.assign(n,vector<ll>());
    parent.assign(n,0);
    iota(parent.begin(),parent.end(),0ll);
    Size.assign(n,1);
    deg.assign(n,0);

    for(ll i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    queue<ll>q;
    for(ll i=0;i<n;i++){
        if(deg[i]==1){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        for(auto i:adj[tmp]){
            Union(i,tmp);
            deg[i]--;
            if(deg[i]==1){
                q.push(i);
            }
        }
    }
    ll que;
    cin>>que;
    for(ll i=0;i<que;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        if(find(u)==find(v)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
};

/*
vector<vector<ll>>adj;
vector<ll>parent,group;
vector<bool>vis;

bool dfs1(ll u, ll p){
    vis[u]=1;
    for(auto i:adj[u]){
        if(!vis[i]){
            parent[i]=u;
            if(dfs1(i,u)) return true;
        }
        else if(i!=p){
            ll c=u;
            while(c!=i){
                group[c]=-1;
                c=parent[c];
            }
            group[c]=-1;
            return true;
        }
    }
    return false;
}
void dfs2(ll u, ll c){
    vis[u]=1;
    group[u]=c;
    for(auto i:adj[u]){
        if(!vis[i] && group[i]!=-1){
            dfs2(i,c);
        }
    }
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
    adj.assign(n,vector<ll>());
    parent.assign(n,-1);
    group.assign(n,-2);

    for(ll i=0;i<n;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vis.assign(n,0);
    dfs1(0,-1);
    
    vis.assign(n,0);
    for(ll i=0;i<n;i++){
        if(group[i]==-1){
            dfs2(i,i);
        }
    }
    
    ll que;
    cin>>que;
    for(ll i=0;i<que;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        if(group[u]==group[v]){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
};
*/