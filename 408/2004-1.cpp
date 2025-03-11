#include <bits/stdc++.h>

using namespace std;

class Angle{
    private:
        double ang;
    public:
        Angle(double ang): ang(ang) {}
        double getAngle() {     // 得到弧度
            return ang/180 * M_PI;
        }

        double getSin() {
            return sin(getAngle());
        }

        Angle operator- (Angle cur) {
            return Angle(this->ang - cur.ang);
        }
};

int main()
{
    Angle a1(30);
    Angle a2(60);
    cout << a1.getSin() << endl;
    Angle a3 = a2 - a1;
    cout << a2.getSin() << endl;
}