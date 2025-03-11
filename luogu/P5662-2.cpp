#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int t, n, m;
int pr[N][N], f[N*N];

int main()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pr[i][j];  // 第j个商品 第i天的价格
        }
    }

    for (int i = 1; i < t; i++) {  // 这里不能是i <= t 必须是 i < t 因为是从今天
        memset(f, 0, sizeof f);
        for (int j = 1; j <= n; j++) {
            for (int k = pr[i][j]; k <= m; k++) {
                f[k] = max(f[k], f[k-pr[i][j]] + pr[i+1][j] - pr[i][j]);
            }
        }
        m += f[m];
    }
    cout << m << endl;
    return 0;
}