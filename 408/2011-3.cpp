#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<char> ans;
    char tar;
    cin >> tar;
    ans.push_back(tar);
    int idx = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == tar) {
            idx = i;
            break;
        }
    }
    for (int i = idx-1; i >= 0; i--) {
        if (s[i] == '(') {
            if (st.size() == 0) {
                if (--i > 0) ans.push_back(s[i]); 
            } else if (st.size() > 0 && st.top() == ')') {
                st.pop();
            }
        } else if (s[i] == ')') st.push(s[i]);
    }
    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i];
        if (i != 0) cout << '>';
    }
    return 0;
}