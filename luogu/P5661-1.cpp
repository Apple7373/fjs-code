#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> t;
vector<bool> st;


bool check(int price, int time) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i].first >= price && t[i].second >= time && !st[i]) {
            st[i] = true;
            return true;
        }
    }
    return false;
}
int main() 
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            t.push_back({b, c+45});
            ans += b;
            st.push_back(false);
        }
        else if (!check(b, c)) ans += b; 
    }
    cout << ans << endl;
    return 0;
}