#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> e;
    vector<int> g;
    for (int i = 2; i < 61; i++) {
        int sum = 0;
        for (int j = 1; j <= i/2; j++) {
            if (i % j == 0) sum += j;
        }
        if (sum == i) e.push_back(i);
        else if (sum > i) g.push_back(i);
    }
// sdfafasdfsadfsf
// asdfjsadfasjfasdfasdfkls
    cout << "E:";
    for (auto it : e) {
        cout << it << ' ';
    }
    cout << endl;
    cout << "G:";
    for(auto it : g) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}