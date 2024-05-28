#include<bits/stdc++.h>
using namespace std;

class Permutation {
    void help(vector<vector<int>>&ans,vector<int>&a,int l, int r){
        if(l==r){
            ans.push_back(a);
            return;
        }
        else{
            for(int i=l;i<=r;i++){
                swap(a[i],a[l]);
                help(ans,a,l+1,r);
                swap(a[i],a[l]);
            }
        }
    }
    void help2(vector<vector<int>>&ans,vector<int>&nums,vector<int>&v,vector<int>&freq){
        if(v.size()==nums.size()){
            ans.push_back(v);
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(!freq[i]){
                    v.push_back(nums[i]);
                    freq[i]=1;
                    help2(ans,nums,v,freq);
                    freq[i]=0;
                    v.pop_back();
                }
            }
        }
    }
    void help3(vector<vector<int>>&ans,vector<int>&nums,int l, int r){
        if(l==r){
            ans.push_back(nums);
            return;
        }
        else{
            for(int i=l;i<=r;i++){
                if(!good(nums,l,i)) continue;
                swap(nums[i],nums[l]);
                help3(ans,nums,l+1,r);
                swap(nums[i],nums[l]);
            }
        }
    }
    bool good(vector<int>&nums, int l, int idx){
        for(int i=l;i<idx;i++){
            if(nums[i]==nums[idx]){
                return false;
            }
        }
        return true;
    }

    void help4(vector<vector<int>>&ans,vector<int>&nums,vector<int>&v,vector<int>&freq){
        if(v.size()==nums.size()){
            ans.push_back(v);
        }
        else{
            for(int i=0;i<nums.size();i++){
                if(!freq[i]){
                    if(i>0 && freq[i-1]==0 && nums[i-1]==nums[i])continue;
                    v.push_back(nums[i]);
                    freq[i]=1;
                    help4(ans,nums,v,freq);
                    freq[i]=0;
                    v.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        help(ans,nums,0,n-1);
        return ans;
    }
    vector<vector<int>> permute2(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v,freq(n);
        help2(ans,nums,v,freq);
        return ans;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        help3(ans,nums,0,n-1);
        return ans;
    }
    vector<vector<int>> permuteUnique2(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>v,freq(n);
        help4(ans,nums,v,freq);
        return ans;
    }
};

int main(){
    Permutation sol;
    vector<int>a={1,2,3,4};
    auto v=sol.permute(a);
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"------------\n";
    v=sol.permute2(a);
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"------------\n";
    a={1,2,2,4};
    v=sol.permuteUnique(a);
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"------------\n";
    v=sol.permuteUnique2(a);
    for(auto vec:v){
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
}