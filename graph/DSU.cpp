#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>parent,Size;

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
int main()
{
    /*
    parent.assign(n,-1);
    iota(parent.begin(),parent.end(),0ll);
    Size.assign(n,1);
    */
}