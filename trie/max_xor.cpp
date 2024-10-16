// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
#include<bits/stdc++.h>
using namespace std;

class BitwiseTrie {
    struct Node{
        Node* links[2]={NULL,NULL};
        bool containsKey(int bit){
            return links[bit]!=NULL;
        }
        void put(int bit, Node* node){
            links[bit]=node;
        }
        Node* get(int bit){
            return links[bit];
        }
    };
    Node* root=NULL;
public:
    BitwiseTrie() {
        root=new Node();
    }
    
    void insert(int num) {
        Node* node=root;
        for(int i=30;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int getmax(int num){
        Node* node=root;
        int ans=0;
        for(int i=30;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                ans|=(1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        BitwiseTrie bt;
        for(int i=0;i<n;i++){
            bt.insert(nums[i]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,bt.getmax(nums[i]));
        }
        return mx;
    }
};

int main(){

}