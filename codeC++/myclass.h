#ifndef MYCLASS_H   //if not define  如果没有定义
#define MYCLASS_H

#include <bits/stdc++.h>
using namespace std;

class myclass{
private:
    int age;
    string name;
public:
    myclass(){}
    myclass(int age, string name);
    void display();
    void set(int a, string n);
};

myclass::myclass(int age, string name) {
    this->age = age;
    this->name = name;
}

void myclass::display() {
    cout << age << endl << name << endl;
}

void myclass::set(int a, string n)  {
    this->age = a;
    this->name = n;
}

#endif
