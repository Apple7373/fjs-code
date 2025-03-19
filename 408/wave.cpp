#include <bits/stdc++.h>

using namespace std;

char a[100][100];
int main()
{
    memset(a, ' ', sizeof a);
    string s;
    cin >> s;
    int n;
    cin >> n;
    int flag = true; // true 从左上到右下， false 从左下到右上
    int j = 0;
    while (j < s.size()) {
        if (flag) {
            for (int i = 0; i < n && j < s.size(); i++, j++) a[i][j] = s[j];
            flag = false;
        } else if (!flag) {
            for (int i = n-2; i > 0 && j < s.size(); i--, j++) a[i][j] = s[j];
            flag = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 100;j ++)
            cout << a[i][j];
        cout << endl;
    }
}