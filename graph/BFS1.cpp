// detect a cycle in undirected graph
#include<bits/stdc++.h>
using namespace std;
class solution
{
    bool cycle(int i,vector<int>&vis,vector<int>adj[])
    {
        pair<int,int>p={i,-1};
        queue<pair<int,int>>q;
        vis[i]=1;
        q.push(p);
        while(!q.empty())
        {
            int node = q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=par)
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool bfsuse(int V, vector<int>adj[])
    {
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                if(cycle(i,vis,adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<int>adj[8];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    //adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[3].push_back(6);
    //adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[6].push_back(3);
    adj[6].push_back(7);
    adj[7].push_back(6);
    solution s;
    cout<<s.bfsuse(7,adj)<<'\n';
}