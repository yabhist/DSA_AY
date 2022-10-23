#include<bits/stdc++.h>
using namespace std;
void dfs_topo(int node, vector<int>&vis, vector<pair<int,int>>adj[],stack<int>&s)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it.first])
        {
            dfs_topo(it.first,vis,adj,s);
        }
    }
    s.push(node);
}

void shortest_path_dag(vector<pair<int,int>>adj[], int n, int src)
{
    stack<int>s;
    vector<int>vis(n+1);
    int dis[n+1];
    fill_n(dis,n+1,INT_MAX);
    dis[src]=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs_topo(i,vis,adj,s);
        }
    }
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(dis[node]!=INT_MAX)
        {
            for(auto it:adj[node])
            {
                if(dis[node]+it.second < dis[it.first])
                {
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<(dis[i]==INT_MAX?-1:dis[i])<<" ";
    }
    cout<<'\n';
}
int main()
{
    vector<pair<int,int>>adj[8];
    adj[1].push_back({2,1});
    adj[2].push_back({3,2});
    adj[3].push_back({5,3});
    adj[5].push_back({4,1});
    adj[2].push_back({4,3});
    adj[6].push_back({3,1});
    adj[7].push_back({6,2});
    shortest_path_dag(adj,7,1);
}
