/*
给一个字符串(aaaa(bbbb(cccc,dddd),eeee(ffff)))该字符串
表明的是各个人的层次关系。
比如aaaa是bbbb和eeee的领导，bbbb是cccc和dddd的领导。
现输入一个名称，比如ffff,要求输出其领导关系
input:  (aaaa(bbbb(cccc,dddd),eeee(ffff)))
output: aaaa>eeee>ffff
*/
#include <bits/stdc++.h>

// 遇到（ 如果栈里面没有 ）, 那么（ 左边的字母就是一个祖先  前提是（ 左边有字母 
// 遇到）直接进栈 
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