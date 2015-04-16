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

	unordered_map<int, int> last;
	vector<int> prev(n, -INF);
	for (int i = 0; i < n; ++i) {
		if (last.count(a[i])) {
			prev[i] = last[a[i]];
		}
		last[a[i]] = i;
	}

	vector< vector<int> > ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i].reserve(n - i);

		int curans = INF;
		for (int j = i; j < n; ++j) {
			if (prev[j] >= i)
				curans = min(curans, j - prev[j]);

		    if (curans == INF)
		    	ans[i].push_back(-1);
		    else
				ans[i].push_back(curans);
		}
	}

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		cout << ans[l - 1][r - l] << "\n";
	}
	    
    return 0;
}
