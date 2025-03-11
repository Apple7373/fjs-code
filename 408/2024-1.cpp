#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 20 || n < 0) {
        cout << "input error" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << string(n-1-i, ' ');
        if (i == 0) cout << string(n,'*') << endl;
        else if (i == n-1) cout << string(3*n-2, '*') << endl;
        else {
            cout << '*';
            cout << string(n+(i-1)*2, ' ');
            cout << '*';
            cout << endl;
        }
    }
    return 0;
}