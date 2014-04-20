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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

struct Tp {
	int l, r, p;
	bool operator<(const Tp& t) const {
		return p < t.p || (p == t.p && r < t.r);
	}
};

int solve(Tp* a, int n) {
	static int f[N];
	for (int i = 0; i < n; ++i) {
		f[i] = 1;
		int p = upper_bound(a, a + i, (Tp){-1, a[i].l, a[i].p}) - a;
		if (p > 0)
			f[i] = max(f[i], f[p - 1] + 1);
		if (i > 0)
			f[i] = max(f[i - 1], f[i]);
	}
	return f[n - 1];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T--) {
		static Tp a[N];
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].p);
		}
		int ans = 0;
		sort(a, a + n);
		for (int i = 0, j; i < n; i = j) {
			j = i + 1;
			while (j < n && a[j].p == a[i].p) ++j;
			ans += solve(a + i, j - i);
		}
		printf("%d\n", ans);
	}
	cerr << clock() << endl;
    
    return 0;
}
                              