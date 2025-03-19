// 版本二
#include <bits/stdc++.h>

using namespace std;

char a[100][100];
int main()
{
	memset(a, ' ', sizeof a);
	char c;
	int n;
	cin >> c >> n;

	a[n-1][n-1] = c;
	for (int i = n-2, j = n-2, k = n, cnt = 1; i >= 0; i--, cnt++, j--, k++) {
		char cur = c + cnt;
		if (c + cnt >= 'z' || c + cnt >= 'Z' && c + cnt <= 'A') {
			cur -= 26;
		}
		a[i][j] = cur;
		a[i][k] = cur;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++)
			cout << a[i][j];
		cout << endl;
	}
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < 10; j ++) 
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}


// 版本一
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     vector<char> up;   //            
//     vector<char> low;
//     for (int i = 0; i < 26; i++)
//         up.push_back('A' + i);
//     for (int i = 0; i < 26; i++)
//         low.push_back('a' + i);

//     char ch;    // ch =b   ch-'a'
//     int n;
//     cin >> ch >> n;
//     int idx;
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         idx = ch - 'A';
//     }
//     else if (ch >= 'a' && ch <= 'z')
//     {
//         idx = ch - 'a';
//     }
//     else
//     {
//         cout << "input error" << endl;
//         return 0;
//     }


    
//     vector<string> ans;
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         for (int i = 0; i < n; i++)
//         {
//             string cur;
//             cout << string(i, ' ');
//             cur += string(i, ' ');
//             if (i != n - 1)
//             {  
//                 cout << up[(idx + n - i - 1) % 26];
//                 cur += string(1, up[(idx + n - i - 1) % 26]);

//                 cout << string((n - i - 1) * 2 - 1, ' ');
//                 cur += string((n - i - 1) * 2 - 1, ' ');

//                 cout << up[(idx + n - i - 1) % 26] << endl;
//                 cur += string(1, up[(idx + n - i - 1) % 26]);

//                 ans.push_back(cur);
//             }
//             else
//                 cout << up[idx] << endl;
//         }

//         for (int i = ans.size() - 1; i >= 0; i--)
//         {
//             cout << ans[i] << endl;
//         }
//     }
//     else if (ch >= 'a' && ch <= 'z')
//     {
//         for (int i = 0; i < n; i++)
//         {
//             string cur;
//             cout << string(i, ' ');
//             cur += string(i, ' ');
//             if (i != n - 1)
//             {

//                 cout << low[(idx + n - i - 1) % 26];
//                 cur += string(1, low[(idx + n - i - 1) % 26]);

//                 cout << string((n - i - 1) * 2 - 1, ' ');
//                 cur += string((n - i - 1) * 2 - 1, ' ');

//                 cout << low[(idx + n - i - 1) % 26] << endl;
//                 cur += string(1, low[(idx + n - i - 1) % 26]);

//                 ans.push_back(cur);
//             }
//             else
//                 cout << low[idx] << endl;
//         }

//         for (int i = ans.size() - 1; i >= 0; i--)
//         {
//             cout << ans[i] << endl;
//         }
//     }
//     return 0;
// }