// detect a cycle in undirected graph
#include<bits/stdc++.h>
using namespace std;
class solution
{
    bool cycle(int i,int parent, vector<int>&vis, vector<int>adj[])
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(cycle(it,i,vis,adj))
                {
                    return true;
                }
            }
            else if(it!=parent)
            {
                return true;
            }
        }
        return false;
    }
public:
    bool dfsuse(int V,vector<int>adj[])
    {
        vector<int>vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                if(cycle(i,-1,vis,adj))
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
    cout<<s.dfsuse(7,adj)<<'\n';
}