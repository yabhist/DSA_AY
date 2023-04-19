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
TreeNode* build(vector<int>&pre,int pres, int pree, int ins, int ine, map<int,int>&mp)
{
    if(pres>pree || ins>ine)return NULL;
    TreeNode* root=new TreeNode(pre[pres]);
    int a=mp[root->val];
    int b=a-ins;
    root->left=build(pre,pres+1,pres+b,ins,a-1,mp);
    root->right=build(pre,pres+b+1,pree,a+1,ine,mp);
    return root;
}
TreeNode* build1(vector<int>&post,int posts, int poste, int ins, int ine, map<int,int>&mp)
{
    if(posts>poste || ins>ine)return NULL;
    TreeNode* root=new TreeNode(post[poste]);
    int a=mp[root->val];
    int b=a-ins;
    root->left=build1(post,posts,posts+b-1,ins,a-1,mp);
    root->right=build1(post,posts+b,poste-1,a+1,ine,mp);
    return root;
}
vector<vector<int>>levelorder(TreeNode * root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            TreeNode * node=q.front();
            q.pop();
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
void preorder(struct TreeNode* root)  //rLR
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct TreeNode* root)  //LrR
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(struct TreeNode* root)  //LRr
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main()
{
    vector<int>in={7,2,9,3,1};
    vector<int>pre={3,9,2,7,1};
    map<int,int>mp;
    for(int i=0;i<in.size();i++)
    {
        mp[in[i]]=i;
    }
    TreeNode* root=build(pre,0,4,0,4,mp);
    for(auto i:levelorder(root))
    {
        for(auto j:i)
        {    
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;


    vector<int>post={7,2,9,1,3};
    TreeNode* root1=build1(post,0,4,0,4,mp);
    for(auto i:levelorder(root1))
    {
        for(auto j:i)
        {    
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    preorder(root1);
    cout<<endl;
    inorder(root1);
    cout<<endl;
    postorder(root1);
    cout<<endl;

}