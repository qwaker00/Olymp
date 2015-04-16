#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int INF = 2e9;

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l; --r;

		unordered_map<int, int> last;
		int ans = INF;
		for (int j = l; j <= r; ++j) {
			if (last.count(a[j]))
				ans = min(ans, j - last[a[j]]);
			last[a[j]] = j;
		}
		if (ans == INF)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}
	    
    return 0;
}
