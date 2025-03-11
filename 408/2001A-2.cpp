#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    if (n >= 0) 
        for (int i = n; i <= 2*n; i++) sum += i;
    else 
        for (int i = 2*n; i <= n; i++) sum += i;
    
    cout << sum << endl;
    return 0;
}