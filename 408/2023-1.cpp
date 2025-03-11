#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> up;   //            
    vector<char> low;
    for (int i = 0; i < 26; i++)
        up.push_back('A' + i);
    for (int i = 0; i < 26; i++)
        low.push_back('a' + i);

    char ch;    // ch =b   ch-'a'
    int n;
    cin >> ch >> n;
    int idx;
    if (ch >= 'A' && ch <= 'Z')
    {
        idx = ch - 'A';
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        idx = ch - 'a';
    }
    else
    {
        cout << "input error" << endl;
        return 0;
    }


    
    vector<string> ans;
    if (ch >= 'A' && ch <= 'Z')
    {
        for (int i = 0; i < n; i++)
        {
            string cur;
            cout << string(i, ' ');
            cur += string(i, ' ');
            if (i != n - 1)
            {  
                cout << up[(idx + n - i - 1) % 26];
                cur += string(1, up[(idx + n - i - 1) % 26]);

                cout << string((n - i - 1) * 2 - 1, ' ');
                cur += string((n - i - 1) * 2 - 1, ' ');

                cout << up[(idx + n - i - 1) % 26] << endl;
                cur += string(1, up[(idx + n - i - 1) % 26]);

                ans.push_back(cur);
            }
            else
                cout << up[idx] << endl;
        }

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << endl;
        }
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        for (int i = 0; i < n; i++)
        {
            string cur;
            cout << string(i, ' ');
            cur += string(i, ' ');
            if (i != n - 1)
            {

                cout << low[(idx + n - i - 1) % 26];
                cur += string(1, low[(idx + n - i - 1) % 26]);

                cout << string((n - i - 1) * 2 - 1, ' ');
                cur += string((n - i - 1) * 2 - 1, ' ');

                cout << low[(idx + n - i - 1) % 26] << endl;
                cur += string(1, low[(idx + n - i - 1) % 26]);

                ans.push_back(cur);
            }
            else
                cout << low[idx] << endl;
        }

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}