#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
int main() {
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
	
	vector<int> tin(8, -1);
	vector<int> low(8, -1); 
	vector<int> vis(8, 0); 
	int timer = 0; 
	for(int i = 1;i<=7;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}