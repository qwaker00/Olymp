#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 222223;
vector<int> g[N];
int w[N], f[N], t[N], timer = 0, n, m, was[N];
int ans[N];

void dfs(int x, int pr) {
	f[x] = t[x] = ++timer;
	was[x] = 1;
	w[x] = 1;
	vector<int> v;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == pr) continue;
		if (was[y]) {
			f[x] = min(f[x], t[y]);
		} else {
			dfs(y, x);
			if (f[y] >= t[x]) {
				v.push_back(w[y]);
			}	
			w[x] += w[y];
			f[x] = min(f[x], f[y]);
		}
	}
	int s = 0;
	for (int i =0 ; i < v.size(); ++i) {
		ans[x] += v[i] * (n - w[x] + s);
		s += v[i];
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for (int i = 1; i <= n; ++i) if (!was[i])
		dfs(i, -1);
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i] + n - 1);
	}
	return 0;
}
