//detect cycle in directed graph
#include<bits/stdc++.h>
using namespace std;
bool cycle_bfs(vector<int>adj[],int n)
{
    int in[n+1]={0};
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        for(auto it:adj[i])
        {
            in[it]++;
        }    
    }
    for(int i=1;i<=n;i++)
    {
        if(!in[i])
        {
            q.push(i);
        }
    }
    int ct=0;
    while(!q.empty())
    {
        int node=q.front();
        ct++;
        q.pop();
        for(auto it:adj[node])
        {
            in[it]--;
            if(!in[it])
            {
                q.push(it);
            }
        }
    }
    if(ct==n) return false;
    return true;
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
    cout<<cycle_bfs(adj,7)<<'\n';
}