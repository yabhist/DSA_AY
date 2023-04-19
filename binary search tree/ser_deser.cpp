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

class Codec {
    string s="";
    int i=0;

    TreeNode* D(vector<string>& v, int l , int r){
        if(l>r){
            return NULL;
        }
        TreeNode* root= new TreeNode(stoi(v[l]));
        for(i=l;i<=r;i++){
            if(stoi(v[i])>stoi(v[l])){
                break;
            }
        }
        root->left=D(v,l+1,i-1);
        root->right=D(v,i,r);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        s+=to_string(root->val);
        s+=',';
        serialize(root->left);
        serialize(root->right);
        return s;
    }

    TreeNode* deserialize(string data) {
        vector<string>v;
        istringstream tmp(data);
        string t;
        while(getline(tmp,t,',')){
            v.push_back(t);
        }
        return D(v,0,v.size()-1);
    }
};

int main(){
    
}