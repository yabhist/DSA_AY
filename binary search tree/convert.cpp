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
//sorted array to BST
TreeNode* sortedArrayToBST1(vector<int>& nums) {
    typedef vector<int>::const_iterator Iter;
    queue<tuple<TreeNode**, Iter, Iter>> q;

    TreeNode* ans = nullptr;
    q.push({&ans, cbegin(nums), cend(nums)});

    while (!empty(q)) {
        auto [nptr, b, e] = q.front(); q.pop();

        if (b == e) continue;

        Iter mid = next(b, distance(b, e) / 2);
        *nptr = new TreeNode(*mid);

        q.push({&(*nptr)->left, b, mid});
        q.push({&(*nptr)->right, mid + 1, e});
    }

    return ans;
}
TreeNode* sortedArrayToBST2(vector<int>& nums) {
    typedef vector<int>::const_iterator Iter;
    stack<tuple<TreeNode**, Iter, Iter>> st;

    TreeNode* ans = nullptr;
    st.push({&ans, cbegin(nums), cend(nums)});

    while (!empty(st)) {
        auto [nptr, b, e] = st.top(); st.pop();

        if (b == e) continue;

        Iter mid = next(b, distance(b, e) / 2);
        *nptr = new TreeNode(*mid);

        st.push({&(*nptr)->left, b, mid});
        st.push({&(*nptr)->right, mid + 1, e});
    }

    return ans;
}
TreeNode* recur(vector<int>&nums,int l,int r){
    if(l>r){
        return NULL;
    }
    int m=(l+r)/2;
    TreeNode* tmp=new TreeNode(nums[m]);
    tmp->left=recur(nums,l,m-1);
    tmp->right=recur(nums,m+1,r);
    return tmp;
}
TreeNode* sortedArrayToBST3(vector<int>& nums) {
    return recur(nums,0,(int)nums.size()-1);
}
int main(){

}