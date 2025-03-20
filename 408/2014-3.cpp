#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	stack<char> st;
	int m = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]); // 左括号进栈
			int curm = st.size(); 
			m = max(m, curm);  // 更新栈的最大 大小
		}
		else if (s[i] == ')') st.pop();  // 遇到右括号 栈顶一定是左括号   括号一定是匹配的
	}

	cout << m << endl;

	}