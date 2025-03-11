#include <bits/stdc++.h>

using namespace std;
vector<char> v;

int main()
{
    string s;
    cin >> s;
    if (s.size() > 20) {
        cout << "长度超过限度" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i]);
    }    
    sort(v.begin(), v.end());

    for (auto it : v) 
        cout << it << ' ';
    cout << endl;
    return 0;

}