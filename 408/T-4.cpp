#include <bits/stdc++.h>
/*

<<<<<<< HEAD
/*

=======
>>>>>>> 8572e67f9c93700effd8905dc6194bc53aaa65ba
3、输入学生个数以及每个学生的姓名和3门课程成绩：输出不及格学生的信息；按平均成绩排序，从高到低输出学生信息。
输入示例：
5
zhaoyi   70 80 91
zhanger  68 40 90
zhangsan 60 70 80
lisi      70 80 90
wangwu  52 70 100 

输出：
*name:zhaoyi    score:70 80 91 80.3333
*name:lisi      score:70 80 90 80
*name:wangwu    score:52 70 100 74
*name:zhangsan  score:60 70 80 70
*name:zhanger   score:68 40 90 66

*/
using namespace std;
struct Student{
    string name;
    double s1, s2,s3;
    double avg;
};
bool cmp(Student a, Student b) {
    return a.avg > b.avg;
}
int main()
{   
    vector<Student> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student cur;
        cin >> cur.name >> cur.s1 >> cur.s2 >> cur.s3;
        cur.avg = (cur.s1 + cur.s2 + cur.s3)/3;
        v.push_back(cur);
    }
    // 输出不及格学生
    for (int i = 0; i < n; i++) {
        if (v[i].s1 < 60 || v[i].s2 < 60 || v[i].s3 < 60) 
            cout << "*name:" << v[i].name << "\tscore:" << v[i].s1 << ' ' << v[i].s2 << ' ' << v[i].s3 << endl;
    }
    sort(v.begin(), v.end(), cmp);
    // 按平均成绩降序输出学生信息
    for (int i = 0; i < n; i++) {
        cout << "*name:" << v[i].name << "\tscore:" << v[i].s1 << ' ' << v[i].s2 << ' ' << v[i].s3 << endl;
    }
    return 0;
}
