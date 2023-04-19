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

// We have a string 
// S. Initially, 
// S= 1.
// Process 
// Q queries in the following formats in order.

// 1 x : Append a digit 
// x at the end of 
// S.
// 2 : Delete the digit at the beginning of 
// S.
// 3 : Print the number represented by 
// S in decimal, modulo 
// 998244353.

// 1≤Q≤6×10e5
 
// For each query in the first format, 
// x∈{1,2,3,4,5,6,7,8,9}.
// A query in the second format is given only if 
// S has a length of 
// 2 or greater.
// There is at least one query in the third format.
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
    
    // ll life;
    // cin>>life;
    // while(life--)
    // {
        
    //}
    const ll mod=998244353;
    ll q;
    cin>>q;
    vector<ll>v;
    list<ll>l;
    ll ans=1;
    l.push_back(1);
    v.push_back(1);
    ll tmp=1;
    for(ll i=0;i<q;i++){
        ll x;
        cin>>x;
        if(x==1){
            ll a;
            cin>>a;
            l.push_back(a);
            ans=(ans*10+a)%mod;
            tmp*=10%mod;
            tmp%=mod;
            v.push_back(tmp);
        }
        else if(x==2){
            ll tmp1=l.front();
            l.pop_front();
            ans=(ans-((v.back()*tmp1)%mod)+mod)%mod;
            v.pop_back();
            tmp=v.back();
        }
        else{
            cout<<ans<<'\n';
        }
    }
}