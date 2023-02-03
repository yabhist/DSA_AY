#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx=2e5+5;
vector<ll>seg(4*mx),lazy(4*mx);
void build_segtree(vector<int>& a, int low, int high, int pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        return;
    }

    int mid=low+(high-low)/2;
    build_segtree(a,low,mid,2*pos+1);
    build_segtree(a,mid+1,high,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
void upd(ll l, ll r, ll low, ll high, ll v, ll pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return;
    }
    if(high<=r && low>=l)
    {
        seg[pos]+=(high-low+1)*v;
        if(low!=high)
        {
            lazy[2*pos+1]+=v;
            lazy[2*pos+2]+=v;
        }
        return;
    }
    ll m=(low+high)/2;
    upd(l,r,low,m,v,2*pos+1);
    upd(l,r,m+1,high,v,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
ll qry(ll l, ll r, ll low, ll high, ll pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(high-low+1)*lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return 0;
    }
    if(high<=r && low>=l)
    {
        return seg[pos];
    }
    ll m=(low+high)/2;
    return qry(l,r,low,m,2*pos+1)+qry(l,r,m+1,high,2*pos+2);
}

int main()
{

}