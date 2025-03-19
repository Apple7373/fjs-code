#include <bits/stdc++.h>

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