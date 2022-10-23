//detect cycle in directed graph
#include<bits/stdc++.h>
using namespace std;

bool cycle(int i, vector<int>&vis,vector<int>&dfsvis, vector<int>adj[])
{
    vis[i]=1;
    dfsvis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            if(cycle(it,vis,dfsvis,adj))
            {
                return true;
            }
        }
        else if(dfsvis[it])
        {
            return true;
        }
    }
    dfsvis[i]=0;
    return false;
}
bool dfsuse(int V,vector<int>adj[])
{
    vector<int>vis(V+1,0);
    vector<int>dfsvis(V+1,0);
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            if(cycle(i,vis,dfsvis,adj))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<int>adj[8];
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(4);
    adj[4].push_back(2);
    adj[6].push_back(3);
    adj[7].push_back(6);
    cout<<dfsuse(7,adj)<<'\n';
}