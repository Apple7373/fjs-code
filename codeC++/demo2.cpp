#include <bits/stdc++.h>  // 
#include <cstring>
#include <vector>

#include "myclass.h"  // 绝对路径 相对路径  ../  linux 返回上一级

using namespace std;

class A{
private:
    int x;
public:
    friend void doSome(A obj);
};


void doSome(A obj) {
    cout << obj.x << endl;
}

class MyClass {
private:
    int x;
public:
    MyClass() : x(10) {}

    // 声明函数为友元函数
    friend void show(const MyClass& obj);     // show函数不是MyClass类的成员函数 是它的友元函数
    // friend void doSome(A obj){
       
    // }
};

// 友元函数定义
void show(const MyClass& obj) {
    // 友元函数可以访问 MyClass 的私有成员
    std::cout << "x = " << obj.x << std::endl;
}


int main()
{
    
}
