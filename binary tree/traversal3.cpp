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
bool isleaf(TreeNode* node)
{
    if(node->left==NULL && node->right==NULL)
    {
        return true;
    }
    return false;
}
void lb(TreeNode* root, vector<int>&res)
{
    TreeNode* node=root->left;
    while(node)
    {
        if(!isleaf(node)) res.push_back(node->val);
        if(node->left!=NULL) node=node->left;
        else node=node->right;
    }
}
void rb(TreeNode* root, vector<int>&res)
{
    TreeNode* node=root->right;
    vector<int>temp;
    while(node)
    {
        if(!isleaf(node)) temp.push_back(node->val);
        if(node->right!=NULL) node=node->right;
        else node=node->left;
    }
    for(auto it=temp.rbegin();it!=temp.rend();it++)
    {
        res.push_back(*it);
    }
}
void lf(TreeNode* root, vector<int>&res)
{
    if(isleaf(root))
    {
        res.push_back(root->val);
        return;
    }
    if(root->left) lf(root->left,res);
    if(root->right) lf(root->right,res);
}
struct store
{
    TreeNode * node;
    int lev;
    int ver;
};

vector<vector<int>>vert(TreeNode* root)
{
    vector<vector<int>>ans;
    map<int,map<int,multiset<int>>> mp;
    queue<store>q;
    q.push({root,0,0});
    while(!q.empty())
    {
        int size=q.size();
        vector<int>v;
        for(int i=0;i<q.size();i++)
        {
            store s=q.front();
            q.pop();
            mp[s.ver][s.lev].insert(s.node->val);
            if(s.node->left) q.push({s.node->left,s.lev+1,s.ver-1});
            if(s.node->right) q.push({s.node->right,s.lev+1,s.ver+1});
        }
    }
    for(auto i:mp)
    {
        vector<int>col;
        for(auto j:i.second)
        {
            col.insert(col.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main()
{
    struct TreeNode* lfch= new TreeNode(2);
    struct TreeNode* rgch= new TreeNode(3);
    struct TreeNode* root=  new TreeNode(1,lfch,rgch);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left= new TreeNode(6);
    root->right->right= new TreeNode(7);
    
    vector<int>res;
    //vector<int>*v=&res;
    if(!root) return 0;
    if(!isleaf(root))res.push_back(root->val);
    lb(root,res);
    lf(root,res);
    rb(root,res);
    for(auto i:res)
    {
        cout<<i<<' ';
    }
    cout<<'\n';
    auto ans=vert(root);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<' ';
        }
        cout<<'\n';
    }
}