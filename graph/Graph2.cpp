////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

// There is a town divided into a grid of cells with H rows and W columns. The cell at the i-th row from the top and 
// j-th column from the left is a passable space if S i,j is . and a block if S i,j is #.

// Takahashi will go from his house to a fish market. His house is in the cell at the top-left corner, 
// and the fish market is in the cell at the bottom-right corner.

// Takahashi can move one cell up, down, left, or right to a passable cell. He cannot leave the town. 
// He cannot enter a block, either. However, his physical strength allows
// him to destroy all blocks in a square region with 
// 2×2 cells of his choice with one punch, making these cells passable.

// Find the minimum number of punches needed for Takahashi to reach the fish market.

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

vector<pair<ll,ll>> change={
    {2,-1},{2,0},{2,1},
    {1,-2},{1,-1},{1,0},{1,1},{1,2},
    {0,-2},{0,-1},{0,1},{0,2},
    {-1,-2},{-1,-1},{-1,0},{-1,1},{-1,2},
    {-2,-1},{-2,0},{-2,1}
};
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
    vector<vector<char>>v(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>>dis(n,vector<ll>(m,1e18));
    dis[0][0]=0;
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
    pq.push({0,0,0});
    while(!pq.empty()){
        ll i=pq.top()[1], j=pq.top()[2];
        ll d=pq.top()[0];
        pq.pop();

        if(dis[i][j]!=d) continue;

        for(auto it:change){
            ll ni=i+it.first, nj=j+it.second;
            if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
            ll cost=(v[ni][nj]=='.' && abs(i-ni)+abs(j-nj)<=1) ? 0:1;
            if(dis[ni][nj]>dis[i][j]+cost){
                dis[ni][nj]=dis[i][j]+cost;
                pq.push({dis[ni][nj],ni,nj});
            }
        }
    }
    cout<<dis[n-1][m-1]<<'\n';
};

/*
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


vector<pair<ll,ll>>c={{1,0},{-1,0},{0,1},{0,-1}};
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
    vector<vector<char>>v(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>>dis(n,vector<ll>(m,1e18));
    dis[0][0]=0;
    deque<pair<ll,ll>>dq;
    dq.push_front({0,0});
    while(!dq.empty()){
        ll i=dq.front().first;
        ll j=dq.front().second;
        dq.pop_front();
        for(auto it:c){
            ll ni=i+it.first;
            ll nj=j+it.second;
            if(ni<0 || nj<0 || ni>=n || nj>=m || v[ni][nj]=='#') continue;
            if(dis[ni][nj]>dis[i][j]){
                dis[ni][nj]=dis[i][j];
                dq.push_front({ni,nj});
            }
        }
        for(ll ni=i-2;ni<=i+2;ni++){
            for(ll nj=j-2;nj<=j+2;nj++){
                if(ni<0 || nj<0 || ni>=n || nj>=m || (abs(ni-i)+abs(nj-j)==4)) continue;
                if(dis[ni][nj]>dis[i][j]+1){
                    dis[ni][nj]=dis[i][j]+1;
                    dq.push_back({ni,nj});
                }
            }
        }
    }
    cout<<dis[n-1][m-1]<<'\n';
};
*/
