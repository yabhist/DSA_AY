#include<bits/stdc++.h>
using namespace std;

class solution
{
    void dfs(int node, vector<int>&vis, vector<int>adj[],vector<int>&storedfs)
    {
        storedfs.push_back(node);
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,storedfs);
            }
        }
    }
public:
    vector<int> dfsGRAPH(int V, vector<int> adj[])
    {
        vector<int>storedfs;
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,storedfs);
            }
        }
        return storedfs;
    }
};
int main()
{

}       