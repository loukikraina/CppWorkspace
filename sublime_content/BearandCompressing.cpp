#include<bits/stdc++.h>
using namespace std;


void recurse(unordered_map<char, vector<string>> &ds, int &count, char letter, string word, int n) {
	if (ds.find(letter) == ds.end() || word.size() >= n - 1) return;


	for (auto a : ds[letter])
	{
		string tempw = word;
		tempw.insert(0, a);
		if (tempw.size() == n) {
			count++;
		}
		char temp = tempw[0];
		tempw.erase(0, 1);
		recurse(ds, count, temp, tempw, n);
	}

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	unordered_map<char, vector<string>> ds;
	string s;
	char a;
	int count = 0;
	for (int i = 0; i < q; i++) {
		cin >> s >> a;
		ds[a].push_back(s);
	}
	recurse(ds, count, 'a', "", n);
	cout << count;
}