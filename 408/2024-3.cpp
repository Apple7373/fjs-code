#include <bits/stdc++.h>

using namespace std;
 // 
int main()
{
    string s;
    getline(cin, s);

    vector<char> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')' || 
            s[i] >= '0' && s[i] <= '9' || s[i] == '-' || s[i] == '+' || s[i] == ' ') {
                // 输入符合要求
                if (s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')') 
                    ans.push_back(s[i]);
            } else {
                cout << "input error" << endl;
                return 0;
            }
    }

    stack<char> st;
    bool flag = true;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '{' || ans[i] == '(' || ans[i] == '[') st.push(ans[i]);
        else if(ans[i] == '}') {
            if (st.size() > 0 && st.top() == '{') st.pop();
            else {
                flag = false;
                break;
            }
        } else if (ans[i] == ']') {
            if (st.size() > 0 && st.top() == '[') st.pop();
            else {
                flag = false;
                break;
            }
        } else if (ans[i] == ')') {
            if (st.size() > 0 && st.top() == '(') st.pop();
            else {
                flag = false;
                break;
            }
        }
    }

    if (flag) cout << "yes ";
    else cout << "no ";

    for (auto i : ans) {
        cout << i;
    }
    cout << endl;

    return 0;
}