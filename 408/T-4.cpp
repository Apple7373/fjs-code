#include <bits/stdc++.h>

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
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << "*name:" << v[i].name << "\tscore:" << v[i].s1 << ' ' << v[i].s2 << ' ' << v[i].s3 << ' ' << v[i].avg << endl;
    }
    return 0;
}