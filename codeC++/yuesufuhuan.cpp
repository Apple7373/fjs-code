#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;                     

                          
int main()  // 主函数
{
    int n, num = 0, cnt = 0;   // 1  2  3  4  5
    cin >> n;
    int a[n];
    bool st[n];
    memset(st, false, sizeof st);
    for (int i = 0; i < n; i++) a[i] = i;
    bool flag = 0;
    int ans = 0;
    while (num < n) {   
        if (st[cnt%n]) {
            cnt++;
            continue;
        }
        if (flag) {
            st[cnt%n] = true;
            num++;   // 表示出去的人数
            ans = cnt % n;
        }   
        cnt++; // 表示下标
        flag = !flag;
    }
    cout << ans << endl;

}

// 方案二
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[100];
    int st[100];
    for (int i = 0; i < n; i++) {
        a[i] = i;
        st[i] = 0;
    }

    int num = 0; // 表示出拳的人数
    int cnt = 0; // 表示下标
    bool flag = 1; // 0 1 0 1
    int ans;
    while (num < n) {
        flag = !flag;  // 变一下
        while (st[cnt%n]) cnt++;  // 找未被选位置
        if (flag) {
            num++;
            st[cnt%n] = true;
            ans = cnt%n;
        }
        cnt++;
    }
    cout << ans << endl;
}