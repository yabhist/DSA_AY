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
//convert bst to Balanced bst
class Solution {
    vector<int>v;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* create(int l, int r){
        if(l>r){
            return NULL;
        }
        int m=(l+r)/2;
        TreeNode* root=new TreeNode(v[m]);
        root->left=create(l,m-1);
        root->right=create(m+1,r);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return create(0,v.size()-1);
    }
};

int main(){

}