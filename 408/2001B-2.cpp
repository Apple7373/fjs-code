#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long ans = 1;
    // 输入数字范围为1~20  要进行范围检查
    int n;
    cin >> n;
    if (n < 1 || n > 20) {
        cout << "输入数据不合法" << endl;
        return 0;
    }
    while (n) {
        ans *= n;
        n--;
    }
    cout << ans << endl;
    return 0;
}