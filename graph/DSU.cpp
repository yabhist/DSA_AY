#include<bits/stdc++.h>


using namespace std;

int parent[1000]={0};
int size[1000]={0};

void make(int v)
{
    parent[v]=v;
    size[v]=1;
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
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        size[b]=0;
        return true;
    }
    return false;
}
int main()
{
    
}