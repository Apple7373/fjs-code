#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>,bool>> v;
int head=0, tail=0;
int n, ans = 0;

bool check(int price, int time) {
    for (int i = head; i < tail; i++) {
        if (v[i].first.first >= price && v[i].first.second >= time && !v[i].second) {
            v[i].second = true;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>n;
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            ans += b;
            v.push_back({{b, c + 45}, false});
            tail++;
        } else {
            while (head < tail) {
                if (v[head].first.second < c || v[head].second) head++;
                else break;
            }
            if (!check(b,c)) ans += b;
        }
    }
    cout << ans << endl;
}