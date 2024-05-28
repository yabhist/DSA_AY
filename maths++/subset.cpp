#include<bits/stdc++.h>
using namespace std;

class Subset {
    void help(vector<vector<int>>&v,vector<int>&s,vector<int>&nums,int index){
        v.push_back(s);
        for(int i=index;i<nums.size();i++){
            s.push_back(nums[i]);
            help(v,s,nums,i+1);
            s.pop_back();
        }
        // v.push_back(s);
    }

    void help2(vector<vector<int>>&ans,vector<int>&q,vector<int>&v, int i){
        if(i==v.size()){
            ans.push_back(q);
            return;
        }
        q.push_back(v[i]);
        help2(ans,q,v,i+1);
        q.pop_back();
        
        help2(ans,q,v,i+1);
    }

    void help3(vector<vector<int>>&ans,vector<int>&nums,vector<int>&v,int l){
        ans.push_back(v);
        for(int i=l;i<nums.size();i++){
            if(i!=l && i>0 && nums[i-1]==nums[i]){
                continue;
            }
            v.push_back(nums[i]);
            help3(ans,nums,v,i+1);
            v.pop_back();
        }
    }

    void help4(vector<vector<int>>&ans,vector<int>&v,vector<int>&nums,int i,vector<bool>&is){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        if(!(i-1>=0 && (!is[i-1]) && nums[i]==nums[i-1])){
            v.push_back(nums[i]);
            is[i]=1;
            help4(ans,v,nums,i+1,is);
            is[i]=0;
            v.pop_back();
        }
        help4(ans,v,nums,i+1,is);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>s;
        help(v,s,nums,0);
        return v;
    }
    vector<vector<int>> subsets2(vector<int>& v) {
        vector<vector<int>>ans;
        vector<int>q;
        help2(ans,q,v,0);
        return ans;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        help3(ans,nums,v,0);
        return ans;
    }
    vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        vector<bool>is(nums.size());
        sort(nums.begin(),nums.end());
        help4(ans,v,nums,0,is);
        return ans;
    }
    void KlenSubsets(vector<int>&choices, int current, int K, vector<int>&selected){
        if(choices.size()-current<K-selected.size())
            return;
        if(selected.size()==K){
            for(auto i:selected)
                cout<<i<<" ";
            cout<<endl;
            return;
        }
        if(current==choices.size())
            return;

        selected.push_back(choices[current]);
        KlenSubsets(choices,current+1,K,selected);
        selected.pop_back();
        KlenSubsets(choices,current+1,K,selected);
    }
};

int main(){
    Subset sol;
    vector<int>a={1,2,3,4};
    auto v=sol.subsets(a);
    for(auto vec:v){
        if(vec.empty()){
            cout<<"phi\n";
            continue;
        }
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"------------\n";
    v=sol.subsets2(a);
    for(auto vec:v){
        if(vec.empty()){
            cout<<"phi\n";
            continue;
        }
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"------------\n";
    vector<int>selected;
    sol.KlenSubsets(a,0,3,selected);
    cout<<"------------\n";
    a={1,3,1,2,2,4};
    v=sol.subsetsWithDup(a);
    for(auto vec:v){
        if(vec.empty()){
            cout<<"phi\n";
            continue;
        }
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
    cout<<"------------\n";
    v=sol.subsetsWithDup2(a);
    for(auto vec:v){
        if(vec.empty()){
            cout<<"phi\n";
            continue;
        }
        for(auto i:vec){
            cout<<i<<' ';
        }cout<<'\n';
    }
}