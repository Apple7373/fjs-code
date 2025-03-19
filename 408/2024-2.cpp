#include <bits/stdc++.h>

using namespace std;

int main()
{
	// ch  先输出a~ch  abcde   
	char ch;
	cin >>ch;
	if (isalpha(ch) == 0) {
		cout << "input error" << endl;
		return 0;
	}
	vector<char> ans;
	for (char i = 'a'; i <= ch; i++) {
		ans.push_back(i);
	}  

	for (int i = ans.size()-2; i>=0; i-=2) 
	{
		// isalpha(ch)  大写 返回1  小写 返回2，非字母返回0
		if (ch >= 'a' && ch <= 'z') 
			ans[i] -= 32;
		else ans[i] == 32;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	for (int i = ans.size()-2; i>=0; i--)
		cout << ans[i];
	// 

}