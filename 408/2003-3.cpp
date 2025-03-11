#include <bits/stdc++.h>

using namespace std;

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    int ans = 0;
    switch(m-1) {
        case 12: ans += 31;  
        case 11: ans += 30;
        case 10: ans += 31;
        case 9:  ans += 30;
        case 8:  ans += 31;
        case 7:  ans += 31;
        case 6:  ans += 30;
        case 5:  ans += 31;
        case 4:  ans += 30;
        case 3:  ans += 31;
        case 2:  ans += 28;
        case 1:  ans += 31;
    }
    ans += d;

    // 判断是否是闰年 月份是否大于2
    if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) 
        if (m > 2) ans += 1;
    cout << ans << endl;

}   