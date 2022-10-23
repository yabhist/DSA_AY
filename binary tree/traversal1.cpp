#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;

using namespace std;

//         1
//     2      3
//  4     5  6    7

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
vector<int> preorder(TreeNode * root)
{
    vector<int>pre;
    if(root==NULL)
    {
        return pre;
    }
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* node=s.top();
        s.pop();
        pre.push_back(node->val);
        if(node->right!=NULL) s.push(node->right);
        if(node->left!=NULL) s.push(node->left);
    }
    return pre;
}
vector<int> inorder(TreeNode* root)
{
    vector<int>in;
    if(root==NULL)
    {
        return in;
    }
    stack<TreeNode* >s;
    TreeNode* node=root;
    while(1)
    {
        if(node!=NULL)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.empty()) break;
            node=s.top();
            s.pop();
            in.push_back(node->val);
            node=node->right;
        }
    }
    return in;
}
vector<int>postorder1(TreeNode* root)
{
    vector<int>post;
    if(root==NULL)
    {
        return post;
    }
    stack<TreeNode*>s,st;
    TreeNode* node=root;
    s.push(node);
    while(!s.empty())
    {
        node=s.top();
        s.pop();
        st.push(node);
        if(node->left!=NULL)
        {
            s.push(node->left);
        }
        if(node->right!=NULL)
        {
            s.push(node->right);
        }
    }
    while(!st.empty())
    {
        post.push_back(st.top()->val);
        st.pop();
    }
    return post;
}
vector<int>postorder2(TreeNode* root)
{
	vector<int> postOrderList;
	if (root == NULL)
		return postOrderList;
	stack<TreeNode*> S;
	S.push(root);
	TreeNode* prev = NULL;
	while (!S.empty()) {
		auto current = S.top();
		if (prev == NULL || prev->left == current
			|| prev->right == current) {
			if (current->left)
				S.push(current->left);
			else if (current->right)
				S.push(current->right);
			else {
				S.pop();
				postOrderList.push_back(current->val);
			}
		}

		else if (current->left == prev) {
			if (current->right)
				S.push(current->right);
			else {
				S.pop();
				postOrderList.push_back(current->val);
			}
		}
		else if (current->right == prev) {
			S.pop();
			postOrderList.push_back(current->val);
		}
		prev = current;
	}
	return postOrderList;
}
vector<vector<int>>zigzagorder(TreeNode * root)
{
    vector<vector<int>>ans;
    int flag=1;
    if(root==NULL)
    {
        return ans;
    }
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>zigzag(size);
        for(int i=0;i<size;i++)
        {
            TreeNode * node=q.front();
            q.pop();
            int index=flag?i:size-i-1;
            if(node->left!=NULL)
            {
                q.push(node->left);
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
            }
            zigzag[index]=node->val;
        }
        flag=!flag;
        ans.push_back(zigzag);
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
    root->right->right=new TreeNode(7);
    for(int i=0;i<7;i++)
    cout<<postorder2(root)[i]<<" ";
    cout<<'\n';
    for(auto j:postorder1(root))
    cout<<j<<" ";
    cout<<'\n';
    for(auto i:levelorder(root))
    {
        for(auto j:i)
        {    
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    for(auto j:preorder(root))
    cout<<j<<" ";
    cout<<'\n';
    for(auto j:inorder(root))
    cout<<j<<" ";
    cout<<'\n';
    for(auto i:zigzagorder(root))
    {
        for(auto j:i)
        {    
            cout<<j<<" ";
        }
        cout<<'\n';
    }
}