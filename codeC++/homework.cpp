#include <bits/stdc++.h>
using namespace std;

/*
d(query, Micky) = 10 = t1;
d(query, Goofy) = 55 = t2;
d(query, Minnie) = 70 = t3;

d(Micky, Goofy) = 60 = x;
d(Micky, Minnie) = 60 = y;
d(Goofy, Minnie) = 119 = z;
Micky 1号，Goofy 2号， Minnie 3号
*/ 
int dis_Approximate[4] = {0,10,55,70};
int dis_real[4][4];
string name[4] = {"", "Micky", "Goofy", "Minnie"};
int main()
{
    // 手动初始化真实距离
    dis_real[1][2] = dis_real[2][1] = 60;
    dis_real[1][3] = dis_real[3][1] = 60;
    dis_real[2][3] = dis_real[3][2] = 119;
    int cur;
    cout << "请选择支撑点：1、Micky 2、Goofy 3、Minnie：";
    cin >> cur;
    cout << "支撑点" << name[cur] << "与query之间的预估距离是：" << dis_Approximate[cur] << endl;
    int cnt = 1; // 表示计算次数
    for (int i = 1; i < 4; i++) {
        // 选择点
        if (i == cur) continue;
        // 计算i与query之间的最小距离
        int mindis = abs(dis_Approximate[cur] - dis_real[cur][i]);
        int maxdis = abs(dis_Approximate[cur] + dis_real[cur][i]);
        cout << "搜索" << name[i] << ":" << endl; 
        cout << "query与" << name[i] << "之间的距离满足：" << mindis << " <= dis(query," << name[i] << ") <= " << maxdis << endl;
        if (mindis >= dis_Approximate[cur]) {
            cout << "因为min(dis(query," << name[i] << ")) > " << dis_Approximate[cur] <<", 所以该对象可以排除。" << endl;  
        } else {
            cout << "因为min(dis(query," << name[i] << ")) < " << dis_Approximate[cur] <<", 该对象不可以排除，需要计算距离。" << endl;
            cnt++;  
        }
    }
    cout << "支撑点选择" << name[cur] << ", 总计算次数为：" << cnt << "次。" << endl;
    return 0;
}

