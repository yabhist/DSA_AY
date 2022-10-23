#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;

using namespace std;

//         1
//     2      3
//  4     5  6    7

// struct TreeNode { //class TreeNode
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//   };

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct Node* root)  //rLR
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root)  //LrR
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root)  //LRr
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node* root= new Node(1);//struct Node* root
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    
    // struct TreeNode* lfch= new TreeNode(2);
    // struct TreeNode* rgch= new TreeNode(3);
    // struct TreeNode* root=  new TreeNode(1,lfch,rgch);
    // root->left->left= new TreeNode(4);
    // root->left->right= new TreeNode(5);
    // root->right->left= new TreeNode(6);
    // root->right->right=new TreeNode(7);
    // postorder(root);
}