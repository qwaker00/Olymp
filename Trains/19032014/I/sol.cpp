#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 500111;
int h[N], f[N];
vector<int> g[N];
vector<int> v[N];
int w[N];
bool was[N];
ll ans[N];
int n, m;

void dfs(int x) {
	was[x] = true;
	f[x] = h[x];
	w[x] = 1;

	int whole = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];

		if (was[y]) {
			f[x] = min(f[x], h[y]);
		} else {
			h[y] = h[x] + 1;
			dfs(y);
			w[x] += w[y];

			f[x] = min(f[x], f[y]);
			if (f[y] < h[x]) {
				whole += w[y];		
			} else {
				v[x].push_back(w[y]);	
			}
		}
	}
	v[x].push_back(n - w[x] + whole);

	ll sum = 0;
	for (int i = 0; i < v[x].size(); ++i) {
		ans[x] += sum * ll(v[x][i]);
		sum += v[x][i];
	}
	ans[x] += n - 1;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}
