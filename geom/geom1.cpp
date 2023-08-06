////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/

// Given are N points (x i​ ,y i​ ) in a two-dimensional plane.

// Find the minimum radius of a circle such that all the points are inside or on it.

// Constraints 2≤N≤50  0≤x i​ ≤1000  0≤y i​ ≤1000
// The given 
// N points are all different.
// The values in input are all integers.

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

const ll N=100010;
const long double eps=1e-10;
const long double pi = acosl(-1);
ll sign(long double x){
    if(fabsl(x)<eps){
        return 0;
    }
    if(x<0){
        return -1;
    }
    return 1;
}
ll cmp(long double x, long double y){
    if(fabsl(x-y)<eps){
        return 0;
    }
    if(x<y){
        return -1;
    }
    return 1;
}
struct Point {
    long double x, y;
    Point(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}
};
 
struct Circle {
    Circle(Point _o, long double _r = 0) : o(_o), r(_r) {}
    Point o;
    long double r;
};
 
struct Line {
    long double a,b,c;
    Line(long double _a=0, long double _b=0, long double _c=0):a(_a),b(_b),c(_c) {}
};
 
long double get_dist(Point p, Point q) {
    long double dx = p.x - q.x, dy = p.y - q.y;
    return sqrtl(dx * dx + dy * dy);
}
Line get_line(Point p, Point q){
    Line l;
    l.a=-(p.y-q.y);
    l.b=+(p.x-q.x);
    l.c=(l.a)*(p.x)+(l.b)*(p.y);
    return l;
}

Line get_perp_bisector_line(Point p, Point q) {
    Line tm=get_line(p,q);
    Line l;
    Point r={(p.x+q.x)/2,(p.y+q.y)/2};
    l.a=tm.b;
    l.b=-tm.a;
    l.c=(l.a)*(r.x)+(l.b)*(r.y);
    return l;
}
 
Point get_line_intersection(Line l1, Line l2) {
    long double det=(l1.a*l2.b-l2.a*l1.b);
    long double x=(l2.b*l1.c-l1.b*l2.c)/det;
    long double y=(l1.a*l2.c-l2.a*l1.c)/det;
    return {x,y};
}
 
Circle get_circle(Point a, Point b, Point c) {
    Line l1 = get_perp_bisector_line(a, b), l2 = get_perp_bisector_line(a, c);
    Point p = get_line_intersection(l1, l2);
    return {p, get_dist(p, a)};
}



signed main(){
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
    vector<Point>u(n);
    for(ll i=0;i<n;i++){
        cin>>u[i].x>>u[i].y;
    }
    Circle c(u[0]);
    for(ll i=1;i<n;i++){
        if(cmp(c.r,get_dist(c.o,u[i]))<0){
            c=Circle(u[i]);
        }
        for(ll j=0;j<i;j++){
            if(cmp(c.r,get_dist(c.o,u[j]))<0){
                c=Circle(Point{(u[i].x+u[j].x)/2,(u[i].y+u[j].y)/2},get_dist(u[i],u[j])/2);
            }
            for(ll k=0;k<j;k++){
                if(cmp(c.r,get_dist(c.o,u[k]))<0){
                    c=get_circle(u[i],u[j],u[k]);
                }
            }
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<c.r<<'\n';
}