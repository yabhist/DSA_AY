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
    adj[3].push_back({5,3});
    adj[3].push_back({6,1});
    adj[4].push_back({2,5});
    adj[4].push_back({5,2});
    adj[5].push_back({3,3});
    adj[5].push_back({4,2});
    adj[6].push_back({3,1});
    adj[6].push_back({7,2});
    adj[7].push_back({6,2});
    
    int par[8];
    int key[8];
    bool mstset[8];
    fill_n(par,8,-1);
    fill_n(key,8,INT_MAX);
    fill_n(mstset,8,false);
    key[1]=0;
    for(int i=1;i<7;i++)
    {
        int mini=INT_MAX,u;
        for(int v=1;v<=7;v++)
        {
            if(mstset[v]==false && key[v]<mini)
            {
                mini=key[v];
                u=v;
            }
        }
        mstset[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(mstset[v]==false && wt<key[v])
            {
                par[v]=u;
                key[v]=wt;
            }
        }
    }
    for(int v=1;v<=7;v++)
    {
        cout<<par[v]<<' ';
    }cout<<'\n';
}