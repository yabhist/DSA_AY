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
//Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original 
//BST is changed to the original key plus the sum of all keys greater than the original key in BST.
class Solution {
    int sum=0;
    void sm(TreeNode* root){
        if(!root){
            return;
        }
        sm(root->right);
        root->val+=sum;
        sum=root->val;
        sm(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        sm(root);
        return root;
    }
};
int main(){

}