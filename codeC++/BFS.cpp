#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    int n, m;
    cin >> n >> m;

    char a[n+1][m+1];
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m; j++) {
            for (int downi = i; downi <= n; downi++) {
                for (int downj = j; downj <= m; downj++) {
                    if ((downi-i+1)*(downj-j+1) <= ans) continue;
                    int black = 0, white = 0;
                    for (int x = i; x <= downi; x++) {
                        for (int y = j; y <= downj; y++) {
                            if (a[x][y] == '0') white++;
                            else black++;
                        }
                    }
                    if (black == white)  ans = (downi-i+1)*(downj-j+1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

