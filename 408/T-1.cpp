#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> nums;
	nums.push_back(0);
	int a;
	while (cin >> a) {
		nums.push_back(a);
		if (getchar() == '\n') break;
	}
	int n = nums.size()-1;
	// idx: 1~n 
	vector<int> v[n+5];
	
	// 往篮子里面加数
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < nums[i] && i+j+1 <= n; j++) {
			v[i+j+1].push_back(i);
		}
	}
	// 判断是否为None

	// 从篮子中找一个合理的路径
	vector<int> ans;
	ans.push_back(n); // 加入终点
	while (ans.back() != 1) {
		// 篮子下标 ans.back();
		if (v[ans.back()].size() == 0) {
			cout << "None" << endl;
			return 0;
		}
		ans.push_back(v[ans.back()][0]);
	}

	for (int i = ans.size()-1; i >= 0; i--)	
		cout << ans[i] << ' ';
	
		
	return 0;
}