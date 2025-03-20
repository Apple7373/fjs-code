#include <bits/stdc++.h>
/*
这道题就是2020-1  墨滴扩散

*/
using namespace std;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int main()
{
    int m, n;
    cin >> m >> n;

    int a[m+10][n+10];
    int num = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) num++;
        }
    }    
    int ans = 0; // 时间
    while (num > 0) {
        ans++;
        int curn = num;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 2)
                    q.push({i, j});
        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && a[x][y] == 1) {
                    num--;
                    a[x][y] = 2;
                }
            }
        }
        if (curn == num) {
            cout << "false" << endl;
            return 0;
        }
    }
    
    cout << ans << endl;



}
