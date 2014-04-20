#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
using namespace std;

#define N 511111

vector<int> g[N];
int w[N], d[N], a[N], p[N], f[N];
pair<int, int> b[N];

void dfs(int x, int pr = -1) {
	w[x] = 1;	
	for (int i = 0; i < (int)g[x].size(); ++i) {
		if (g[x][i] == pr) continue;
		d[g[x][i]] = d[x] + 1;
		p[g[x][i]] = x;
		dfs(g[x][i], x);
		w[x] += w[g[x][i]];
	}
}
void deadline(int x) {
	f[x] = max(a[x] + d[x], f[ p[x] ] + 1);
	for (int i = 0; i < (int)g[x].size(); ++i) {
		if (g[x][i] == p[x]) continue;
		deadline(g[x][i]);
	}	
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	d[1] = 0;
	p[1] = 0;
	dfs(1);
	deadline(1);
	for (int i = 1; i <= n; ++i) {
		b[i] = make_pair(-f[i], i);
	}
	sort(b + 1, b + n + 1);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int x = b[i].second;
		ans = max(ans, a[x] + d[x] + i - 1);
	}
	cout << ans << endl;
	
//	cerr << "Time: " << clock() << endl;
	return 0;
}
