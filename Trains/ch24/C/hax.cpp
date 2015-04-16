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
#include <assert.h>
typedef long double ld;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const ld eps = 1e-10;
const ld eps2 = 1e-10;
ld a[111], b[111];
int was[111], IT = 0;
int pr[111];

bool kuhn(int x, vector< vector<int> >& g) {
	if (was[x] == IT) return false;
	was[x] = IT;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (pr[y] == -1 || kuhn(pr[y], g)) {
			pr[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
    freopen("10.in", "r", stdin);
    freopen("C10.out", "w", stdout);

    int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		assert(n <= 100);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		swap(a[n - 1], a[1]);
		swap(a[n / 2], a[2]);
//		random_shuffle(a, a + n);

		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}

		bool ans = 0;
		for (int i = 0; i < n && !ans; ++i)
		for (int j = 0; j < n && !ans; ++j) if (i != j)
		for (int k = 0; k < n; ++k) if (k != i && k != j) {
			// a[0] b[i]   a[1] b[j]    a[2] b[k]

			ld A1 = a[1] - a[0];
			ld B1 = b[j] - b[i];
			ld C1 = -A1 * (a[0] + a[1]) / 2 - B1 * (b[i] + b[j]) / 2;


			ld A2 = a[2] - a[0];
			ld B2 = b[k] - b[i];
			ld C2 = -A2 * (a[0] + a[2]) / 2 - B2 * (b[i] + b[k]) / 2;

			ld d = A1 * B2 - A2 * B1;
			ld dx = -C1 * B2 + B1 * C2;
			ld dy = -A1 * C2 + A2 * C1;

			ld cx, cy;
			if (fabs(d) < eps) {
				cx = a[0];
				cy = b[i];
			} else {
				cx = dx / d;
				cy = dy / d;
			}
			ld rr = sqr(cx - a[0]) + sqr(cy - b[i]);

//			if (fabs(rr) < eps) continue;

/*
			if (fabs(sqr(cx - a[1]) + sqr(cy - b[j]) - rr) > eps) {
				cerr << i << " " << j << " " << k << " " << double(fabs(sqr(cx - a[1]) + sqr(cy - b[j]) - rr)) << endl;
				assert(0);
			}
			if (fabs(sqr(cx - a[2]) + sqr(cy - b[k]) - rr) > eps) {
				cerr << i << " " << j << " " << k << " " << double(fabs(sqr(cx - a[2]) + sqr(cy - b[k]) - rr)) << endl;
				assert(0);
			}
*/
			++IT;
			bool ok = true;
			vector< vector<int> > g(n);
			for (int it = 0; it < n; ++it) {
				for (int it2 = 0; it2 < n; ++it2) 
					if (fabs(sqr(cx - a[it]) + sqr(cy - b[it2]) - rr) < eps2) {
						g[it].push_back(it2);
					}
				if (g[it].size() == 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				for (int it = 0; it < n; ++it) pr[it] = -1;
				for (int it = 0; it < n; ++it) {
					++IT;
					if (!kuhn(it, g)) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				ans = 1;
				break;
			}
		}
		puts(ans ? "YES" : "NO");
	}
    
    return 0;
}
