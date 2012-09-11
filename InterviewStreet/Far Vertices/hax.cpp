#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int mark[222], x, y, yy[222], pp[222], xx[222], ans = 0, pr[222], kk = 0, n, k;

void Mark(int x, int k, int pr = -1) {
	mark[x] = true;
	if (k)
		for (int i = xx[x]; i; i = pp[i]) {
			int y = yy[i];
			if (y == pr) continue;
			Mark(y, k - 1, x);
		}
}

void dfs(int x) {
	for (int i = xx[x]; i; i = pp[i]) {
		int y = yy[i];
		if (y == pr[x]) continue;

		pr[y] = x;
		dfs(y);
	}
	if (!mark[y]) {
		++ans;

		int xx = x, cc = k;
		while (pr[xx] != -1 && cc > 0) {
			cc--;
			xx = pr[xx];
		}
		Mark(xx, k);
	}
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		cin >> x >> y;
		yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;
		yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk;
	}

	pr[1] = -1;
	dfs(1);
	cout << ans << endl;

	return 0;
}
