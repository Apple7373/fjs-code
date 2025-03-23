#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];
int n;
int main()
{    
    int n;
    cin >> n;
    int cnt = 1;
    // 先填充前n斜线 
    bool flag = true; // true表示左下到右上  false 表示右上到左下
    for (int k = 0; k < n; k++) {
        if (flag) {
            for (int i = k, j = 0; i >= 0; i--,j++) a[i][j] = cnt++;
            flag = false;
        } else {
            for (int i = 0, j = k; i <= k; i++, j--) a[i][j] = cnt++;
            flag = true;
        }
    }

    // 接下来输出下三角
    for (int k = n; k < 2*n-1; k++) {
        if (flag) {
            for (int i = n-1, j = k-i; j <= n-1; i--, j++) a[i][j] = cnt++;
            flag = false;    
        } else {
            for (int j = n-1, i = k-j; i <= n-1; i++, j--) a[i][j] = cnt++;
            flag = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    return 0;
}