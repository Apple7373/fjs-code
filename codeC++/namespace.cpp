#include <bits/stdc++.h>
#include <iostream> 
#include <math.h>

using namespace std;

class MyClass{
private:
    int age;
public:
    MyClass() {
        cout << "调用无参数构造" << endl;
    }
    MyClass(int age);
    void doSome() {
        cout << age << endl;
    }
    void setAge(int a) {
        age = a;
    }
};

MyClass::MyClass(int age): age(age) {
    cout << "调用有参数构造" << endl;
}

int main() 
{
    MyClass mc; // 调用无参数构造
    MyClass mc(19); // 调用有参数构造
    MyClass mc(); // 被视为一种函数声明，不是声明一个类对象
}

