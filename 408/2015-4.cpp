#include <bits/stdc++.h>

using namespace std;
// 动态规划版本
int dp[1000][1000];
int main()
{
	memset(dp, 0, sizeof dp);
	string s1 = "0", s2 = "0", s;
	cin >> s;
	s1 += s;
	cin >> s;
	s2 += s;

	int maxlen = 0;
	int cnt = 0;
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
				if (dp[i][j] == maxlen) cnt++;
				else if (dp[i][j] > maxlen) {
					cnt = 1;
					maxlen = dp[i][j];
				}
				// maxlen = max(maxlen, dp[i][j]);
		}
	}
	
	cout << maxlen << ' ' << cnt << endl;
	
}

// 纯暴力版本
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int maxlen = 0;
	int cnt = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			int p1 = i, p2 = j;
			while (p1 < s1.size() && p2 < s2.size() && s1[p1] == s2[p2]) {
				p1++, p2++;
			}
			int len = p1-i;
			if (maxlen == len) cnt++;
			else if (maxlen < len) {
				cnt = 1;
				maxlen = len;
			}
		}
	}	
	cout << maxlen << ' ' << cnt << endl;
}


