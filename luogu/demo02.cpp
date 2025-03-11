// 公交换乘 // 优化版本
#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
typedef struct{
    int price, time;
    bool isUsed;
}Node;
Node a[N];
int n, ans = 0;
int tail = 0, head = 0;

bool check(int price, int time) {
    int h = head, t = tail;
    while (h < t) {
        if (!a[h].isUsed && a[h].price >= price && a[h].time + 45 >= time) {
            a[h].isUsed = true;
            return true;
        }
        h++;
    } 
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            ans += y;
            a[tail] = {y, z, false};
            tail ++;
        } else {
            // 新的时间z进来了 排除过期的票
            while (head < tail) {
                if (a[head].isUsed || a[head].time + 45 < z) head++;
                else break;
            }
            // 判断是否有一张优惠票
            if (!(check(y, z))) ans += y;
        }
    }    
    cout << ans << endl;
    return 0;
}