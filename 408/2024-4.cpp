#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(char val):val(val), left(nullptr), right(nullptr) {}
};
TreeNode* dfs(string s, int idx) {
    if (idx >= s.size()) return nullptr;
    if (s[idx] == '#') {
        return nullptr;
    }
    TreeNode* cur = new TreeNode(s[idx]);
    cur->left = dfs(s, idx+1);
    cur->right = dfs(s, idx+2);
    return cur;
}

void pre(TreeNode* root) {
    if (root == nullptr) return;
    pre(root->left);
    pre(root->right);
    cout << root->val; 
}
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
     
}

int main()
{
    string s;
    cin >> s;
    TreeNode* root = dfs(s, 0);
    pre(root);
    cout << endl;
    inorder(root);
}