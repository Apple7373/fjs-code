#include <bits/stdc++.h>

using namespace std;

struct Student {
char cno[3]; //课程编号
// double avg;  //平均成绩
char sno[3]; //学生编号
double avg;  //平均成绩
};


int main()
{
	vector<Student> v;
	char c[3];
	while (cin >> c) {
		if (c[0] == '\\') break;
		Student s;
		strcpy(s.cno, c);
		cin >> c;
		strcpy(s.sno, c);
		cin >> s.avg;
		v.push_back(s);
	}
	for (auto it : v) {
		cout << it.cno << ' ' << it.sno << ' ' << it.avg << endl;
	}
	
}

