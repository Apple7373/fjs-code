#include <bits/stdc++.h>

using namespace std;
/*
    递归函数，典型例子是求斐波那契数列

int fib(int n) {
    if (n == 1 || n == 2) return 1;
    return fib(n-1) + fib(n-2);
}
int main() 
{
    cout << fib(2) << endl;
    return 0;
}
*/

int f(int i, int j) {
    if (j == 0 || i == j) return 1;
    else return f(i-1, j) + f(i-1, j-1);
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // 输出空格
        int num = n-i-1;
        while (num--) cout << ' ';
        // 输出结果
        for (int j = 0; j <= i; j++) {
            cout << f(i,j) << ' ';
        }
        cout << endl;
    }
}