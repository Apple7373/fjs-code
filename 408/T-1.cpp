#include<bits/stdc++.h>
using namespace std;
/*
题目：
输入一行数字，每个数字用空格隔开，输入数组的每位数值代表从数组当前位置可以向后跳的最大步数，从数组的第一个数字开始向后跳，
如果可以跳到数组的最后一个位置，则输出数组跳跃的一条路径，否则输出None。    
Example1 输入：
1 2 4 4 2
Example1 输出：
1 2 4 5
或
1 2 3 4 5
或
1 2 3 5 

进阶：这个题目只需要输出一条满足要求的路径（前提是路径存在），如果要输出所有合理的路径应该怎么做呢？

*/
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
