#include <bits/stdc++.h>

using namespace std;


// 1、先筛出2-50的质数 
// 2、将一个偶数分解成两个质数之和
// 3、输出 ----

vector<int> odd; // 质数  
map<int,int> m; // m[3] = 1; m[47] = 1;  m[100] = 0
map<int, vector<vector<int>>> bac;  

vector<vector<int>> fun(int x) {
    vector<vector<int>> ans;
    for (int i = 0; i < odd.size() && odd[i] <= x/2; i++) {
        if (m[x-odd[i]] == 1) ans.push_back({odd[i], x-odd[i]});
    }
    return ans;
}
                                    // 6 {3,3}
vector<vector<int>> backtrack() {   // 10 {3,7}  {5,5}
    vector<vector<int>> ans;
    for (auto i : bac) {
        vector<vector<int>> temp;
        if (ans.size() == 0) {
            // cout << "*****";
            for (auto j : i.second) {
                temp.push_back(j);
            }
        }
        else {
            for(auto k : ans) {
                for (auto  t: i.second) {
                    auto cur = k;
                    cur.push_back(t[0]);
                    cur.push_back(t[1]);
                    // cout << "----";
                    temp.push_back(cur);
                }
            }
        }
        ans = temp;
    }
    return ans;
}

bool cmp(pair<int,int> a,pair<int,int> b) {
    if (a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}
int main()
{
    vector<bool> cur(51, true);
    for (int i = 2; i < 51; i++) {
        for (int j = 2; j *i < 51; j++) {
            cur[i*j] = false;
        }
    }
    for (int i = 2; i < 51; i++) {
        if(cur[i]) {
            odd.push_back(i);
            m[i]++;
        }
    }
    // for (auto it : m) {
    //     cout << it.first << ' ';
    // }

    // for (int i : odd) {
    //     cout << i << ' ';
    // }

    // 2、将一个偶数分解成两个质数之和
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (i % 2 == 0) {
            bac[i] = fun(i);  // bac[10] = {{3,7}, {5,5}}
        }
    }

    for (auto it : bac) {
        cout << it.first << endl;
        for (auto j : it.second) {
            for (auto k : j) {
                cout << k << ' ';
            }
            cout << endl;
        }
    }

    
    // cout << "0---------------";
    vector<vector<int>> ans = backtrack();
    map<int,int> curm;
    for (auto it : ans) {
        for (auto j : it) {
            curm[j]++;
        }
        vector<pair<int,int>> cur;
        for (auto j : curm) {
            cur.push_back({j.first, j.second});
        }

        curm.clear();  // 清空

        sort(cur.begin(), cur.end(), cmp);
        for (auto it : cur) {
            cout << it.first << ' ' << it.second << ' ';
        }
        cout << endl;
    }

    return 0;
}