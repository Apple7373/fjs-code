#include <bits/stdc++.h>
// 公交换乘 朴素版本
using namespace std;
typedef struct Node{
    int price, time;
    bool isUsed;
}node[100005];
int n;
int head = 0, tail = 0;
int ans = 0;
node a;
bool check(int price, int time) {
    int h = head, t = tail;
    while (h < t) {
        if (!a[h].isUsed && a[h].price >= price && a[h].time+45 >= time) {
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
            if (!(check(y, z))) ans += y;
        }
    }

    cout << ans << endl;
    return 0;
}