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

#define N 22
#define MOD 1000000007

int ed[66666];
int x[N], y[N], n, nn, T;
int good[66666], f[66666], fc[66666], gn = 0, g[66666];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	ed[0] = 0;
	for (int i = 1; i < 65536; ++i) ed[i] = ed[i & (i - 1)] + 1;

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

		nn = 1 << n;
		gn = 0;
		for (int i = 1; i < nn; ++i) {
			good[i] = true;
			if (ed[i] < 3) {
				g[gn++] = i;
				continue;
			}

			int state = 0, a, b, c;
			for (int j = 0; j < n; j++) if (i & (1 << j)) {
				if (state == 0) {
					state = 1;
					a = y[j];
					b = -x[j];
				} else
				if (state == 1) {
					a -= y[j];
					b += x[j];
					c = - a * x[j] - b * y[j];
					state = 2;
				} else {
					if (a * x[j] + b * y[j] + c != 0) {
						good[i] = false;
						break;
					}
				}
			}
			if (good[i]) g[gn++] = i;
		}
//		cerr << "Good " << gn << endl;

		memset(f, 63, sizeof(f));
		f[0] = 0;
		fc[0] = 1;
		for (int i = 1; i < nn; ++i) {
			if (good[i]) {
				f[i] = 1;
				fc[i] = 1;
				continue;
			}

			if ((1 << ed[i]) > gn) {
				for (int j = 0; j < gn; ++j) {
					if ( (g[j] | i) != i) continue;
					if (f[i ^ g[j]] + 1 < f[i]) {
						f[i] = f[i ^ g[j]] + 1;
						fc[i] = fc[i ^ g[j]];
					} else
					if (f[i ^ g[j]] + 1 == f[i]) {
						fc[i] = (fc[i] + fc[i ^ g[j]]) % MOD;
					}
				}
			} else {
				for (int j = (i - 1) & i; j; j = (j - 1) & i) {
					if (!good[j]) continue;
					if (f[i ^ j] + 1 < f[i]) {
						f[i] = f[i ^ j] + 1;
						fc[i] = fc[i ^ j];
					} else
					if (f[i ^ j] + 1 == f[i]) {
						fc[i] = (fc[i] + fc[i ^ j]) % MOD;
					}
				}
			}
		}
		cout << f[nn - 1] << " " << fc[nn - 1] << endl;
//		cerr << clock() << endl;
	}

	return 0;
}
