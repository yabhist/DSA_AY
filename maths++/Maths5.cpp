/*
Brahman
*/

//print number of all types of matrices with i rows j columns (1<=i<=n, 1<=j<=m) containing only 1s

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
    vector<string>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll>hist(m+1);
    vector<vector<ll>>ans(n+1,vector<ll>(m+1));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='0'){
                hist[j]=0;
            }
            else{
                hist[j]=hist[j]+1;
            }
        }
        
        vector<pair<ll,ll>>st;
        st.push_back({-1,0});
        for(ll j=0;j<=m;j++){
            ll idx_in_st=j;
            while(st.back().second > hist[j]){
                ans[st.back().second][j-st.back().first]++;
                ans[max(st[st.size()-2].second,hist[j])][j-st.back().first]--;
                idx_in_st=st.back().first;
                st.pop_back();
            }
            st.push_back({idx_in_st,hist[j]});
        }
    }
    
    for(ll ct=0;ct<2;ct++){
        for(ll i=1;i<=n;i++){
            for(ll j=m;j>=1;j--){
                if(j+1<=m) ans[i][j]+=ans[i][j+1];
            }
        }
    }
    for(ll j=1;j<=m;j++){
        for(ll i=n;i>=1;i--){
            if(i+1<=n) ans[i][j]+=ans[i+1][j];
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<ans[i][j]<<' ';
        }cout<<'\n';
    }
}