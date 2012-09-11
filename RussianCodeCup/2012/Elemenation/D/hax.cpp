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

#define N 22222

int S, T, n, a[N], f[222][N], g[222][N], ans = 0;


bool Check(int s, int noi) {
	if (s < 0) return false;
	if (s == 0) return true;
	if (s >= 22000) throw 666;
	if (f[noi][s] || g[noi + 1][s]) return true;
	for (int i = 0; i <= s; i++)
		if (f[noi][i] && g[noi + 1][s - i]) return true;
	return false;
}


int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> S >> T >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	f[0][0] = true;
	for (int i = 0; i < n; i++) {
		memcpy(f[i + 1], f[i], sizeof(f[i]));
		for (int j = a[i]; j <= 22000; j++) {
			f[i + 1][j] |= f[i + 1][j - a[i]];
		}
	}

	g[n][0] = true;
	for (int i = n - 1; i >= 0; i--) {
		memcpy(g[i], g[i + 1], sizeof(g[i]));
		for (int j = a[i]; j <= 22000; j++) {
			g[i][j] |= g[i][j - a[i]];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {
			if ( abs(T - S) % (a[i] - a[j]) == 0) {
				int k = (T - S) / (a[i] - a[j]);
				if (k < 0) continue;
				ans += Check(T - k * a[i], j);
//				if (Check(T - k * a[i], i)) cerr << i << " " << j << endl;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
