#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* recur(int l, int r, vector<int>& nums){
        if(l>r){
            return NULL;
        }
        int i=max_element(nums.begin()+l,nums.begin()+r+1)-nums.begin();
        TreeNode* root=new TreeNode(nums[i]);
        root->left=recur(l,i-1,nums);
        root->right=recur(i+1,r,nums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recur(0,nums.size()-1,nums);
    }
};
int main(){
    
}