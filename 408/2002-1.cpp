#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main() 
{
    for(int i = 0; i <= 5; i++) { // 要从0开始
        for(int j = 0; j <= 4; j++) {
            for (int k = 0; k <= 6; k++) {
                s.insert(8*i + 10*j + 18*k);
            }
        }
    }
    s.erase(0);   // 删除0
    cout << s.size() << endl;
    for (auto it : s) {
        cout << it << ' ';
    }
    return 0;
}