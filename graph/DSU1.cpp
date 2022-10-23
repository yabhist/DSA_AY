#include<bits/stdc++.h>


using namespace std;

int parent[1000]={0};
int Rank[1000]={0};

void make(int v)
{
    parent[v]=v;
    Rank[v]=0;
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
        if(Rank[a]<Rank[b])
        {
            parent[a]=b;
        }
        else if(Rank[a]>Rank[b])
        {
            parent[b]=a;
        }
        else
        { 
            parent[b]=a;
            Rank[a]++;
        }
        return true;
    }
    return false;
}
int main()
{
    
}