#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n+10];
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    long long m = a[n] % 2147483648;

    // 质因数分解
    cout << m << "=";
    for (int i = 2; i <= m; i++) {
        if (m % i == 0) {
            cout << i;
            m /= i;
            if (m != 1) cout << "*";
            i--;
        }
    }
    cout << endl;
}