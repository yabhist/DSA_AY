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
// Given an integer n, return a list of all possible full binary trees with n nodes.
class Solution {

    map<int,vector<TreeNode*>>memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(memo.find(n)==memo.end()){
            vector<TreeNode*>v;
            if(n==1){
                v.push_back(new TreeNode());
            }
            else if(n&1){
                for(int x=0;x<n;x++){
                    int y=n-1-x;
                    for(TreeNode* left: allPossibleFBT(x)){
                        for(TreeNode* right:allPossibleFBT(y)){
                            TreeNode* p=new TreeNode();
                            p->left=left;
                            p->right=right;
                            v.push_back(p);
                        }
                    }
                }
            }
            memo[n]=v;
        }
        return memo[n];
    }
};
int main(){

}