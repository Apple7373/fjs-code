#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    int n, k;
    cin >> n >> k;
    int pri[n];
    for (int i = 0; i < n; i++) cin >> pri[i];
    sort(pri, pri + n);
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (i != n-1 && pri[i] == pri[i+1]) continue;
        int cur = 0;
        cur += pri[i];
        for (int j = i-1; j >= 0; j--) {
            if (abs(pri[j]-pri[i]) > k) break;
            cur += pri[j];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

