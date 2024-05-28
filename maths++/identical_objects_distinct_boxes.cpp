#include<bits/stdc++.h>
using namespace std;

void help(vector<vector<int>>&ans,vector<int>&candidates,vector<int>&q,int idx,int target,int n, int k){
    if(target<0){
        return;
    }
    if(target==0){
        ans.push_back(q);
        return;
    }
    if(idx==k){
        return;
    }
    help(ans,candidates,q,idx+1,target,n,k);
    for(int i=0;i<n;i++){
        q[idx]=candidates[i];
        help(ans,candidates,q,idx+1,target-candidates[i],n,k);
        q[idx]=0;
    } 
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target, int k) {
    vector<vector<int>>ans;
    vector<int>q(k);
    int n=candidates.size();
    help(ans,candidates,q,0,target,n,k);
    return ans;
}

int main(){
    vector<int>a={1,2,3,4,5,6,7};
    auto v=combinationSum(a,7,4);
    cout<<v.size()<<'\n';
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
}