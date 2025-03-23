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
			m = max(m, (int)st.size());  // 因为st.size()返回的是一个无符号整数，而max要求比较的两个数据类型一样，所以要将st.size()从无符号整数强转成有符号整数 更新栈的最大 大小
		}
		else if (s[i] == ')') st.pop();  // 遇到右括号 栈顶一定是左括号   括号一定是匹配的
	}

	cout << m << endl;

	}