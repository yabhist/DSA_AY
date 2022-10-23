#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};

bool comp(node a , node b)
{
    return a.wt < b.wt;
}

int find(int v,vector<int>& parent)
{
    if(v==parent[v])return v;
    return parent[v]=find(parent[v],parent);
}
void Union(int a, int b, vector<int>& parent, vector<int>& Rank)
{
    a=find(a,parent);
    b=find(b,parent);
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
        
    }
    
}

int main()
{
    vector<node> edges;
    edges.push_back(node(1,2,2));
    edges.push_back(node(3,2,1));
    edges.push_back(node(4,2,5));
    edges.push_back(node(3,5,3));
    edges.push_back(node(3,6,1));
    edges.push_back(node(4,5,2));
    edges.push_back(node(6,7,2));

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(8);
    iota(parent.begin(),parent.end(),0);

    vector<int> rank(8,0);

    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it:edges)
    {
        if(find(it.v, parent) != find(it.u, parent))
        {
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            Union(it.u , it.v, parent ,rank);
        }
    }
    cout<<cost<<'\n';
    for(auto it:mst)
    {
        cout<<it.first<<' '<<it.second<<'\n';
    }
}
// 11 
// 3 2
// 3 6
// 1 2
// 4 5
// 6 7
// 3 5