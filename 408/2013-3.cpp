/*
3、编写程序:输入表达式，输出相应二叉树的先序遍历结果（干脆中缀转前缀 后缀都给出了 ，有示例）
输入: a+b*(c-d)-e/f
输出: -+a*b-cd/ef
infix: a+b-a*((c+d)/e-f)+g
suffix: ab+acd+e/f-*-g+
prefix: +-+ab*a-/+cdefg

思路：我是用中缀构建一棵二叉树，需要两个栈 节点node栈，和运算符栈
从左往右扫描中缀表达式
    1、遇到字母，生成一个TreeNode节点指针，节点值为字母，然后加入节点栈中
    2、遇到运算符ch，如果ch的优先级大于栈顶元素的优先级，那么直接入栈；否则，运算符栈一直出栈直到栈顶符号优先级小于ch，或者栈变空。
    3、遇到 （ 直接进栈，遇到 ），运算符栈一直出栈直到遇到（。

    关于运算符出栈，就意味着一颗字数形成，根为运算符。每次形成一棵子树时，需要从node栈连续出两个元素，先出来的作为右孩子，后出来的作为左孩子。
    形成一棵子树后将根节点重新加入到node栈中。
*/

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