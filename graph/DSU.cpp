#include<bits/stdc++.h>


using namespace std;

vector<int>parent(100),Size(100);

void make(int v)
{
    parent[v]=v;
    Size[v]=1;
}
int find(int v)
{
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}
bool Union(int a, int b)
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
    
}