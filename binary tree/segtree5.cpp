#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+10;
vector<int>seg(4*mx),lazy(4*mx);
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
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);

}
void upd(int l, int r, int low, int high, int v, int pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=lazy[pos];
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
        seg[pos]+=v;
        if(low!=high)
        {
            lazy[2*pos+1]+=v;
            lazy[2*pos+2]+=v;
        }
        return;
    }
    int m=(low+high)/2;
    upd(l,r,low,m,v,2*pos+1);
    upd(l,r,m+1,high,v,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}
int qry(int l, int r, int low, int high, int pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=lazy[pos];
        if(low!=high)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<l || low>r)
    {
        return 9e18;
    }
    if(high<=r && low>=l)
    {
        return seg[pos];
    }
    int m=(low+high)/2;
    int a=qry(l,r,low,m,2*pos+1);
    int b=qry(l,r,m+1,high,2*pos+2);
    return min(a,b);
}
int main()
{

}