#include <bits/stdc++.h>

using namespace std;

struct Student{
    string id;
    string name;
    int age;
};
int main() 
{
    ifstream fin("D:/SystemFile/Desktop/兼职/考研复试/b.txt");
    if (!fin) {
        cout << "文件打开失败" << endl;
        return 0;
    }   
    string tar;
    cin >> tar;
    
    while (true) {
        string id;
        string name;
        int age;
        fin >> id >> name >> age;
        if (id == "") break; // 文件已经读完
        if (id == tar) {
            cout << "找到:" << id << ' ' << name << ' ' << age << endl;
            return 0;
        }
    }
    cout << "文件中没有" << endl;

    return 0;
}