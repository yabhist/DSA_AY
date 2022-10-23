#include<bits/stdc++.h>
using namespace std;

class bst
{
        int data;
        bst* left;
        bst* right;
    public:
        bst();
        bst(int);
        bst* insert(bst*,int);
        bst* search(bst*,int);
        bst* deletenode(bst* , int );
        void inorder(bst*);

};

bst::bst():data(0),left(NULL),right(NULL){}
bst::bst(int val)
{
    data=val;
    left=right=NULL;
}
bst* bst::insert(bst* root, int val)
{
    if(!root)
    {
        return new bst(val);
    }
    if(val > root->data)
    {
        root->right= insert(root->right,val);
    }
    else if(val < root->data)
    {
        root->left= insert(root->left,val);
    }
    return root;
}
void bst ::inorder(bst* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}
bst* bst::search(bst* root, int val)
{
    if (root == NULL || root->data == val)
       return root;
    
    if (root->data < val)
       return search(root->right, val);
 
    return search(root->left, val);
}
bst* bst:: deletenode(bst* root, int k) 
{ 
    if (root == NULL) 
        return root; 
    if(root->data > k){ 
        root->left = deletenode(root->left, k); 
        return root; 
    } 
    else if(root->data < k){ 
        root->right = deletenode(root->right, k); 
        return root; 
    } 


    if (root->left == NULL) { 
        bst* temp = root->right;
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        bst* temp = root->left; 
        delete root; 
        return temp; 
    } 
    else {
        bst* Parent = root;
        bst *succ = root->right; 
        while (succ->left != NULL) { 
            Parent = succ; 
            succ = succ->left; 
        } 

        if (Parent != root) 
            Parent->left = succ->right; 
        else
            Parent->right = succ->right;
        root->data = succ->data; 
        delete succ;          
        return root; 
    } 
} 

int main()
{
    bst b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
    b.inorder(root);
    cout<<'\n';
    cout<<(b.search(root,30)?"found":"not found")<<'\n';
    cout<<(b.search(root,130)?"found":"not found")<<'\n';
    b.deletenode(root,60);
    b.deletenode(root,30);
    b.inorder(root);
    cout<<'\n';    
}