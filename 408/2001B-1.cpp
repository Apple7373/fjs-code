#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h;
    cin >> h;

    for (int i = 0; i < h; i++) {
        int num = h-i-1;
        while (num--) cout << ' ';
        num = h+ i*2;
        while (num--) cout << '*';
        cout << endl;
    }
    return 0;
}