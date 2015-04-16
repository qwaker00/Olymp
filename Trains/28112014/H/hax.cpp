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
int was[155555], IT = 0;

bool bydiff(const tp& a, const tp& b) {
	return a.x - a.y > b.x - b.y;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		sort(a, a + n, bydiff);
		int left = 0;
		int right = 1e6 + 1;
		while (left < right) {
			int center = (left + right + 1) / 2;
			
			++IT;
			int prof = center;
			for (int it = 0; it <= k; ++it) {
				int minp = -1;
				for (int i = 0; i < n && a[i].x - a[i].y >= prof; ++i) {
					if (was[i] == IT) continue;
					if (minp == -1 || a[i].y <= a[minp].y) {
						minp = i;
					}
				}
				if (minp != -1) {
					was[minp] = IT;
					prof += a[minp].y;
				} else {
					prof = 1e9;
					break;
				}
			}
			if (prof == 1e9) right = center - 1;else left = center;
		}
		printf("%d\n", left);
	}

    return 0;
}
