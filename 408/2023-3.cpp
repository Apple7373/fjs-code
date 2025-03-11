#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
void dfs(int n) {
    cnt++;
    cout << n << ' ';
    if (n == 1) return;
    else if (n%2==1) dfs(n*3+1);
    else if (n%2==0) dfs(n/2);
}

int main()
{
    int n;
    cin >> n;
    dfs(n);
    cout << cnt << endl;
}