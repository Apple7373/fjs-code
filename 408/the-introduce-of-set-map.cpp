#include <bits/stdc++.h>

using namespace std;
 // 
int main()
{
    // 直到每个stl是如何加入、删除、遍历是一个重点
    // 集合在离散数学里面无序不可重复
    // 在c++里面是有序不可重复  默认是升序  也就是说明也可以降序
    // set<int> s;  // 默认 其实这个相当于set<int,less<int>> s;

    set<int, greater<int>> s;  // 降序
    s.insert(9);
    s.insert(8);
    s.insert(10);
    s.insert(199);



    // vector<pair<int,vector<int>>> a;

    // auto就是自动判断数据类型  set遍历方式
    // for (auto i : s) {
    //     cout << i << endl;
    // }
    

    // 迭代器遍历
    // for(auto it = s.begin(); it != s.end(); it++) {
    //     cout << *it << endl;
    // }

    // map存储的是键值对  key-value
    // map<char, int, less<char>> m;  // 默认按照key值升序  map<char,int,less<char>> m
    map<char,int,greater<char>> m;
    m['d'] = 1;
    m['c'] = 4;
    m['a'] = 2;
    m['j'] = 2;

    for (auto it : m) {
        cout << it.first << ' ' << it.second << endl;
    }
    return 0;
}