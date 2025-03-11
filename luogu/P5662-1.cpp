#include <bits/stdc++.h>

using namespace std;

const int N = 101;
int n, m, t, price[N][N], f[N*N];

int main()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> price[j][i];  // 第j个物品 第i天的价格
        }
    }

    for (int k = 1; k < t; k++) {   // 是天数
        memset(f, 0, sizeof f); // f不包含成本
        for (int i = 1; i <= n; i++) {
            for (int j = price[i][k]; j <= m; j++) {  // 同一间物品 能买几个 不是这个意思， 关键在于f[j-price[i][k]] 每次j++ 这个值都是会变的
                f[j] = max(f[j], f[j-price[i][k]] + price[i][k+1] - price[i][k]);
            }
        }
        m += f[m];
    }
    cout << m << endl;
}