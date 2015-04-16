#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;

const int Mod = 1000000007;

inline void add(int& x, int y) {
	x = (x + y) % Mod;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
	for (int __case = 1; __case <= T; ++__case) {
		int n, m;
		scanf("%d-%d", &n, &m);
		assert(n > 0);
		assert(n > m);

		int ans1, ans2;
		{
			vector< vector<int> > f(n + 1, vector<int>(m + 1, 0));
			f[0][0] = 1;
			for (int i = 0; i <= n; ++i)
				for (int j = 0; j <= m; ++j) {
					if (i + 1 <= n) add(f[i + 1][j], f[i][j]);
					if (j + 1 < i && j + 1 <= m) add(f[i][j + 1], f[i][j]);
				}
			ans1 = f[n][m];
		}
		{
			vector< vector<int> > f(n + 1, vector<int>(m + 1, 0));
			f[0][0] = 1;
			for (int i = 0; i <= n; ++i)
				for (int j = 0; j <= m; ++j) {
					if ((j == m || i + 1 <= j) && i + 1 <= n) add(f[i + 1][j], f[i][j]);
					if (j + 1 <= m) add(f[i][j + 1], f[i][j]);
					//cerr << i << " " << j << "  " << f[i][j] <<endl;
				}
			ans2 = f[n][m];
		}

		cout << "Case #" << __case << ": " << ans1 << " " << ans2 << endl;
	}

    return 0;
}
