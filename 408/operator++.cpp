#include <bits/stdc++.h>

using namespace std;

class Complex{
    private:
        double a, b;
    public:
        Complex() {}
        Complex(double a = 0, double b = 0): a(a), b(b) {}

        // 前置++ 
        Complex& operator ++() {
            ++a;
            ++b;
            return *this;
        }
        
        // 后置++ 用int区分       // 函数重载/重写
        Complex operator ++(int) {
            Complex temp(*this);
            ++a, ++b;
            return temp;
        }
        Complex operator -(Complex c) const;
        void display();
};

Complex Complex::operator-(Complex c) const {
	// this->a = 5.0;  // const 表示这是一个常成员函数 不能修改对象中变量值
	return Complex(this->a - c.a, this->b - c.b);
}

void Complex::display() {
	cout << this->a;
	if (this->b < 0) cout << this->b << "i"; 
	if (this->b > 0) cout << "+" << this->b << "i"; 
}


int main()
{
    Complex c1(5,5);
    Complex c2(4.5,6.3);
    Complex c3(++c1 - c2);  
    c3.display();

    // Complex c4(++c1 - c2);
    // c4.display();
}