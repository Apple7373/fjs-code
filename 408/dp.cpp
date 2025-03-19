#include <bits/stdc++.h>

using namespace std;

char a[100];
char b[100];

int dp[100][100];
int main()
{
    int m, n;
    cin >> m >> n;
    scanf("%s",a+1);
    scanf("%s",b+1);

    int ma = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;  // 这里原本写 dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1)  但是可以不这么写，原因可讲
                ma = max(ma, dp[i][j]);
            }
                
        }
    }
    cout << ma << endl;
}