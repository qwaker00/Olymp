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

struct tp {
	int x, y;
} a[155555];

bool bydiff(const tp& a, const tp& b) {
	return a.x - a.y > b.x - b.y;
}
bool byX(const tp& a, const tp& b) {
	return a.x < b.x;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		sort(a, a + n, byX);
		int left = 0;
		int right = 1e6 + 1;
		while (left < right) {
			int center = (left + right + 1) / 2;			

			//cerr << center << endl;
			vector<LL> f1(n), f2;
			for (int i = 0; i < n; ++i) f1[i] = a[i].y;
			for (int it = 1; it <= k; ++it) {
				f2.assign(n, 1e18);
				LL mi = 1e18;
				for (int i = 0; i < n; ++i) {					
					if (i > 0 && f1[i - 1] + center <= a[i - 1].x) mi = min(mi, f1[i - 1]);
					f2[i] = mi + a[i].y;
				}
				f1.swap(f2);
			}
			bool fnd = 0;
			for (int i= 0; i < n; ++i) if (f1[i] + center <= a[i].x) {
				fnd = 1;
				break;
			}
			if (fnd) left = center;else right = center - 1;
		}
		printf("%d\n", left);
	}

    return 0;
}
