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

#include <bits/stdc++.h>

using namespace std;

int n;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> st(nums.size(), false);
        backtrack(nums, st);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<bool>& st) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // if (!st[i]) {
                // st[i] = true;
                cur.push_back(nums[i]);
                backtrack(nums, st);
                cur.pop_back();
                // st[i] = false;
            // }
        }
    }
};

int main() {
    
    cin >> n;
    vector<int> nums = {1,2,3};
    Solution s;
    s.permute(nums);

    for (auto i : s.ans) {
        for (int j : i) {
            cout << j;
        }
        cout << ' ';
    }
    cout << s.ans.size() << endl;
}