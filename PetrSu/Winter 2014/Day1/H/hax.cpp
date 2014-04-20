#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <memory.h>
#include <vector>
#include <cstdio>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define M 1000000007
#define N 333

int n, w[N];
vector<int> g[N];
int f[N][N + N][3];
int ff[N + N][3];

inline void add(int& x, int y) {
	x = (x + y) % M;
}
inline int mul(int x, int y) {
	return (LL(x) * y) % M;
}

void dfs(int x, int pr = -1) {
	for (int balance = -n + N; balance <= n + N; ++balance) memset(f[x][balance], 0, sizeof(f[x][balance]));
	w[x] = 1;
	f[x][N + 1][1] = 1;
	f[x][N + 0][2] = 2;
	for (size_t i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == pr) continue;
		dfs(y, x);
		for (int j = -w[x] + N; j <= w[x] + N; ++j) for (int sj = 0; sj < 3; ++sj) if (f[x][j][sj]) {
			for (int k = -w[y] + N; k <= w[y] + N; ++k) for (int sk = 0; sk < 3; ++sk) if (f[y][k][sk]) {
				if (sj == 2 || sk == 2) {
					add(ff[j + k - N][sj], mul(f[y][k][sk], f[x][j][sj]));
				} else {
					add(ff[j + k - N - (sk * 2 - 1) - (sj * 2 - 1) + ((sk ^ sj) * 2 - 1)][sk ^ sj], mul(f[y][k][sk], f[x][j][sj]));
				}
			}
		}
		w[x] += w[y];
		for (int j = -w[x] + N; j <= w[x] + N; ++j) {
			memcpy(f[x][j], ff[j], sizeof(f[x][j]));
			memset(ff[j], 0, sizeof(ff[j]));
		}
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	while (cin >> n) {
		for (int i = 0; i <= n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);

	/*	for (int i = 1; i <= n; ++i) {
			cerr << i << ": " << endl;
			for (int j = -n + N; j <= n + N; ++j) {
				if (f[i][j][0]) cerr << "\tbalance:" << j - N << " state:" << 0 << " = " << f[i][j][0] << endl;
				if (f[i][j][1]) cerr << "\tbalance:" << j - N << " state:" << 1 << " = " << f[i][j][1] << endl;
				if (f[i][j][2]) cerr << "\tbalance:" << j - N << " state:" << 2 << " = " << f[i][j][2] << endl;
			}
		}
		cerr << "===\n";
	*/
		LL ans = 0;
		for (int balance = -n + N; balance <= n + N; ++balance) {
			ans = (ans + ((LL(f[1][balance][0]) + f[1][balance][1] + f[1][balance][2]) % M) * max(0, balance - N)) % M;
		}
		cout << (ans * 3) % M << endl;
	}

    return 0;
}
