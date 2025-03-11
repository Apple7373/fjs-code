#include <bits/stdc++.h>

using namespace std;


map<string, int> m;

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
int main()
{
    // string s = "ghjkd";
    // string cur = s.substr(0, 2);
    // cout << cur << endl;


    string line;
    getline(cin, line);

    int beg = 0;
    int end = 0;
    while (end <= line.size()) {
        if (end == line.size()) {
            m[line.substr(beg, end - beg)]++;
            break;
        }
        if (line[end] == ' ') {
            m[line.substr(beg, end-beg)]++;
            beg = end+1;
            // end++;
        } else if (line[end] == ',' || line[end] == '.') {
            m[line.substr(beg, end-beg)]++;
            m[line.substr(end,1)]++;
            // end++;
            beg = end+2;
            end++;
        }
        end++;
    }
    vector<pair<string,int>> v(m.begin(),m.end());

    sort(v.begin(), v.end(), cmp);
    for (auto it : v) {
        cout << it.first << ' ' << it.second << endl;
    }
    
}