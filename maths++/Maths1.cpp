////
/*------------------This code is written by 'yabhist' (abhi_yadav1)------------------*/                                                                                   

#include<bits/stdc++.h>

using namespace std;

typedef int I;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
 
#define int long long int

#include<bits/stdc++.h>
using namespace std;

// lcm(a,b)=n find a,b such that max(a,b) is minimum
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int life;
    // cin>>life;
    // while(life--)
    // {
        
    // }
    int n;
    cin>>n;
    vector<int>v;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int curr=1;
            while(n%i==0)
            {
                n/=i;
                curr*=i;
            }
            v.push_back(curr);
        }
        
    }
    if(n>1)
    {
        v.push_back(n);
    }
    int sz=v.size();
    int ansa=1e18,ansb=1e18;
    for(int i=0;i<(1LL<<sz);i++)
    {
        int a=1,b=1;
        for(int j=0;j<sz;j++)
        {
            if(i&(1LL<<j))
            {
                a*=v[j];
            }
            else
            {
                b*=v[j];
            }
        }
        if(max(ansa,ansb)>max(a,b))
        {
            ansa=a;
            ansb=b;
        }
    }
    cout<<ansa<<' '<<ansb<<'\n';
}

//2nd method
// #include <bits/stdc++.h>
// using namespace std;
// #define finish(x) return cout << x << endl, 0
// #define ll long long

// ll x;

// ll lcm(ll a, ll b){
//     return a / __gcd(a, b) * b;
// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> x;
//     ll ans;
//     for(ll i = 1 ; i * i <= x ; i++){
//         if(x % i == 0 && lcm(i, x / i) == x){
//             ans = i;
//         }
//     }
//     cout << ans << " " << x / ans << endl;
// }