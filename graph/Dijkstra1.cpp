////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

// find max happiness possible starting from i=0, from x to y(change in happiness) h[x]>h[y] -> h[x]-h[y] , else -2*(h[x]-h[y]) 
// initial happiness = 0, can be -ve
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

vector<vector<pair<ll,ll>>>adj;
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
    ll n,m;
    cin>>n>>m;
    vector<ll>h(n);
    adj.assign(n,vector<pair<ll,ll>>());
    for(ll i=0;i<n;i++){
        cin>>h[i];
    }
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back({v,max(h[v]-h[u],0ll)});
        adj[v].push_back({u,max(h[u]-h[v],0ll)});

    }
    priority_queue <pair<ll,ll> ,vector<pair<ll,ll>> ,greater<pair<ll,ll>>> pq;
    vector<ll> dis(n,3e18);
    dis[0]=0;
    pq.push({0,0});
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll dist=pq.top().first;
        ll prev=pq.top().second;
        while(dis[prev]<dist){
            pq.pop();
            dist=pq.top().first;
            prev=pq.top().second;
        }
        pq.pop();
        ans=max(ans,h[0]-(h[prev]+dis[prev]));
        vector<pair<ll,ll>>::iterator it;
        for(it=adj[prev].begin(); it!=adj[prev].end(); it++)
        {
            ll next=it->first;
            ll nexdist=it->second;
            if(dis[next]> dis[prev] + nexdist)
            {
                dis[next]=dis[prev] + nexdist;
                pq.push(make_pair(dis[next],next));
            }
        }
    }
    debug(dis)
    cout<<ans<<'\n';
};