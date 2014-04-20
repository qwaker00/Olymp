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

pair<LD, LD> a[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int p, r;
		scanf("%d%d", &p, &r);
		for (int i = 0; i < p; ++i) {
			int w, l, h;
			scanf("%d%d%d", &l, &w, &h);
			a[i] = make_pair(LD(h) / 2, LD(l) * w * h);
		}
		sort(a, a + p);
		const LD eps = 1e-8;
		LD rr = LD(r) * r * r;
		bool fail = false;
		for (int i = 0; i < p; ++i) {
			if (rr > LD(a[i].first) * a[i].first * a[i].first + eps) {
				rr = rr + 3*a[i].second/(4*PI);
			} else {
				fail = true;
				break;
			}
		}
		puts(fail ? "Fail" : "Success");
	}

	
    return 0;
}
