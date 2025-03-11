#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int price, time;
    bool isUsed;
}Node;
Node d[100010];
int cnt = 0;
int n, ans = 0;
int main() 
{   
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            // 是地铁票
            ans += b;
            d[cnt] = {b, c, false};   // 问题出在这里
            cnt++;
        } else {
            // 是公交
            int flag = 0;
            for (int k = 0; k < cnt; k++) {
                if (!d[k].isUsed && d[k].price >= b && d[k].time + 45 >= c) {
                    d[k].isUsed = true;
                    flag = 1; // 表示已经找到优惠票
                    break;
                }
            }
            if (flag == 0) ans += b;
        }
    }
    cout << ans << endl;
}