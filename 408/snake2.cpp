#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int flag = true;
    for (int k = 0; k < n; k++) {
        if (!flag) {  // false 从右上到左下
            for (int i = 0, j = k; i <= k; i++, j--) a[i][j] = ++cnt;
            flag = true;
        }
        else if (flag) { // true 从左下到右上
            for (int j = 0, i = k; j <= k; j++, i--) a[i][j] = ++cnt;
            flag = false;
        }
    }

    int beg = 1;
    for (int k = n; k < 2*n-1; k++) {
        if (flag) {
            for (int j = beg, i = k-j; j < n; j++, i--) a[i][j] = ++cnt;
            flag = false;
        } else if (!flag) {
            for (int i = beg, j = k-i; i < n; i++,j--) a[i][j] = ++cnt;
            flag = true;
        }
        beg++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}