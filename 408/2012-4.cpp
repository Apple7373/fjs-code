#include<bits/stdc++.h>

using namespace std;
map<char,int> m;
string pre, in, post;

struct Treenode{
    char val;
    Treenode* left;
    Treenode* right;
    Treenode(){}
    Treenode(char val):val(val),left(nullptr), right(nullptr)
    {}
};

Treenode* preAndIn(int ps, int pe, int is, int ie, string pre) {
    if (ps > pe || is > ie) return nullptr;
    Treenode* cur = new Treenode(pre[ps]);
    int ri = m[pre[ps]];
    cur->left = preAndIn(ps+1, ps+ri-is, is, ri-1, pre);
    cur->right = preAndIn(ps+ri-is+1, pe, ri+1, ie, pre);
    return cur;
}

void postcout(Treenode* root) {
    if (root == nullptr) return ;
    postcout(root->left);
    postcout(root->right);
    cout << root->val;
}

Treenode* postAndIn(int is, int ie, int ps, int pe, string post) {
    if (is > ie || ps > pe) return nullptr;
    Treenode* cur = new Treenode(post[pe]);
    int ri = m[post[pe]];
    cur->left = postAndIn(is, ri-1, ps, ps+ri-is-1, post);
    cur->right = postAndIn(ri+1, ie, ri+ps-is, pe-1, post);
    return cur;
}

void precout(Treenode* root) {
    if (root == nullptr) return ;
    cout << root->val;
    precout(root->left);
    precout(root->right);
}
int main()
{
    // 1、输入前序中序，给出后序
    // cout << "请输入前序：";
    // cin >> pre;
    // cout << "请输入中序：";
    // cin >> in;
    // for (int i = 0; i < in.size(); i++) m[in[i]] = i;
    // Treenode* root = preAndIn(0, in.size()-1, 0, in.size()-1, pre);
    // // 遍历
    // cout << "后序遍历结果：";
    // postcout(root);

    // 2、输入中序后序，给出前序
    cout << "请输入中序：";
    cin >> in;
    cout << "请输入后序：";
    cin >> post;
    for (int i = 0; i < in.size(); i++) m[in[i]] = i;
    Treenode* root = postAndIn(0, in.size()-1, 0, in.size()-1, post);
    cout << "前序遍历结果：";
    precout(root);
}