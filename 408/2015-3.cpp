#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<pair<char,int>> st;
    string s;
    cin >> s;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == ')') st.push({')', i});
        else if (s[i] == '+') st.push({'+', i});
        else if (s[i] == '-') st.push({'-', i});
        else if (s[i] == '(' && i > 1 && s[i-1] == '-') {
            int nl = 1;
            stack<pair<char,int>> cur; // 存储删除的元素
            while (nl > 0) {
                if (st.top().first == '+') {
                    st.top().first = '-';
                    cur.push(st.top());
                    st.pop();
                } else if (st.top().first == '-') {
                    st.top().first = '+';
                    cur.push(st.top());
                    st.pop();
                } else if (st.top().first == ')') {
                    nl--;
                    cur.push(st.top());
                    st.pop();
                } else if (st.top().first == '(') {
                    nl++;
                    cur.push(st.top());
                    st.pop();
                } 
                // cout << "*";
            }
            // 处理完 
            // 将cur里面的元素再加入到st中
            while (cur.size() > 0) {
                st.push(cur.top());
                cur.pop();
            }
            // cout << "---";
            st.push({s[i], i});  // 加入（  
        }   
    }
    // cout << "+++";
    while (st.size() > 0) {
        if (st.top().first == '-' || st.top().first == '+') {
            s[st.top().second] = st.top().first;
        }
        st.pop();
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '(' && s[i] != ')') cout << s[i];
    }


    // a-(b+c-(e-(f+g)))   a-b-c+e-f-g
    // a-(b-c)
    // a-(b-(((c+d))))  a-b+c+d
    return 0;
}