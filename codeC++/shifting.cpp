#include <bits/stdc++.h>

using namespace std;

int main()
{
    int offset;
    cin >>offset;
    int n = 26;
    char ch[26];
    for (int i = 0; i < 26; i++) {
        ch[i] = 'A' + i;
    }
    while (n--) {
        cout << ch[offset % 26];
        offset++;
    }
    return 0;
}