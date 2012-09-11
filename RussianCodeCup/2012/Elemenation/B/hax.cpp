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

#define N 211111
#define M N+N

int ans1 = 0, ansc2 = -1, ansc1 = -1;
int xx[N], yy[M], pp[M], zz[M], was[N], c1, c2, n, x, y, z, kk = 0;

bool dfs(int x, int mi) {
	if (x == c2) {
		ans1 = mi;

		for (int i = xx[x]; i; i = pp[i]) {
			int y = yy[i];
			if (was[y]) {
				ansc2 = max(zz[i] - ans1, ansc2);
			} else
				ansc2 = max(zz[i], ansc2);
		}

		return true;
	}

	bool fnd = false;
	int aa = -1;

	was[x] = true;
	for (int i = xx[x]; i; i = pp[i]) {
		int y = yy[i];
		if (was[y]) continue;

		if (dfs(y, min(mi, zz[i]))) {
			fnd = true;
			aa = max(zz[i] - ans1, aa);
		} else
			aa = max(zz[i], aa);
	}
	if (x == c1) ansc1 = aa;

	return fnd;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);


	scanf("%d%d%d", &n, &c1, &c2);
	for (int i = 1; i < n;i++){ 
		scanf("%d%d%d", &x, &y, &z);
		yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk, zz[kk] = z;
		yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk, zz[kk] = z;
	}

	dfs(c1, (int)2e9);
	if (ansc1 != -1 && ansc2 != -1) {
		cout << min(ansc1, ansc2) + ans1 << endl;
	} else {
		cout << ans1 << endl;
	}

	return 0;
}
