// https://codeforces.com/contest/1196/problem/D2

#include <bits/stdc++.h>

using namespace std;

int main() {	
	const string t = "RGB";

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 1e9;
		for (int offset = 0; offset < 3; ++offset) {
			vector<int> res(n);
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				res[j] = (s[j] != t[(j + offset) % 3]);
				cur += res[j];
				if (j >= k) cur -= res[j - k];
				if (j >= k - 1) ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}