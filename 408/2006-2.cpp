#include <bits/stdc++.h>

using namespace std;

int fun(int cur) {
    int ans = 0;
    while (cur) {
        ans *= 10;
        ans += cur%10;
        cur /= 10;
    }
    return ans;
}

int main()
{
    int cur;
    vector<pair<int,int> > v;
    int num = 0;
    while (cin >> cur) {
        if (cur == 0) break;
        int x = fun(cur);
        v.push_back(make_pair(cur, x));
        if (++num == 10) break;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
}