#include <bits/stdc++.h>

using namespace std;
// 说一下set 默认升序降序的方式

set<int> s1; // 出现的数字
set<int> s2; // 组别
map<pair<int,int>, int> m;

int main()
{
    
    int n;
    cin >> n;
    int num;
    vector<int> a; // 第一行
    vector<int> b; // 第二行
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
        s1.insert(num);
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
        s2.insert(num);
    }
    
    // 录入map
    for (int i = 0; i < n; i++) {
        m[make_pair(a[i], b[i])]++;
    }

    for(auto it : s2) { // 组别
        cout << it << "={";
        int num = 1;
        for (auto it2 : s1) { // 数字
            if (num != 1) cout << ',';
            num++; 
            if (m[make_pair(it2, it)] != 0) cout << it2 << '=' << m[make_pair(it2, it)];
            else cout << it2 << '=' << 0;
        }
        cout << "}" << endl;
    }
}
