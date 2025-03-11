#include <bits/stdc++.h>

using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() 
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < 2*n-1; i++) 
        v.push_back(fib(i));

    for (int i = 0; i < n; i++) {
        // 输出空格
        int num = n-i-1;
        while (num--) cout << ' ';
        for (int j = 0; j < 2*i+1; j++)
            cout << v[j] << ' ';
        cout << endl;
    }
    return 0;
}