#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<string> v;
	char ch;
	cin >> ch;
	int n;
	cin >> n;
	vector<char> up;
	vector<char> low;
	for (int i = 0; i < 26; i++) {
		up.push_back(i + 'A');
		low.push_back(i + 'a');
	}
	
	if (isalpha(ch) == 1) {
		int idx = ch - 'A';
		
		for (int i = 0; i < n-1; i++) {
			string cur;
			cout << string(i, ' ');
			cur += string(i, ' ');

			cout << up[(idx+n-i-1)%26];
			cur += up[(idx+n-i-1)%26];

			cout << string((n-i-1)*2-1, ' ');
			cur += string((n-i-1)*2-1, ' ');

			cout << up[(idx+n-i-1)%26];
			cur += up[(idx+n-i-1)%26];

			cout << endl;
			v.push_back(cur);
		}
		cout << string(n-1,' ');
		cout << up[idx] << endl;

		for (int i = v.size()-1; i >= 0; i--) {
			cout << v[i] << endl;
		}
	} else if (isalpha(ch) == 2) {
		int idx = ch - 'a';
		
		for (int i = 0; i < n-1; i++) {
			string cur;
			cout << string(i, ' ');
			cur += string(i, ' ');

			cout << low[(idx+n-i-1)%26];
			cur += low[(idx+n-i-1)%26];

			cout << string((n-i-1)*2-1, ' ');
			cur += string((n-i-1)*2-1, ' ');

			cout << low[(idx+n-i-1)%26];
			cur += low[(idx+n-i-1)%26];

			cout << endl;
			v.push_back(cur);
		}
		cout << string(n-1,' ');
		cout << low[idx] << endl;

		for (int i = v.size()-1; i >= 0; i--) {
			cout << v[i] << endl;
		}
	} else {
		cout << "input error" << endl;
	}
	return 0;
}