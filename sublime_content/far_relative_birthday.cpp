#include<bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	char arr[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	int count = 0, x, y, m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (arr[i][j] == '.') continue;
			else {
				x = i;
				y = j;
				m = n - 1;

				while (true) {
					if (m - x <= 0 && m - y <= 0) break;

					if (m - x > 0) {
						if (arr[++x][j] == 'C') count++;
					}
					if (m - y > 0) {
						if (arr[i][++y] == 'C') count++;
					}
				}
			}
		}
	cout << count;
}