#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[100];
	char b[100];
	scanf("%s", a+1);
	scanf("%s", b+1);
	a[0]='0';
	b[0]='0';
	
	int n = strlen(a);
	int m = strlen(b);
	int d[100][100];
	memset(d, 0, sizeof d);
	int max = 0;
	int cnt = 0;
	for (int i = 1; i < strlen(a); i++) {
		for (int j = 1; j < strlen(b); j++) {
			if (a[i] == b[j]) {
				d[i][j] = d[i-1][j-1] + 1;
				if (d[i][j] > max) {
					max = d[i][j];
					cnt = 1;
				} else if (d[i][j] == max) cnt++;
			}
				
		}	
	}

	cout << max << ' ' << cnt;
}



