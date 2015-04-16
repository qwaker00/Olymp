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

LL gcd(LL x, LL y) {
	LL z;
	while (y) {
		z = x % y;
		x = y;
		y = z;
	}
	return x;
}
LL f[18][111111];
int lg2[111111];

inline LL get(int l, int r) {
	int t = lg2[r - l + 1];
	return gcd(f[t][l], f[t][r - (1 << t) + 1]);
}

inline void maximize(LL& x, LL y) {
	if (y > x) x = y;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i <= 111111; ++i) lg2[i] = lg2[i >> 1] + 1;

    int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lld", &f[0][i]);
		for (int j = 1; (1 << j) <= n; ++j) {
			for (int i = 0; i + (1 << j) <= n; ++i) {
				f[j][i] = gcd(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
			}
		}
		LL ans = 0;
		for (int l = 0; l < n; ++l) {
			int r = l;
			while (r < n) {
//				cerr << l << " " << r << " -> ";
				LL g = get(l, r);
				int left = r;
				int right = n - 1;
				while (left < right) {
					int c = (right + left + 1) / 2;
					if (get(l, c) == g)
						left = c;
					else
						right = c - 1;
				}
				maximize(ans, get(l, left) * (left - l + 1));
//				cerr << l << " " << left << endl;
				r = l + 2 * (left - l + 1) - 1;
			}
		}
		printf("%lld\n", ans);
	}

    return 0;
}
