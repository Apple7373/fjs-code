#include <bits/stdc++.h>

using namespace std;

struct Student {
	string name;
	int age;
	int score;
	
	Student() {
	}
	Student(string name, int age, int score) {
		this->name = name;
		this->age = age;
		this->score = score;
	}
};

bool cmp(Student a, Student b) {
	return a.score > b.score;
}
int main()
{
	vector<Student> s;
    ifstream fin("D:/SystemFile/Desktop/兼职/考研复试/b.txt");
    if (!fin) {
        cout << "文件打开失败" << endl;
        return 0;
    }
    
    for (int i = 0; i < 4; i++) {
    	string name;
    	int age;
    	int score;
    	fin >> name >> age >> score;
    	Student curs(name, age, score);
    	s.push_back(curs);
	}
	sort(s.begin(), s.end(), cmp);
	
	for (auto it : s) {
		cout << it.name <<' ' << it.age << ' ' << it.score << endl;
	}
	return 0;
}