#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;
int main()
{
    cin >> s1 >> s2 >> s3;
    int n1 = 0, n2 = 0;
    for (int idx = 0; idx < s3.size(); ) {
        // 先用s1尝试
        bool flag = true;
        int j = 0, i = idx;
        while (j < s1.size()) {
            if (s1[j] == s3[i]) {
                j++, i++;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            n1++;
            idx = i;
        }
        else {
            flag = true;
            // 用s2尝试
            int j = 0, i = idx;
            while (j < s2.size()) {
                if (s2[j] == s3[i]) {
                    j++, i++;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                n2++;
                idx = i;
            }
            else {
                cout << "false" << endl;
                return 0;
            }
        }
    }
    cout << n1 << ' ' << n2 << endl;
}