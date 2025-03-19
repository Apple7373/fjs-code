#include <bits/stdc++.h>

using namespace std;

int main()
{
	int maxlen = 0;
	vector<char> ans;
	int beg = 0, i;
	string s;
	cin >> s;
	for (i = 1; i < s.size(); i++) {
		if (s[i] != s[i-1]) {
			int len = i-beg;
			
			if (len == maxlen) ans.push_back(s[beg]);
			else if (len > maxlen) {
				ans.clear();
				ans.push_back(s[beg]);
				maxlen = len;
			}
			beg = i;
		}
	}
	
	int len = i - beg;
	if (len == maxlen) ans.push_back(s[beg]);
	else if (len > maxlen) {
		ans.clear();
		ans.push_back(s[beg]);
		maxlen = len;
	}

	cout << maxlen << ' ';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}