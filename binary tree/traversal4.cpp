#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;

using namespace std;

//         1
//     2      3
//  4     5  6    7

struct TreeNode { //class TreeNode
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void morris_inorder(TreeNode*root)
{
    TreeNode* cur=root;
    while(cur)
    {
        if(cur->left==NULL)
        {
            cout << cur->val << " ";
            cur=cur->right;
        }
        else
        {
            TreeNode* prev=cur->left;
            while(prev->right && prev->right!=cur)
            {
                prev=prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;

                cur = cur->left;
            }
            else {
                prev->right = NULL;
                cout << cur->val << " ";
                cur = cur->right;
            } 
        }
    }
}
void morris_preorder(TreeNode*root)
{
    TreeNode* cur=root;
    while(cur)
    {
        if(cur->left==NULL)
        {
            cout << cur->val << " ";
            cur=cur->right;
        }
        else
        {
            TreeNode* prev=cur->left;
            while(prev->right && prev->right!=cur)
            {
                prev=prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                cout << cur->val << " ";
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                
                cur = cur->right;
            } 
        }
    }
    
}
void morris_postorder(TreeNode*root)
{
    vector<int>v;
    TreeNode* cur=root;
    while(cur)
    {
        if(cur->right==NULL)
        {
            v.push_back(cur->val);
            cur=cur->left;
        }
        else
        {
            TreeNode* prev=cur->right;
            while(prev->left && prev->left!=cur)
            {
                prev=prev->left;
            }
            if (prev->left == NULL) {
                v.push_back(cur->val);
                prev->left = cur;
                cur = cur->right;
            }
            else {
                prev->left = NULL;
                cur = cur->left;
            } 
        }
    }
    reverse(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i<<" ";
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

    morris_postorder(root);
    cout<<'\n';
    morris_inorder(root);
    cout<<'\n';
    morris_preorder(root);
    cout<<'\n';
}