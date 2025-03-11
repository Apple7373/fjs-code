#include <bits/stdc++.h>

using namespace std;

class Student {
    public:
        char name[10];
        int num;
        void show() {
            cout << name << ' ' << num << endl;
        }
};

vector<Student> v;

void in() {
    cout << "请输入数量：";
    int n;
    cin >> n;
    while (n--) {
        char curname[10];
        cin >> curname;
        Student stu;
        strcpy(stu.name, curname);
        cin >> stu.num;
        v.push_back(stu);
    }
}

void search() {
    int num;
    cout << "请输入学号：";
    cin >> num;

    for(auto it : v) {
        if (it.num == num) {
            cout << "找到：";
            it.show(); 
            return; // 结束程序
        }
    }
    cout << "未找到." << endl;   
}

// 升序
bool cmp1(Student a, Student b) {
    return a.num < b.num;
}
// 降序
bool cmp2(Student a, Student b) {
    return a.num > b.num;
}

// 浏览
void display() {
    cout << "1、升序  2、降序：";
    int op;
    cin >> op;
    if (op == 1) sort(v.begin(), v.end(), cmp1);
    else if (op == 2) sort(v.begin(), v.end(), cmp2);
    for (auto it : v) {
        cout << it.name << ' ' << it.num << endl;
    }
}
int main()
{
    while (true) {
        cout << "请输入操作1、输入 2、查询 3、浏览 4、结束：" << endl;
        int op;
        cin >> op;
        switch(op) {
            case 1: 
                in();
                break;
            case 2:
                search();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0; // 结束程序
            default:
                cout << "输入错误。" << endl;

        }
    }
    
}

/*
zs 90
ls 88
ww 101
 */