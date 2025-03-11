#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int f[N][N];
int v[N], w[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {  // 考虑前i个物品
        for (int j = 0; j <= m; j++) {  // 容量为j时
            // f[i][j] = f[i-1][j];        // 更新  什么时候更新的
            for(int k = 0; k*v[i] <= j; k++)
                f[i][j] = max(f[i-1][j], f[i-1][j-v[i]*k] + w[i]*k);
        }
    }

    cout << f[n][m] << endl;
    return 0;
}