#include <bits/stdc++.h>

using namespace std;

int a[100][100];
vector<int> nums;
int main()
{
    int n;
    cin >> n;

    while (n > 0) {
        nums.push_back(n%7);
        n /= 7;
    }
    int ans = 0;
    for (int i = nums.size()-1; i >= 0; i--) {
        ans = ans * 10 + nums[i];
    }
    cout << ans << endl;
    return 0;
}