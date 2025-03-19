#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	vector<int> nums;
	nums.push_back(0);
	while (cin >> a) {
		nums.push_back(a);
		if (getchar() == '\n') break;
	}
	int n = nums.size()-1;
	// idx:1~n
	vector<int> v[n+10];
	for (int i = 1; i < n; i++) {
		// pass
		if (i != 1 && v[i].size() == 0) {
			cout << "None" << endl;
			return 0;
		}
		for (int j = 1; j <= nums[i] && i+j <= n; j++) {
			v[i+j].push_back(i);
		}
	}
	
	if (v[n].size() == 0) {
		cout << "None" << endl;
		return 0;
	}
	vector<int> ans;
	ans.push_back(n);
	ans.push_back(v[n][0]);
	while (ans.back() != 1) {
		ans.push_back(v[ans.back()][0]);
	}
	
	for (int i = ans.size()-1; i >= 0; i--)
		cout << ans[i] << ' ';
	cout << endl;
}