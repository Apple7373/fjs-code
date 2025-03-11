#include <bits/stdc++.h>

using namespace std;

int main()
{
    double h;
    int n;
    cin >> h >> n;
    double ans = 0;
    ans += h;
    n--;
    h /= 2;
    while (n--) {
        ans += 2*h;
        h /= 2;
    }
    cout << ans << endl;

}
// 4  2*2 1*2 0.5*2 0.25*2   