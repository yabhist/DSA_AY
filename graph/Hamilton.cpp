#include<bits/stdc++.h>
using namespace std;


class Solution
{
    bool dfs(int i,int N ,int count,vector<int>&vis,vector<int>&path, vector<int>adj[])
    {
        vis[i]=1;
        path[count]=i;
        if(count==N)
        {
            return true;
        }
        for(auto j:adj[i])
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
        return false;
    }
    public:
    
    bool check(int N,int M,vector<vector<int>>&edges,vector<int>&path)
    {
        vector<int>vis(N+1,0);
        vector<int>adj[N+1];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=N;i++)
        {
            if(dfs(i,N,1,vis,path,adj))
            {
                return true;
            }
            vis[i]=0;
            path[1]=-1;
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
            }cout<<'\n';
    	}
    	else
    	cout<<"0"<<endl;
	}
}
