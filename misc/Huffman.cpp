#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* left;
    node* right;
    int freq;
    node(int a)
    {
        left=NULL;
        right=NULL;
        freq=a;
    }
};
struct comp
{
    bool operator() (node* a, node*b)
    {
        return a->freq > b->freq;
    }
};
void preorder(struct node* root)  //rLR
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->freq<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root)  //LrR
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->freq<<" ";
    inorder(root->right);
}
node* huffman(priority_queue<node*,vector<node*>,comp>pq , int n)
{
    for(int i=1;i<=n-1;i++)
    {
        node *z= new node(0),*x,*y;
        z->left=x=pq.top();
        pq.pop();
        z->right=y=pq.top();
        pq.pop();
        z->freq=x->freq + y->freq;
        pq.push(z);        
    }
    return pq.top();
}
int main()
{
    map<char,int>fr;
    fr['a']=45;
    fr['b']=13;
    fr['c']=12;
    fr['d']=16;
    fr['e']=9;
    fr['f']=5;
    priority_queue<node*,vector<node*>,comp>pq;
    for(auto i:fr)
    {
        node* z=new node(i.second);
        pq.push(z);
    }
    node * root=huffman(pq,6);
    preorder(root);
    cout<<'\n';
    inorder(root);
    cout<<'\n';
}