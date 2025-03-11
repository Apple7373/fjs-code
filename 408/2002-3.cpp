#include <bits/stdc++.h>

using namespace std;


bool check(int n) 
{
    int p = n * n;
    vector<int> v;
    while (p) {   
        v.push_back(p%10);
        p /= 10;
    }
    int i = 0;
    int j = v.size()-1;
    while (i < j) {
        if (v[i] != v[j]) return false;
        i++, j--;
    }
    return true;

}

int main() 
{
    for (int i = 0; i < 256; i++) {
        if (check(i)) cout << i << ' ';
    }
    return 0;
}