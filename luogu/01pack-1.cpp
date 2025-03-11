#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int f[N];
int v[N], w[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j], f[j-v] + w);
        }
    } 
    cout << f[m] << endl;
}