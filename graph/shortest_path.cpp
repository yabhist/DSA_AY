#include<bits/stdc++.h>
using namespace std;
int * shortest_path(vector<int>adj[],int n,int src,int dis[])
{
    fill_n(dis,n+1,INT_MAX);
    dis[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        for(auto it:adj[i])
        {
            if(dis[it]==INT_MAX)//if(dis[i]+1 < dis[it])
            {
                dis[it]=dis[i]+1; 
                q.push(it);
            }
        }
    }
    return dis;
}
int main()
{
    vector<int>adj[8];
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
    int dis[8];
    int *p=shortest_path(adj,7,1,dis);
    for(int i=1;i<=7;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<'\n';
}