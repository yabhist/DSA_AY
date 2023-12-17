#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Traversal {
    vector<int>v;
    void help(Node* root){
        if(!root){
            return;
        }
        for(auto i:root->children){
            help(i);
        }
        v.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        v.clear();
        help(root);
        return v;
    }
    vector<int> preorder(Node* root) {
        v.clear();
        if(!root){
            return v;
        }
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node* tmp=st.top();
            st.pop();
            v.push_back(tmp->val);
            for(auto it=tmp->children.rbegin();it!=tmp->children.rend();it++){
                st.push(*it);
            }
        }
        return v;
    }
};
int main(){

}