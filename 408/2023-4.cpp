#include <bits/stdc++.h>

using namespace std;

struct Student {
    char cno[3]; //课程编号
    double avg;  //平均成绩
    char sno[3]; //学生编号  地址大
    // double avg;  //平均成绩
};
vector<Student> v;

bool cmp(Student a, Student b) {
    if (strcmp(a.cno, b.cno) == 0) {
        return a.avg > b.avg;
    }
    return strcmp(a.cno, b.cno) < 0;
    // return a.cno < b.cno;
}
int main()
{
    char ch[3];
    while (cin >> ch) {
        if (ch[0] == '\\') break;
        Student s;
        strcpy(s.cno, ch);
        cin >> ch;
        strcpy(s.sno, ch);
        cin >> s.avg;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    cout << "cno\tsno\tavg\n"; 

    for (auto it : v) {
        cout << it.cno << "\t" << it.sno << "\t" << it.avg << endl;
    }
    return 0;
}