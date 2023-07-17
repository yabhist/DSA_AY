#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>>adj[8];
    adj[1].push_back({2,2});
    adj[2].push_back({1,2});
    adj[2].push_back({3,1});
    adj[2].push_back({4,5});
    adj[3].push_back({2,1});
    adj[3].push_back({5,1});
    adj[3].push_back({6,1});
    adj[4].push_back({2,5});
    adj[4].push_back({5,2});
    adj[5].push_back({3,1});
    adj[5].push_back({4,2});
    adj[6].push_back({3,1});
    adj[6].push_back({7,2});
    adj[7].push_back({6,2});

    int src =1;
    priority_queue <pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> dis(8,INT_MAX);
    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        if(dis[prev]!=dist) continue;
        vector<pair<int,int>>::iterator it;
        for(it=adj[prev].begin(); it!=adj[prev].end(); it++)
        {
            int next=it->first;
            int nexdist=it->second;
            if(dis[next]> dis[prev] + nexdist)
            {
                dis[next]=dis[prev] + nexdist;
                pq.push(make_pair(dis[next],next));
            }
        }
    }
    for(int i=1;i<=7;i++)
    {
        cout<<dis[i]<<' ';
    }
    cout<<'\n';
}