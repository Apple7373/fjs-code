#include <bits/stdc++.h>

using namespace std;
struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char ch):val(ch), left(nullptr), right(nullptr) {}
};
map<char, int> m;
stack<char> op;
stack<TreeNode*> node;
string s;

void out(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val;
    out(root->left);
    out(root->right);
}
void operation() {
    // 取出左右操作数
    TreeNode* r = node.top();
    node.pop();
    TreeNode* l = node.top();
    node.pop();
    // 取出操作符
    TreeNode* root = new TreeNode(op.top());
    op.pop();
    root->left = l;
    root->right = r;
    node.push(root);
}
int main()
{
    m['-'] = 1;
    m['+'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        // 1、如果是字母，直接node栈
        if (isalpha(s[i])) {
            TreeNode* cur = new TreeNode(s[i]);
            node.push(cur);
        } 
        else if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
            if (op.size() == 0 || m[op.top()] < m[s[i]]) op.push(s[i]);
            else { // 当前栈顶操作符优先级小于 当前操作符
                while (op.size() > 0 && m[op.top()] >= m[s[i]]) {
                    operation();
                }
                op.push(s[i]);
            }
        }
        else if (s[i] == '(') op.push(s[i]);
        else if (s[i] == ')') {
            while (op.top() != '(') {
                // 取出左右操作数
                TreeNode* r = node.top();
                node.pop();
                TreeNode* l = node.top();
                node.pop();
                // 取出操作符
                TreeNode* root = new TreeNode(op.top());
                op.pop();
                root->left = l;
                root->right = r;
                node.push(root);
            }
            op.pop(); // 删除（
        }
    }
    // 处理剩余运算符
    while (op.size() > 0) {
        // 取出左右操作数
        TreeNode* r = node.top();
        node.pop();
        TreeNode* l = node.top();
        node.pop();
        // 取出操作符
        TreeNode* root = new TreeNode(op.top());
        op.pop();
        root->left = l;
        root->right = r;
        node.push(root);
    }

    TreeNode* root = node.top();
    out(root);
    return 0;
} // a+b*(c-d)-e/f