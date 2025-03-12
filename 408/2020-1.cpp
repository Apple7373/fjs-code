#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int main()
{
    int m, n;
    cin >> m >> n;

    int num = 0; // 记录白纸数量
    // 循环结束条件是白纸为0，或者当前循环白纸数量和上一次循环白纸数量相同
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) num++;
        }
    }
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool flag = true;
    int cnt = 0; // 表示循环次数
    
    while (num > 0) {
        int curnum = num;
        cnt++;
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                if (a[i][j] == 2) q.push({i,j});
        while (q.size() > 0) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                if (x >= 0 && x < m && y >= 0 && y < n && a[x][y] == 1) {
                    a[x][y] = 2;
                    num--;
                }
            }
        }
        if (curnum == num) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << cnt << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}