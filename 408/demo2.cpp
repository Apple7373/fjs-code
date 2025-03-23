#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){}
	TreeNode(char c):val(c), left(nullptr), right(nullptr){}
};

string s;

TreeNode* dfs(int& idx) {
    if (idx >= s.size() || s[idx] == '#') return nullptr;
    TreeNode* cur = new TreeNode(s[idx]);
    cur->left = dfs(++idx);
    cur->right = dfs(++idx);
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
    cout << (int)'z' << endl;

}