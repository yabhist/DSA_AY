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
string serialize(TreeNode * root)
{
    if(!root) return "";
    string s="";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        if(node==NULL)
        {
            s+="#,";
        }
        else
        {
            s+=to_string(node->val)+",";
        }
        if(node!=NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode * deserialize(string data)
{
    if(data.size()==0 || data[0] == '#') return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")
        {
            node->left=NULL;
        }
        else
        {
            TreeNode* leftnode=new TreeNode(stoi(str));
            node->left=leftnode;
            q.push(leftnode);
        }
        getline(s,str,',');
        if(str=="#")
        {
            node->right=NULL;
        }
        else
        {
            TreeNode* rightnode=new TreeNode(stoi(str));
            node->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}

TreeNode* buildTree(string str)
{
   if(str.length() == 0 || str[0] == '#')
       return NULL;

   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   TreeNode* root = new TreeNode(stoi(ip[0]));

   queue<TreeNode*> queue;
   queue.push(root);

   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       TreeNode* currTreeNode = queue.front();
       queue.pop();

       string currVal = ip[i];

       if(currVal != "#") {

           currTreeNode->left = new TreeNode(stoi(currVal));

           queue.push(currTreeNode->left);
       }
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];
       if(currVal != "#") {

           currTreeNode->right = new TreeNode(stoi(currVal));

           queue.push(currTreeNode->right);
       }
       i++;
   }

   return root;
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
    string s=serialize(root);
    cout<<s<<'\n';
    auto root1=deserialize("1,2,3,4,5,6,7,#,#,#,#,#,#,#,#,");
    for(auto i:levelorder(root1))
    {
        for(auto j:i)
        {    
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    auto root2=buildTree("1 2 3 4 5 6 7 # # # # # # # #");
    for(auto i:levelorder(root2))
    {
        for(auto j:i)
        {    
            cout<<j<<" ";
        }
        cout<<'\n';
    }
}