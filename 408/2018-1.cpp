#include <bits/stdc++.h>

/*
1、输入一个只含有英文字母的字符串，输出最大回文子串的长度及此长度回文子串的个数（回文不区分大小写）。
样例：
输入: aBaAb(最大回文子串为BaAb)
输出: 4 1
输入: aBcbBb(最大回文子串为Bcb和bBb)
输出: 3 2
输入: a B
输出: 1 2
输入: aBcBB
输出: 3 1
输入: aaaaaa
输出: 6 1 
*/
using namespace std;

int main()
{
    // int c = 'a' - 'A';
    // cout << c << endl;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) 
        if (s[i] >= 'a') s[i] -= 32;
    
    int maxlen = 0;
    int cnt = 1;
    string ans;
    int n = s.size();
    int maxleft = 0;
    for (int i = 0; i < n; i++) {
        int left = i;
        int right = i;
        // 1、单向扩展
        while (left > 0 && s[left] == s[left-1]) left--;
        while (right < n-1 && s[right] == s[right+1]) right++;
        // 2、双向扩展
        while (left > 0 && right < n-1 && s[left-1] == s[right+1]) 
            left--, right++;
        int len = right - left + 1;
        if (len > maxlen) {
            maxlen = len;
            maxleft = left;  // 区分不同
            cnt = 1;
        } else if (len == maxlen) {
            if (left != maxleft) {
                cnt++;
                maxleft = left;
            }
        }
    }
    cout << maxlen << ' ' << cnt << endl;
    return 0;
}