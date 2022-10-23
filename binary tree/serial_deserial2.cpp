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
string serialize(TreeNode * root) {//postorder
  if (!root)
    return "#";
  string left = serialize(root -> left);
  string right = serialize(root -> right);
  return left + ',' + right + ',' + to_string(root -> val);
}
TreeNode * deserialize(string & data) {
  if (data.back() == '#') {
    data.pop_back();
    if (data.size())
      data.pop_back();
    return NULL;
  }
  int n = 0;
  for (int i = data.size() - 1, j = 1; i >= 0 && data[i] != ','; i--, j *= 10) {
    if (data[i] == '-')
      n = -n;
    else
      n += (data[i] - '0') * j;
    data.pop_back();
  }
  if (data.size())
    data.pop_back();
  TreeNode * root = new TreeNode(n);
  root -> right = deserialize(data);
  root -> left = deserialize(data);
  return root;
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



string my_serialize(TreeNode * root) {//postorder
  if (!root)
    return "#";
  string left = my_serialize(root -> left);
  string right = my_serialize(root -> right);
  return left + ' ' + right + ' ' + to_string(root -> val);
}
TreeNode* help_me(vector<string>&data, int &i)
{
    if (data.at(i) == "#")
    {
        i++;
    return NULL;
    }
    
    TreeNode* root = new TreeNode(stoi(data.at(i)));
    i++;
    root->right = help_me(data,i);
    root->left = help_me(data,i);
    
    return root;
}
TreeNode* my_deserialize(string data)
{
    vector<string> result;
    istringstream iss(data);
    for (string s; iss >> s; )
        result.push_back(s);
        reverse(result.begin(),result.end());
        int i = 0;
        return help_me(result, i);
    
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
    TreeNode* root1=deserialize(s);
    postorder(root1);
    cout<<'\n';

    string s2=my_serialize(root);
    for(auto i:s2)
    {
        cout<<i;
    }
    cout<<'\n';
    TreeNode* root2=my_deserialize(s2);
    postorder(root2);
    cout<<'\n';
}