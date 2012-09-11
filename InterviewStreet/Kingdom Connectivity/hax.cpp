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
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 22222
#define M 222222

int xx[N], yy[M], pp[M], n, m, tn, ts[N], mark[N], x, y, kk, f[N];

void Mark(int x, int marker, int roadid) {
	if (mark[x] & marker) return;
	mark[x] ^= marker;
	for (int i = xx[x]; i; i = pp[i])
		if ( (i & 1) == roadid)
			Mark(yy[i], marker, roadid);
}

bool Dfs(int x) {
	if (mark[x] == 4) return true;
	if (mark[x] != 3) return false;
	mark[x] = 4;
	for (int i = xx[x]; i; i = pp[i])
		if ( (i & 1) == 1) {
			if (Dfs(yy[i]))
				return true;
		}
	mark[x] = 5;
	ts[tn++] = x;
	return false;
}

bool TopSort() {
	for (int i = 1; i <= n; i++)
		if (mark[i] == 3)
			if (Dfs(i))
				return true;
	return false;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;
		yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk;
	}

	Mark(1, 1, 1);
	Mark(n, 2, 0);

	if (TopSort()) {
		puts("INFINITE PATHS");
		return 0;
	}

	for (int i = 0; i < tn; ++i) {
		int x = ts[i];
		if (x == n) {
			f[x] = 1;
		} else {
			f[x] = 0;
			for (int i = xx[x]; i; i = pp[i])
				if ( (i & 1) == 1 ) {
					f[x] = (f[x] + f[yy[i]]) % 1000000000;
				}
		}
	}
	cout << f[1] << endl;

	return 0;
}
