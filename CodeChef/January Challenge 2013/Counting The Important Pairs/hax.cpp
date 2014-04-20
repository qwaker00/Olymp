#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

int n, m, in[N], to1[N], to2[N];
int timer = 0;
vector<int> g[N];

int most = 0;
int mostp = 0;

void dfs(int x, int pr = -1) {
	in[x] = ++timer;
	to1[x] = to2[x] = timer;

	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (y == pr) continue;

		if (in[y]) {
			if (to1[x] >= in[y]) {
				to2[x] = to1[x];
				to1[x] = in[y];
			} else
			if (to2[x] > in[y]) {
				to2[x] = in[y];
			}
		} else {
			dfs(y, x);

			if (to1[y] >= in[y]) {
				++most;
			} else {
				if (to2[y] >= in[y]) {
					++mostp;
				}
			}

			if (to1[x] >= to1[y]) {
				to2[x] = to1[x];
				to1[x] = to1[y];
			} else
			if (to2[x] > to1[y]) {
				to2[x] = to1[y];
			}
			if (to1[x] >= to2[y]) {
				to2[x] = to1[x];
				to1[x] = to2[y];
			} else
			if (to2[x] > to2[y]) {
				to2[x] = to2[y];
			}
		}
	}
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);

	LL ans = LL(m) * (m - 1) / 2 - (LL(most) * (most - 1) / 2 + LL(most) * (m - most) + mostp);
	cout << ans << endl;

    return 0;
}
