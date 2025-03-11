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
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i-1][j-v[i]] + w[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w[i]);  // 并没有更新f[i][0~j-1]
        }
    }
    // int ans = 0;
    // for (int i = 1; i <= m; i++) ans = max(f[n][i], ans);    
    // cout << ans << endl;

    cout << f[n][m] << endl;
    return 0;
}