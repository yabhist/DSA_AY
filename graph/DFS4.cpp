//topological sort
#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>&vis, vector<int>adj[],stack<int>&s)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,s);
        }
    }
    s.push(node);
}
void topo(int V, vector<int> adj[])
{
    stack<int>s;
    vector<int>vis(V+1,0);
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,s);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    vector<int>adj[8];
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(4);
    adj[2].push_back(4);
    adj[6].push_back(3);
    adj[7].push_back(6);
    topo(7,adj);
}