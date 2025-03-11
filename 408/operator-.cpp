#include <bits/stdc++.h>

// 考试时不计算时间复杂度    暴力  

using namespace std;

class Complex{
	private:
		double a, b;
	public:
		Complex() {}
		Complex(double a, double b):a(a), b(b) {}
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
	Complex c1(5.2,6);
	Complex c2(4.8,4);

	Complex c3 = c2 - c1;
	c3.display();

	return 0;
}