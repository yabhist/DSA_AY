#include<bits/stdc++.h>
using namespace std;
vector<int>lvl;
vector<vector<int>>dp,adj;
int N, LGN;
void dfs(int u, int p){
    lvl[u]=lvl[p]+1;
    dp[u][0]=p;
    for(int i=1;i<=LGN;i++){
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v==p) continue;
        dfs(v,u);
    }
}
int lca(int u, int v){
    if(lvl[u]<lvl[v]){
        swap(u,v);
    }
    int diff=lvl[u]-lvl[v];
    for(int i=0;i<LGN;i++){
        if((1<<i)&diff){
            u=dp[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=LGN;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];
}
int main(){

}