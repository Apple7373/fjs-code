#include <bits/stdc++.h>

using namespace std;

// 判断是否是闰年
bool isLeap(int y) {
    return (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);
}

// 返回这一月的天数
int days(int y, int m) {
    switch(m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeap(y) ? 29 : 28;
    }
}

// 循环增加天数
void addDays(int& y, int& m, int& d, int add) {
    while (add > 0) {
        int allDays = days(y, m); 
        int remain = allDays - d;

        if (add <= remain) {
            d += add;
            break;
        } else {
            add -= remain+1;
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
    }
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    int add;
    cin >> add;
    addDays(y, m, d, add);
    printf("%d-%02d-%02d\n", y, m, d);
    return 0;
}