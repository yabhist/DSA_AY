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
    int i;
    TreeNode* help(vector<int>& preorder, int l, int r){
        if(l>r){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[l]);
        for(i=l;i<=r;i++){
            if(preorder[i] > preorder[l]){
                break;
            }
        }
        root->left=help(preorder,l+1,i-1);
        root->right=help(preorder,i,r);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return help(preorder,0,preorder.size()-1);
    }
};

int main(){
    
}