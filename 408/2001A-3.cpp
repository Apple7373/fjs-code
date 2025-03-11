#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int a = 1; a < 10; a++) 
        for (int b = 0; b < 10; b++)
            for (int c = 0; c < 10; c++)
                for (int d = 0; d < 10; d++) 
                    if (9*(a*1000 + b*100 + c*10 + d) == d*1000 + c*100 + b*10 + a) cout << a*1000 + b*100 + c*10 + d << ' ';
    cout << endl;
    return 0; 
}