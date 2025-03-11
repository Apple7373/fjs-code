#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;
    cin >> ch;
    if (ch > 'a' && ch < 'z' || ch > 'A' && ch < 'Z') {
        vector<char> v;
        if (ch > 'a' && ch < 'z') {
            for (char cur = 'a'; cur <= ch; cur++) v.push_back(cur);
            for (int i = v.size()-2; i >= 0; i-=2) v[i] -= 32;
            for (int i = v.size()-2; i >= 0; i--) v.push_back(v[i]);
        } else if (ch > 'A' && ch < 'Z') {
            for (char cur = 'A'; cur <= ch; cur++) v.push_back(cur);
            for (int i = v.size()-2; i >= 0; i-=2) v[i] += 32;
            for (int i = v.size()-2; i >= 0; i--) v.push_back(v[i]);
        }
        for (auto it : v) cout << it;
        cout << endl;
    } else cout << "input error" << endl;
    return 0;
    

}