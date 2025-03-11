#include <bits/stdc++.h>

using namespace std;

// D:\SystemFile\Desktop\兼职\考研复试\b.txt
int main()
{
	string s;
	vector<string> v;
	ofstream fout("D:/SystemFile/Desktop/兼职/考研复试/b.txt", ios::out);
	if (!fout) {
	    cout << "打开失败" << endl;
	}

	while (cin >> s) {
		v.push_back(s);
		int cnt = 0;
		for (int i = v.size()-1; i >= 0; i--) {
			cout << ++cnt << '=' << v[i] << ' ';
			fout << cnt << '=' << v[i] << ' ';
			
			if (cnt == 4) break; 
		}
		cout << endl;
	}    
}