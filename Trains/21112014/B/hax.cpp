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

struct Tp {
	LL x, y, z;
	Tp() {}
	Tp(LL x, LL y) : x(x), y(y), z(y > 0 || (y == 0 && x > 0)) {};
	LL sq() const {
		return x * x + y * y;
	}
} a[1111], b[2111];

LD iround(LD x) {
    LL ansl = x * 1e8 + 1e-7;
    if (ansl % 10 >= 5) {
    	return ((ansl / 10) + 1) / 1e7;
    } else {
    	return (ansl / 10) / 1e7;
    }
}

LL mul(const Tp& a, const Tp& b) {
	return a.x * b.y - a.y * b.x;
}

bool cmp(const Tp& a, const Tp& b) {
	if (a.z != b.z) return a.z < b.z;
	int t = mul(a, b);
	if (t == 0) {
//		if (a.z > 0)
			return a.sq() > b.sq();
//		else
//			return a.sq() > b.sq();
	}
	return t < 0;
}

bool right(const Tp& a, const Tp& b) {
	int t = mul(a, b);
	if (t == 0)
		return cmp(a, b);
	return t < 0;
//	return t < 0 || (t == 0 && a.z == b.z);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	cout.precision(7);
	cout << fixed;

    int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].x = x;
			a[i].y = y;
		}
		LL ans = 0;
		for (int it = 0; it < n; ++it) {
			LL SX = 0, SY = 0;
			int l = 0;
			for (int j = 0; j < n; ++j) if (j != it) {
				b[l] = Tp(a[j].x - a[it].x, a[j].y - a[it].y);
				SX += b[l].x;
				SY += b[l].y;
				++l;
			}
			sort(b, b + l, cmp);
			memcpy(b + l, b, sizeof(b[0]) * l);
			
//			for (int i = 0; i < l; ++i) {
//				cerr << b[i].x << " " << b[i].y << endl;			
//			}

			LL sumx = 0;
			LL sumy = 0;
			for (int i = 0, j = 0; i < l; ++i) {
				while (j < i + l && (j <= i || right(b[i], b[j]))) {
					sumx += b[j].x;
					sumy += b[j].y;
					++j;
				}
				sumx -= b[i].x;
				sumy -= b[i].y;

				LL preans = 0;
				preans -= b[i].x * sumy - b[i].y * sumx;
				preans += b[i].x * (SY - sumy) - b[i].y * (SX - sumx);
//				cerr << preans << endl;

//				LL ans1 = 0;
//				for (int k =0; k < l; ++k) if (k != i) {
//					ans1 += abs(mul(b[i], b[k]));
//				}
//				cerr << i << " " << j << ": " << ans1 << " " << preans << endl;
//				assert(ans1 == preans);

				ans += preans;
			}
//			cerr << endl;
		}
//		cerr << "ans " << ans << endl;

		if (n < 3) {
			cout << 0. << "\n";
//			printf("%.7f\n", 0.);
		} else {
			LD ansd = (LL(n) * (n - 1) * (n - 2)) / 6;
			LD S = ans / ansd;
			LD res = S / 12 * (n / 3);
			cout << double(iround(res)) << "\n";
//			printf("%.7f\n", double(iround(res)));
		}
	}

    return 0;
}
