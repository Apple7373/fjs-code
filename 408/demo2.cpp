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
    cin >> s;
    int idx = 0;
    TreeNode* root = dfs(idx);

    cout << "中序："; 
    inorder(root);
    cout << endl;
    cout << "后序：" ;
    postorder(root);
    cout << endl;

}