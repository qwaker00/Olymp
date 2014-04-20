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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;

//int ans2[N];
int n, m, q, ans[N], was[N], endx[N];
vector<int> g[N], good[N], grev[N];

int dfs_counter = 0;

struct Tp {
	int l, r, v;
} T[4*N];

void init(int x, int l, int r) {
	T[x].v = 1e9, T[x].l = l, T[x].r = r;
	if (l < r) {
		init(x + x, l, (l + r) >> 1);
		init(x + x + 1, (l + r + 2) >> 1, r);
	}	
}

void update(int x, int l, int r, int v) {
	if (T[x].l > r || T[x].r < l) return;
	if (l <= T[x].l && r >= T[x].r) {
		if (v < T[x].v) T[x].v = v;
		return;
	}
	update(x + x, l, r, v);
	update(x + x + 1, l, r, v);
}

int getmin(int x, int l) {
	int ans = T[x].v;
	while (T[x].r > T[x].l) {
		if (T[x + x].r >= l) x = x + x;else x = x + x + 1;
		if (T[x].v < ans) ans = T[x].v;
	}
	return ans;
}

void dfs_good(int x) {
	//assert(x == ++dfs_counter);
	++dfs_counter;
	was[x] = 1;
	sort(g[x].begin(), g[x].end());
	good[x].resize(g[x].size());
	for (int i = 0; i < (int)g[x].size(); ++i)
		if (!was[g[x][i]]) {
			good[x][i] = true;
			dfs_good(g[x][i]);
		} else {
			good[x][i] = false;
		}
	endx[x] = dfs_counter;
}

void dfs(int x) {	
//	update(1, x, x, x);
	for (int i = ((int)g[x].size()) - 1; i >= 0; --i) {
		if (good[x][i]) {
			dfs(g[x][i]);
		}
	}
	//assert(x == dfs_counter--);
	int bestx = x;
	for (int i = 0; i < (int)grev[x].size(); ++i) {
		int y = grev[x][i];
		int curx = (y < x) ? y : getmin(1, y);
		if (bestx > curx) bestx = curx;
	}
	update(1, x, endx[x], bestx);
	if (x != bestx) {
//		cerr << x << " " << bestx << endl;
		++ans[bestx];
	}
}

int wasIt[N], IT = 0;

int brute(int x, int source) {
	if (x <= source) return x;
	if (wasIt[x] == IT) return 1e9;
	wasIt[x] = IT;
	int best = x;
	for (int i = 0; i < (int)grev[x].size(); ++i) {
		int t = brute(grev[x][i], source);
		if (t < best) best = t;
	}
	return best;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
    	scanf("%d%d%d", &n, &m, &q);
    	for (int i = 0; i <= n + 1; ++i) {
    		was[i] = 0;
    		g[i].clear();
    		grev[i].clear();
    		good[i].clear();
    		ans[i] = 0;
    	}
    	for (int i = 0; i < m; ++i) {
    		int x, y;
    		scanf("%d%d", &x, &y);
    		g[x].push_back(y);
    		grev[y].push_back(x);
    	}

    	init(1, 1, n);
    	dfs_counter = 0;
    	dfs_good(1);
    	dfs(1);

//    	cerr << endl;

/*    	for (int x = 1; x <= n; ++x) ans2[x] = 0;
    	for (int x = 2; x <= n; ++x) {
    		++IT;
			int best = x;
			for (int i = 0; i < (int)grev[x].size(); ++i) {
				int t = brute(grev[x][i], x);
				if (t < best) best = t;
			}
//			cerr << x << " " << best << endl;
    		++ans2[best];
    	}
*/
    	//int sum = 0;
    	//for (int i = 1; i <= n; ++i) sum += ans[i];
    	//assert(sum == n - 1);

/*    	for (int i = 1; i <= n; ++i) {
    		assert(ans[i] == ans2[i]);
    	}
*/
    	for (int i = 0; i < q; ++i) {
    		int x;
    		scanf("%d", &x);
    		if (i) putchar(' ');
    		printf("%d", ans[x]);
    	}
    	puts("");
//    	cerr << endl;
    }

    return 0;
}
