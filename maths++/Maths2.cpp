////
/*------------------------This  code  is  written  by  'yabhist'------------------------*/                                                                                 

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
// You are given a sequence A1, A2, ..., AN and Q queries. There are two types of queries:

// 1 X Y — Set AX = Y.
// 2 L R G — Compute the number of indices i such that L ≤ i ≤ R and gcd(G, Ai) = 1.
// Find the answer to each query of the second type

// 1 ≤ N, Q ≤ 5 · 1e4
// 1 ≤ L ≤ R ≤ N
// 1 ≤ X ≤ N
// 1 ≤ Y, G ≤ 1e5
// 1 ≤ Ai ≤ 1e5 for each valid i
const ll mx=1e5;
vector<tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>> pbds(mx+5);
vector<ll>p(mx+5),a;

void change(ll i, ll keep, vector<ll>&a)
{
    vector<ll>v;
    ll temp=a[i];
    while(temp!=1)
    {
        v.push_back(p[temp]);
        ll bb=p[temp];
        while(temp%bb==0)
        {
            temp/=bb;
        }
    }
    ll sz=v.size();
    for(ll j=0;j<(1ll<<sz);j++)
    {
        ll mm=1;
        for(ll k=0;k<sz;k++)
        {
            if(j&(1ll<<k))
            {
                mm*=v[k];
            }
        }
        if(keep) pbds[mm].insert(i);  
        else pbds[mm].erase(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(ll i=1;i<=mx;i++)
    {
        p[i]=i;
    }
    for(ll i=2;i*i<=mx;i++)
    {
        if(p[i]==i)
        {
            for(ll j=i*i;j<=mx;j+=i)
            {
                p[j]=i;
            }
        }
    }
    // ll life;
    // cin>>life;
    // while(life--)
    // {

    // }
    ll n;
    cin>>n;
    a.assign(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(ll i=0;i<n;i++)
    {
        change(i,1,a);
    }

    ll q;
    cin>>q;
    for(ll i=0;i<q;i++)
    {
        ll cc;
        cin>>cc;
        if(cc==2)
        {
            ll l,r,g;
            cin>>l>>r>>g;
            l--;
            r--;
            vector<ll>v;
            ll temp=g;
            while(temp!=1)
            {
                v.push_back(p[temp]);
                ll bb=p[temp];
                while(temp%bb==0)
                {
                    temp/=bb;
                }
            }
            ll sz=v.size();
            ll ans=0;
            for(ll j=0;j<(1ll<<sz);j++)
            {
                ll ct=0;
                ll mm=1;
                for(ll k=0;k<sz;k++)
                {
                    if(j&(1ll<<k))
                    {
                        ct++;
                        mm*=v[k];
                    }
                }
                if(ct%2==0)
                {
                    ans+=pbds[mm].order_of_key(r+1)-pbds[mm].order_of_key(l);
                }
                else
                {
                    ans-=pbds[mm].order_of_key(r+1)-pbds[mm].order_of_key(l);
                }
            }
            cout<<ans<<'\n';
        }
        else
        {
            ll x,y;
            cin>>x>>y;
            x--;
            change(x,0,a);
            a[x]=y;
            change(x,1,a);
        }
    }
}  
// 4
// 2 3 4 5
// 3
// 2 1 4 2
// 1 2 6
// 2 1 4 2

// 2
// 1