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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
             
#define N 111111
#define M N*2

LL ans = 0;
int x, y, z, n, k, kk = 0;
int xx[N], yy[M], zz[M], pp[M], was[N], bad[N];

bool dfs(int x, int& mnroad) {
	was[x] = true;
	bool any = false;
	for (int i = xx[x]; i; i = pp[i]) {
		int y = yy[i], r = (int)2e9;
		if (was[y]) continue;
		if (dfs(y, r)) {
			if (!any) {
				any = true;
				mnroad = min(zz[i], r);
			} else {
				int w = min(zz[i], r);
				if (w <= mnroad) {
					ans += w;
				} else {
					ans += mnroad;
					mnroad = w;
				}
			}
		}
	}
	if (any && bad[x]) {
		ans += mnroad;
		mnroad = (int)2e9;
	}
	return any || bad[x];
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> x >> y >> z;
		yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk, zz[kk] = z;
		yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk, zz[kk] = z;
	}
	for (int i = 0;i < k; i++) {
		cin >> x;
		bad[x] = true;
	}

	ans = 0;
	int r = (int)2e9;
	dfs(0, r);
	cout << ans << endl;
	
	return 0;
}
