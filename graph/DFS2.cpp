//bipartite check
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int>adj[],int color[],int i,bool&ct)
{
    color[i]=ct;
    for(auto it:adj[i])
    {
        if(color[it]==-1)
        {
            ct=!ct;
            if(!dfs(adj,color,it,ct))
            {
                return false;
            }
        }
        else if(color[i]==color[it])
        {
            return false;
        }
    }
    return true;
}
bool bipartite_check(vector<int>adj[],int n)
{
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++)
    {
        bool ct=1;
        if(color[i]==-1)
        {
            if(!dfs(adj,color,i,ct))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<int>adj[11];
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[3].push_back(6);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[6].push_back(3);
    adj[6].push_back(7);
    adj[7].push_back(6);

    // adj[8].push_back(9);
    // adj[8].push_back(10);
    // adj[9].push_back(8);
    // adj[9].push_back(10);
    // adj[10].push_back(8);
    // adj[10].push_back(9);

    cout<<bipartite_check(adj,10)<<'\n';
}