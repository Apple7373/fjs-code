#include <iostream>

using namespace std;

int main()
{ 
    int n, m;
    cin >> n >> m;
    char a[n+10][m+10];
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }
    int ans = 0; // 存储结果
    // 左上点的坐标用i、 j表示
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 右下角坐标 di dj
            for (int di = i; di < n; di++) {
                for (int dj = j; dj < m; dj++) {
                    // 接下来就遍历子矩形内的点
                    int black=0, white=0;
                    for (int x = i; x <= di; x++) {
                        for (int y = j; y <= dj; y++) {
                            if (a[x][y] == '0') white++;
                            else black++;
                        }
                    }
                    // 走到这 说明遍历完一个子矩形
                    if (black == white) { // 说明就是一个平衡矩形
                        if(black + white > ans) ans = black + white;
                        // ans = max(ans, black + white);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    
}
