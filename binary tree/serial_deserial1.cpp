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

void serializeHelper(TreeNode* root, string &output)
{
    if (!root)
    {
        output =  output + " "+ "#";
        return;
    }
    output = output + " " + std::to_string(root->val);
    
    serializeHelper(root->left, output);
    serializeHelper(root->right,output); 
}
string serialize(TreeNode* root) {
        if (!root)
            return "#";
        
        string output;
        serializeHelper(root,output);
        
        return output;
        
    }
    

TreeNode* deserializeHelper(vector<string>&data, int &i)
{
    if (data.at(i) == "#")
    {
        i++;
    return NULL;
    }
    
    TreeNode* root = new TreeNode(stoi(data.at(i)));
    i++;
    root->left = deserializeHelper(data,i);
    root->right = deserializeHelper(data,i);
    
    return root;
}
TreeNode* deserialize(string data) {
        
    vector<string> result;
    istringstream iss(data);
    for (string s; iss >> s; )
        result.push_back(s);
        
        int i = 0;
        return deserializeHelper(result, i);
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


string serialize1(TreeNode * root) {
      if (!root)
        return "#";
      string left = serialize1(root -> left);
      string right = serialize1(root -> right);
      return to_string(root -> val) + ',' + left + ',' + right;
    }
TreeNode * deserial_help(string data, int & pos) {
  if (pos >= data.size()) return NULL;

  int pos1 = data.find_first_of(",", pos);
  if (pos1 == string::npos) {
    pos1 = data.size();
  }

  TreeNode * root;
  string vals = data.substr(pos, pos1 - pos);
  pos = pos1 + 1;
  if (vals == "#") {
    root = NULL;
    return root;
  }

  int val = atoi(vals.c_str());
  root = new TreeNode(val);

  root -> left = deserial_help(data, pos);
  root -> right = deserial_help(data, pos);
  return root;
}

TreeNode * deserialize1(string data) {
  int pos = 0;
  return deserial_help(data, pos);
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
    for(auto i:s)
    {
        cout<<i;
    }
    cout<<'\n';
    string s1=serialize1(root);
    for(auto i:s1)
    {
        cout<<i;
    }
    cout<<'\n';

    auto root0=deserialize(s);
    preorder(root0);
    cout<<'\n';
    auto root1=deserialize1(s1);
    preorder(root1);
    cout<<'\n';
    cout<<s1<<'\n';

}