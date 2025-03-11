#include<bits/stdc++.h>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    vector<bool> v(n+1);
    for (int i = 1; i <= n; i++) v[i] = false;

    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < n; ) {
        if (!v[++idx%n]) {
            if (++cnt % 3 == 0) {
                cout << idx%n  << ' ';
                v[idx%n] = true;
                i++;
            }
        }
        // cnt ++;
    }
}
// 1 2 3 4 5







// int main()
// {
//     vector<pair<int,bool>> v;
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         v.push_back(make_pair(i+1, false));
//     }

//     int cnt = 0;
//     int idx = 0;
//     for (int i = 0; i < n; ) {
//         if (!v[idx%n].second) {
//             if (++cnt % 3 == 0) { 
//                 v[idx%n].second = true;  
//                 cout << v[idx%n].first << ' ';  
//                 i++; 
//             }
//         }
//         idx ++;
//     }
// }