#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;
int was[N], IT = 0;
int p[N][22];
int in[N], out[N], d[N];
vector<int> g[N];
LL S[N+N];
int timer;
LL val[N], inpv[N];

int NN;

void add(int x, LL y) {
	while (x <= NN) {
		S[x] += y;
		x = (x | (x - 1)) + 1;
	}
}

LL sum(int l, int r) {
	if (l > 0) return sum(0, r) - sum(0, l - 1);
	LL ans = 0;
	while (r) {
		ans += S[r];
		r &= r - 1;
	}
	return ans;
}

void dfs(int x) {
	was[x] = IT;

	for (int i = 1; i < 22; ++i) {
		p[x][i] = p[p[x][i - 1]][i - 1];
	}

	++timer;
	in[x] = timer;

	for (int i =0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (was[y] == IT) continue;
		p[y][0] = x;
		d[y] = d[x] + 1;
		dfs(y);
	}

	++timer;
	out[x] = timer;
}

int lca(int x, int y) {
	for (int i = 21; i >= 0; --i) if (p[x][i] && d[p[x][i]] >= d[y]) x = p[x][i];
	for (int i = 21; i >= 0; --i) if (p[y][i] && d[p[y][i]] >= d[x]) y = p[y][i];
	if (x == y) return x;
	for (int i = 21; i >= 0; --i) if (p[y][i] != p[x][i]) {
		x = p[x][i];
		y = p[y][i];
	}
	return p[x][0];
}

inline LL get_v(int x) {
	return val[x];
}

inline void add_v(int x, LL y) {
	add(in[x], y);
	add(out[x], -y);
	val[x] += y;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d\n", &n, &m);
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			inpv[i] = x;
		}
		scanf("\n");
		for (int i = 1; i < n; ++i) {
			int x, y;
			scanf("%d%d\n", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}

		++IT;
		timer = 0;
		d[1] = 0;
		dfs(1);
		NN = timer;

		for (int i = 1; i <= n; ++i) add_v(i, inpv[i]);
		timer = 0;
		while (m--) {
			++timer;
			char ch;
			scanf("%c", &ch);
			if (ch == 'C') {
				int x, y;
				scanf("%d%d\n", &x, &y);
				int z = lca(x, y);
				LL ans = sum(in[z], in[x]) + sum(in[z], in[y]) - get_v(z);
				ans += LL(timer) * (d[x] + d[y] - d[z] - d[z] + 1);
				printf("%lld\n", ans);
			} else
			if (ch == 'P') {
				int x;
				scanf("%d\n", &x);
				add_v(x, -timer - get_v(x));
			} else assert(false);
		}

		memset(S, 0, sizeof(S[0]) * (NN + 3));
		memset(val, 0, sizeof(val[0]) * (n + 3));
		memset(p, 0, sizeof(p[0]) * (n + 3));
		for (int i = 1; i <= n; ++i) g[i].clear();
	}

    return 0;
}
