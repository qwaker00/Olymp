#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111
#define Q 333333

struct Tp {
	int y;
	int a, b;
	int i;

	Tp(int y = 0, int a = 0, int b = 0, int i = 0) : y(y), a(a), b(b), i(i) { }
};
vector<Tp> req1[N];
vector<Tp> req2[N];
int fail[Q], wasproc[Q];
int n, m, x, y, a, b, c, d, t, was[N], timer, inp[N], p[N], parent[N], dsu[N], bad[N], badmost[N], ra[Q], rb[Q];
vector<int> g[N];

int fs(int x) {
	if (dsu[x] != x) dsu[x] = fs(dsu[x]);
	return dsu[x];
}

void dfs(int x, int pr) {
	parent[x] = pr;
	was[x] = true;
	p[x] = inp[x] = ++timer;

	for (size_t i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == pr) continue;

		if (!was[y]) {
			dfs(y, x);
			if (p[y] < p[x]) p[x] = p[y];
			if (p[y] >= inp[x] || pr == -1) bad[y] = x + 1;
			if (p[y] >= inp[y]) badmost[y] = x + 1;
		} else {
			if (inp[y] < p[x]) p[x] = inp[y];
		}
	}

	for (size_t i = 0; i < req1[x].size(); ++i) {
		const Tp& r = req1[x][i];

		if (!wasproc[r.i]) {
			wasproc[r.i] = true;
			continue;
		}

		int fx = fs(r.a);
		int fy = fs(r.b);
		if ( badmost[r.y] == x + 1 && (fx == r.y || fy == r.y) && fx != fy) {
			fail[r.i] = true;
		}
	}

	for (size_t i = 0; i < req2[x].size(); ++i) {
		const Tp& r = req2[x][i];

		if (wasproc[r.i]) continue;
		wasproc[r.i] = true;

		int fx = fs(r.a);
		int fy = fs(r.b);
		if ( (bad[fx] == x + 1 || bad[fy] == x + 1) && fx != fy) {
			fail[r.i] = true;
		}
	}

	
	for (size_t i = 0; i < g[x].size(); ++i) if (parent[g[x][i]] == x) {
		dsu[ g[x][i] ] = x;
	}
}

int main() {
    freopen("police.in", "r", stdin);
    freopen("police.out", "w", stdout);
    
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			ra[i] = a;
			rb[i] = b;
			req1[c].push_back( Tp(d, a, b, i) );
			req1[d].push_back( Tp(c, a, b, i) );
		} else {
			scanf("%d%d%d", &a, &b, &c);
			ra[i] = a;
			rb[i] = b;
			req2[c].push_back( Tp(0, a, b, i) );

			if (a == c || b == c) fail[i] = true;
		}
	}
	
	for (int i = 1; i <= n; ++i) dsu[i] = i;
	for (int i = 1; i <= n; ++i) if (!was[i]) dfs(i, -1);
	for (int i = 0; i < q; ++i) {
		puts( (fail[i] || fs(ra[i]) != fs(rb[i])) ? "NO" : "YES");
	}

    return 0;
}
