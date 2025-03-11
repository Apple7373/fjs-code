#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    switch(m) {
        case 12:
        case 10:
        case 8:
        case 7:
        case 5:
        case 3:
        case 1:
            if (++d > 31) {
                m++;
                d = 1;
            }
            if (m > 12) {
                y++;
                m = 1;
            }
            break;
        case 11:
        case 9:
        case 6:
        case 4:
            ++d;
            if (d > 30) {
                m++;
                d++;
            }
        case 2:
            ++d;
            if (y%400==0 || y%4==0 && y%100!=0) {
                if (d > 29) {
                    m++;
                    d=1;
                }
            }
            else if (d > 28) {
                m++;
                d=1;
            }
    }
    cout << y << ' ' << m << ' ' << d;
}