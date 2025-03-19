#include <bits/stdc++.h>

using namespace std;

int a[100][100];
int main()
{
    int n;
    cin >> n;
    int ceng = 0;
    int num = 1;
    int mm = n*n;
    while (num < mm) {
        // 1
        for (int j = ceng; j < n-1-ceng && num <= mm; j++) a[ceng][j] = num++;
        // 2
        for (int i = ceng; i < n-1-ceng && num <= mm; i++) a[i][n-1-ceng] = num++;
        // 3
        for (int j = n-1-ceng; j > ceng && num <= mm; j--) a[n-1-ceng][j] = num++;
        // 4
        for (int i = n-1-ceng; i > ceng && num <= mm; i--) a[i][ceng] = num++;
        ceng++;
    }
    if (n%2==1) a[n/2][n/2] = num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << '\t';   
        cout << endl;
    }
    return 0;
}