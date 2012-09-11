#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<size_t> Z(string s) {
	size_t n = s.length();
	vector<size_t> z(n);
	for (size_t i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)	z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		vector<size_t> z = Z(s);
		z[0] = s.length();
		cout << std::accumulate(z.begin(), z.end(), 0) << endl;
	}

	return 0;
}
