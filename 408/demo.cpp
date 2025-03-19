#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	stack<char> st;
	bool flag = true;
	vector<char> ans;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')' || 
			s[i] == '+' || s[i] == '-' || s[i] == ' ' || s[i] >= '0' && s[i] <= '9') {
				if (s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']' || s[i] == '(' || s[i] == ')') ans.push_back(s[i]); // 加入到结果集
			} else {
				cout << "input error" << endl;
				return 0;
			}
	}

	for (int i = 0; i < s.size(); i++) {
		// cout << '*';
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') st.push(s[i]);
		else if (s[i] == '}') {
			if (st.size() > 0 && st.top() == '{') st.pop();
			else {
				flag = false;
				break;
			}
		} else if (s[i] == ']') {
			if (st.size() > 0 && st.top() == '[') st.pop();
			else {
				flag = false;
				break;
			}
		} else if (s[i] == ')') {
			if (st.size() > 0 && st.top() == '(') st.pop();
			else {
				flag = false;
				break;
			}
		}		
	}

	if(flag) {
		cout << "yes" <<' ';
	} else cout << "no" << ' ';
	for (auto it : ans) 
		cout << it;

	return 0;

}