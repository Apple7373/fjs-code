#include <bits/stdc++.h>

using namespace std;

bool check(char ch) {
    if (ch == '{' || ch == '}' || ch == '[' ||
        ch == ']' || ch == '(' || ch == ')' ||
        ch >= '0' && ch <= '9' || ch == '+' ||
        ch == '-' || ch == ' ')
        return true;
    else return false;
}
int main()
{
    string s;
    getline(cin, s);
    // cin >> s;
    stack<char> st;
    vector<char> ans;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (check(s[i])) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
                ans.push_back(s[i]);
            } else if ((s[i] == '}' || s[i] == ')' ||s[i] == ']' ) && st.size() == 0){
                flag = false;
                ans.push_back(s[i]);
            } 
            else if (s[i] == '}' && st.size() > 0) {
                ans.push_back(s[i]);
                char t = st.top();
                st.pop();
                if (t != '{') flag = false; 
            } else if (s[i] == ']'  && st.size() > 0) {
                ans.push_back(s[i]);
                char t = st.top();
                st.pop();
                if (t != '[') flag = false; 
            } else if (s[i] == ')'  && st.size() > 0) {
                ans.push_back(s[i]);
                char t = st.top();
                st.pop();
                if (t != '(') flag = false; 
            }
        } else {
            cout << "input error" << endl;
            return 0;
        }
    }

    if (flag ) {
        cout << "yes" << ' ';
    } else cout << "no" << ' ';
    
    for (auto it : ans) cout << it;
    cout << endl;

}