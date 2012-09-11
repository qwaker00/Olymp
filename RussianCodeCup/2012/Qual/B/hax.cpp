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
#define M 411111

int mc, dc, cc, cnt;
int timein[N], f[N], timer = 0;
int xx[N], yy[M], pp[M], kk = 0;
int was[N], n, m, x, y, si[N], w[N];
int mmc[M];

void dfs(int x, int pr) {
	if (was[x]) return;
	was[x] = true;

	timein[x] = ++timer;
	f[x] = timer;
	cnt++;
	w[x] = 1;

	for (int i = xx[x]; i; i = pp[i]) {
		int y = yy[i];
		if (y == pr) continue;

		if (was[y]) {
			f[x] = min(f[x], timein[y]);
		} else {
			dc++;
			dfs(y, x);
			w[x] += w[y];
			f[x] = min(f[x], f[y]);
			if (f[y] > timein[x]) {
				mmc[mc++] = w[y];
			}
		}
	}
}


int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;
		yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk;
	}

	for (int i = 1; i <= n; ++i) if (!was[i]) {
		cnt = 0;
		dfs(i, -1);
		si[cc++] = cnt;
	}

	if (cc > 2) {
		puts("0");
	} else
	if (cc == 2) {
		cout << (LL(m - mc) * LL(si[0]) * LL(si[1])) << endl;
	} else {
		LL ans = LL(m - mc) * ( (LL(n) * LL(n - 1)) / 2 - m);
		for (int i = 0; i < mc; i++)
			ans += LL(mmc[i]) * LL(n - mmc[i]) - 1;
		cout << ans << endl;
	}
	

	return 0;
}
