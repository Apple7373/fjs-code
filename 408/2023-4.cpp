#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char c) {
        val = c;
        left = nullptr;
        right = nullptr;
    }
};
int i = 0;

TreeNode* dfs(string s) {
    if (s[i] == '#' || i >= s.size()) return nullptr;
    TreeNode* cur = new TreeNode(s[i]);
    i++;
    cur->left = dfs(s);
    i++;
    cur->right = dfs(s);
    return cur;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val;
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}
int main()
{
    string s;
    cin >> s;
    
    TreeNode* root = dfs(s); // 构建树

    inorder(root);
    cout << endl;
    postorder(root);
    return 0;
}