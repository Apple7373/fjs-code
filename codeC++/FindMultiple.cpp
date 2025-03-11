#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int curN;
        cin >> curN;
        int max = 0;
        bool flag = 1;
        for (int i = 0; i < curN; i++) {
            int a;
            cin >> a;
            if (max < a) {
                if (max != 0 && a % max != 0) {
                    flag = 0;
                }
                max = a;
            } else {
                if (max % a != 0) {
                    flag = 0;
                } 
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}