#include<bits/stdc++.h>
using namespace std;

struct TreeNode { //class TreeNode
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> pre,in,post;
void preinpost(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    stack<pair<TreeNode*,int>>s;
    s.push({root,1});
    while(!s.empty())
    {
        auto it=s.top();
        s.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL)
            {
                s.push({it.first->left,1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL)
            {
                s.push({it.first->right,1});
            }
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
}
int main()
{
    struct TreeNode* lfch= new TreeNode(2);
    struct TreeNode* rgch= new TreeNode(3);
    struct TreeNode* root=  new TreeNode(1,lfch,rgch);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left= new TreeNode(6);
    root->right->right=new TreeNode(7);
    preinpost(root);
    for(int i=0;i<7;i++)
    cout<<pre[i]<<" ";
    cout<<'\n';
    for(auto j:in)
    cout<<j<<" ";
    cout<<'\n';
    for(auto j:post)
    cout<<j<<" ";
    cout<<'\n';
}