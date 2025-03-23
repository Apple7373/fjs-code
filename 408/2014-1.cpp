/*
1、系统中有最近打开文件的记录，现用整数表示打开的文件名，且只
显示最近3个打开的文件，输出文件序列.
示例:
输入:1输出:1
输入:2输出:2, 1
输入:3
输出:3, 2, 1
输入:4
输出:4,3,2
输入:1
输出:1,4,3
输入:4
输出:1,4, 3
输入:3
输出:1,4,3
*/

#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
int main()
{
    cout << "请输入：";
    int a;
    while (cin >> a) {
        int flag = false; // 当前输入不在最近访问列表
        for (int i = ans.size()-1, cnt = 0; i >= 0 && cnt < 3; i--, cnt++) {
            if (ans[i] == a) {
                flag = true;
                break;
            }
        }
        if (!flag) ans.push_back(a);
        
        for (int i = ans.size()-1, cnt = 0; i >= 0 && cnt < 3; i--, cnt++) {
            cout << ans[i];
            if (i != 0) cout << ',';
        }
        cout << endl;
        cout << "请输入：";
    }
    return 0;
}