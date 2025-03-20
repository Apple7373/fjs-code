#include <bits/stdc++.h>
/*
定义移位操作，shift(str,x)代表将str中的前x位移到后面，例如shift("ABCD",2)得到CDAB。
输入一个长度为n的字符串最多进行n次移位操作后，输出有几次得到的字符串与原字符串相同。
输入:
byebye
hello
输出
2
1 
*/
using namespace std;


int shift(string s) {
    int ans = 0;
    for (int i = 1; i <= s.size(); i++) {
        string cur = s.substr(i, s.size()-i);
        cur += s.substr(0, i);
        cout << cur << endl;
        if (cur == s) ans++;
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int ans = shift(s);
    cout << ans << endl;


}
