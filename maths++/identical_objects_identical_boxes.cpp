#include<bits/stdc++.h>
using namespace std;

void help(vector<vector<int>>&ans,vector<int>&candidates,vector<int>&q,int i,int target,int k){
    if(q.size()>k){
        return;
    }
    if(target==0){
        ans.push_back(q);
        return;
    }
    if(i==candidates.size()){
        return;
    }
    if(candidates[i]<=target){
        q.push_back(candidates[i]);
        help(ans,candidates,q,i,target-candidates[i],k);
        q.pop_back();
    }
    help(ans,candidates,q,i+1,target,k);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target, int k) {
    vector<vector<int>>ans;
    vector<int>q;
    int n=candidates.size();
    help(ans,candidates,q,0,target,k);
    return ans;
}

void help2(vector<vector<int>>&ans,vector<int>&candidates,vector<int>&q,int l,int target,int n, int k){
    if(target<0){
        return;
    }
    if(q.size()>k){
        return;
    }
    if(target==0){
        ans.push_back(q);
        return;
    }
    for(int i=l;i<n;i++){
        q.push_back(candidates[i]);
        help2(ans,candidates,q,i,target-candidates[i],n,k);
        q.pop_back();
    } 
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target, int k) {
    vector<vector<int>>ans;
    vector<int>q;
    int n=candidates.size();
    help2(ans,candidates,q,0,target,n,k);
    return ans;
}

int main(){
    vector<int>a={1,2,3,4,5,6,7};
    auto v=combinationSum(a,7,4);
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"---------\n";
    v=combinationSum2(a,7,4);
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
}