#include<bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int i,int N ,int count,vector<int>&vis,vector<int>&path, vector<vector<int>>&adj)
    {
        vis[i]=1;
        path[count]=i;
        if(count==N)
        {
            if(adj[path[count]][path[1]]==1)
            return true;
            return false;
        }
        for(int j=1;j<=N;j++)
        {
            if(adj[i][j]==1)
            {
                if(!vis[j])
                {
                    if(dfs(j,N,count+1,vis,path,adj))
                    {
                        return true;
                    }
                    vis[j]=0;
                    path[count+1]=-1;
                }
            }
        }
        return false;
    }
    public:
    
    bool check(int N,int M,vector<vector<int>>&edges,vector<int>&path)
    {
        vector<int>vis(N+1,0);
        vector<vector<int>>adj(N+1,vector<int>(N+1,0));
        for(auto i:edges)
        {
            adj[i[0]][i[1]]=1;
            adj[i[1]][i[0]]=1;
        }
        path[1]=1;
        vis[1]=1;
        for(int i=2;i<=N;i++)
        {
            if(adj[1][i]==1)
            {
                if(dfs(i,N,2,vis,path,adj))
                {
                    return true;
                }
                vis[i]=0;
                path[2]=-1;
            }
        }
        return false;
    }
};
 

int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
        vector<int>path(N+1,-1);
    	if(obj.check(N,M,Edges,path)){
    		cout<<"1"<<endl;
            for(int i=1;i<=N;i++)
            {
                cout<<path[i]<<' ';
            }cout<<path[1]<<'\n';
    	}
    	else
    	cout<<"0"<<endl;
	}
}
