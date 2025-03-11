#include <bits/stdc++.h>

using namespace std;

class C {
    private:
        double a, b, c;
    public:
        C(double a, double b, double c):a(a), b(b), c(c) {}

        void getAns() {
            // 先判断跟的个数
            double ch = b*b-4*a*c;
            if (ch < 0) cout << "方程无解" << endl;
            else if (ch == 0) {
                cout << "方程有一个根, 为x = " << -b / (2*a) << endl; 
            } else {
                double x1 = (-b+sqrt(b*b-4*a*c)) / (2*a);
                double x2 = (-b-sqrt(b*b-4*a*c)) / (2*a);
                cout << "方程有两个根, 为x1 = " << x1 << ", x2 = " << x2 << endl; 
            }
        }
};   

int main()
{
    double a, b, c;
    cout << "输入系数：";
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "a系数不能为0" << endl;
        return 0;
    }
    C c1 (a, b, c);
    c1.getAns();
    return 0;  
}