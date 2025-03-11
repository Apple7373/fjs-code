#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int max = 0;
    
    int beg = 0;
    vector<char> ans;
    for (int i = 1; i <= s.size(); i++) {  // 重点是下标起止位置
        if (i == s.size() || s[i] != s[i-1]) {
            int curlen = i-beg;
            if (max < curlen) {
                max = curlen;
                ans.clear();   
            }
            ans.push_back(s[i-1]);
            beg = i;
        }
    }
    cout << max << ' ';
    for (char i : ans) {
        cout << i << ' ';
    }
}