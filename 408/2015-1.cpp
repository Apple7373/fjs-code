#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; 
	cin >> n;
	vector<string> ans;
	// 输出第一行
	cout << string(n, '*') << endl;
	ans.push_back(string(n, '*')); 
	
	int h = n/2;
	for (int i = 0; i < h; i++) {
		string s;
		cout << string(h-i, '*');
		s += string(h-i, '*');
		cout << string(2*i+1, ' ');
		s += string(2*i+1, ' ');
		cout << string(h-i,'*');
		s += string(h-i,'*');
		ans.push_back(s);
		cout << endl;
	}
	for (int i = ans.size()-2; i>=0; i--) {
		cout << ans[i] << endl;
	}
	
}

if (a[mid] < n) {
	left = mid + 1;
} else if (a[mid] > n) {
	
}
