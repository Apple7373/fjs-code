// 纪念品
#include <bits/stdc++.h>

using namespace std;
const int N = 110;
const int M = 1010;

int t, n, m;
int price[N][N];
int f[M];
int main()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> price[i][j];
        }
    }

    for (int i = 1; i < t; i++) { // 天数
        memset(f, 0, sizeof f);
        for (int j = 1; j <= n; j++) { // 第j个物品
            for (int k = price[i][j]; k <= m; k++) { // 第
                f[k] = max(f[k], f[k-price[i][j]] + price[i+1][j] - price[i][j]);
            }
        }
        m += f[m];
    }
    cout << m << endl;
    return 0;
}