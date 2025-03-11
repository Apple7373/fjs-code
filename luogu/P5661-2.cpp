#include <bits/stdc++.h>

using namespace std;

deque<pair<int,int>> q;
stack<pair<int,int>> s;
// vector<bool> st;

void reback() {
    while (!s.empty()) {
        q.push_front(s.top());
        s.pop();
    }
}
bool check(int price, int time) {
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop_front();
        if (p.first >= price && p.second >= time) {
            reback();
            return true;
        }
        s.push(p);
    }
    reback();
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
            q.push_back({b, c+45});
            ans += b;
        }
        else if (!check(b, c)) ans += b; 
    }
    cout << ans << endl;
    return 0;
}