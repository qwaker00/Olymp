#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define INF 1000000000
#define N 222

size_t start[N];
int n, m, jcost[N], rcost[N], f[N*2][N*2], d[N*2];
vector<int> g[N*2];

inline void add(int x, int y, int fl) {
	g[x].push_back(y);
	g[y].push_back(x);
	f[x][y] = fl;
	f[y][x] = 0;
}

bool bfs(int x) {
	queue<int> q;
	memset(d, 63, sizeof(d));
	q.push(x);
	d[x] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (size_t i = 0, y; i < g[x].size(); ++i)
			if (f[x][y = g[x][i]] > 0 && d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
	}
	return d[n + m + 1] < 1e9;
}

int dfs(int x, int maxfl) {
	if (x == n + m + 1) return maxfl;
	int totfl = 0;
	for (size_t& i = start[x], y; i < g[x].size(); ++i)
		if (d[x] + 1 == d[y = g[x][i]] && f[x][y] > 0) {
			int fl = dfs(y, min(maxfl - totfl, f[x][y]));
			if (fl) {
				f[x][y] -= fl;
				f[y][x] += fl;
				totfl += fl;
				if (maxfl == totfl) break;
			}
		}
	return totfl;
}

int main() {	
//	freopen(".in", "r", stdin);

	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i) scanf("%d", &rcost[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &jcost[i]);
	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			add(i, x + n, INF);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		add(0, i, jcost[i]);
		ans += jcost[i];
	}
	for (int i = 1; i <= m; ++i) add(n + i, n + m + 1, rcost[i]);
	while (bfs(0)) {
		memset(start, 0, sizeof(start));
		ans -= dfs(0, INF);
	}

	cout << ans << endl;
	return 0;
}
