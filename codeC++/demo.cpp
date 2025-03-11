#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
 
using namespace std;

/*
运算符重载  
复数 
a + bi
*/
class Complex{
private:
    int x;  // 实部
    int y;  // 虚部

public:
    Complex() {}
    Complex(int x, int y): x(x), y(y) {}

    void display() {
        cout << x;
        if (y >= 0) cout << " + " << y << "i";
        else  cout << y << "i";
        cout << endl;
    }
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // friend 返回值类型 operator操作符 (参数) {}
    
    Complex operator+(Complex& c);  // +    
    friend Complex operator-(Complex& c1, Complex& c2); 
    friend bool operator!=(Complex& c1, Complex& c2);  // 不等于 返回真
    friend ostream& operator<<(ostream& os, const Complex& c);  // 重载输出运算符
    friend istream& operator>>(istream& is, Complex& c);  // 重载输入运算符
    Complex operator++() {
        ++x;
        ++y;
        return *this;
    }
    
    Complex operator++(int) {
        Complex temp = *this;
        ++x;
        ++y;
        return temp;
    }
    friend Complex operator--(Complex& c);  //  前缀--

    friend Complex operator--(Complex& c, int);  // 后缀--  用int进行区分
};
Complex operator--(Complex& c)
{   // 后运算符
    Complex temp = c;
    --c.x;
    --c.y;
    return temp;
}

// 这种写法不对
Complex operator--(Complex& c, int){
    Complex temp = c;
    --c.x;
    --c.y;
    return temp;
}

/*
>> 运算符的重载 不能 将 Complex& c 改为 const Complex& c，这是因为 
>> 运算符需要修改传入的对象（即读取输入并将其存储到对象的成员中），而 const 修饰符禁止对对象进行修改。
*/
istream& operator>>(istream& is, Complex& c) {
    is >> c.x >> c.y;
    return is;
}

// 
/*
原因在于你在 ostream& operator<<(ostream& os, Complex& c) 中使用了 Complex& 类型，
而在调用时 cur-- 返回的是一个临时对象。临时对象是 const 类型的，因此你需要调整 operator<< 的签名，使其能接受常量对象。
将 operator<< 的参数类型从 Complex& c 改为 const Complex& c，这样可以接受临时对象（常量引用）。why
临时对象是不可修改的，因此不能绑定到非常量引用上。
*/
ostream& operator<<(ostream& os, const Complex& c) { 
    if (c.y < 0) os << c.x << c.y;
    else os << c.x << "+" << c.y;
    os << "i";
    return os;
}

bool operator!=(Complex& c1, Complex& c2) {
    if (c1.x != c2.x || c1.y != c2.y) return true;
    else return false;

    // return c1.x != c2.x || c1.y != c2.y;
}

Complex operator-(Complex& c1, Complex& c2) {
    Complex ans;  // 最终的结果
    ans.x = c1.x - c2.x;
    ans.y = c1.y - c2.y;
    return ans;
}

Complex Complex::operator+(Complex& c) {
    Complex ans;
    ans.x = this->x + c.x;
    ans.y = this->y + c.y;
    return ans;
}




int main() 
{ 
    Complex c1;      // 5+7i
    Complex c2(4, 9);// 4+9i
    
    // 测试 输入运算符
    // c1.set(5, 7);
    cin >> c1;

    // c1.display();

    Complex cur = c1 - c2;
    // cur.display();
    cout << cur << endl;
    
    // Complex ans = cur++;
    cout << cur-- << endl;
    // cout << ans << endl;
    // cout << cur << endl;
    

    // 验证++
    // ++a;
    // cout << cur << endl;

    // 验证！=
    // if (c1 != c2) cout << "yes" << endl;
    // else cout << "no" << endl;

    // ++
}

 


 