#include<bits/stdc++.h>
using namespace std;



void recurse(vector<int> &ds, int &count, char letter, string word, int n) {

	int mmin, count, pos;
	vector<int>::iterator new_end;
	while (true) {
		mmin = *min_element(dst.begin(), dst.end());
		count = 0;
		for (int i = 0; i < ds.size(); i++) {
			if (mmin == ds[i]) {
				count++;
				pos = i;
			}
			if (count == 2) {
				ds[i] = mmin * 2;
				break;
			}
		}
		if (count == 2) break;
		new_end = remove(dst.begin(), dst.end(), mmin);
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> ds;
	int a;
	for (int i = 0; i < q; i++) {
		cin >> a;
		ds.push_back(a);
	}
	recurse(ds, count, 'a', "", n);
	cout << count;
}