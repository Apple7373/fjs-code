#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(char val):val(val), left(nullptr), right(nullptr) {}
};
int idx = 0;
TreeNode* dfs(string s) {
    if (idx >= s.size()) return nullptr;
    if (s[idx] == '#') {
        return nullptr;
    }
    TreeNode* cur = new TreeNode(s[idx]);
    idx++;
    cur->left = dfs(s);
    idx++;
    cur->right = dfs(s);
    return cur;
}

void post(TreeNode* root) {
    if (root == nullptr) return;
    post(root->left);
    post(root->right);
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
    TreeNode* root = dfs(s);
    post(root);
    cout << endl;
    inorder(root);
}