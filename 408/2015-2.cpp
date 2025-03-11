#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> ans; 
vector<char> cur; // 当前符合条件的结果
vector<char> nums = {'a','b','c'};  
vector<bool> st(nums.size(), false);
int n;
void dfs() {
    // 进入一层循环 首先判断cur是否满足条件
    if (cur.size() == n) {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        // if (!st[i]) {
            cur.push_back(nums[i]);
            // st[i] = true;
            dfs();
            // st[i] = false;
            cur.pop_back();
        // }
    }
}

int main()
{
    cin >> n;
    dfs();
    for (auto it : ans) {
        for (auto it2 : it) cout << it2;
        cout << ' ';
    }
    cout << ans.size() << endl;
}