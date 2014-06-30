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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 100111;

LL c[N], h[N];

LL gcd_ex(LL a, LL b, LL & x, LL & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL x1, y1;
	LL d = gcd_ex(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, m, k;
    LL C, H;
    cin >> n >> m >> C >> H >> k;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> h[i];
    }

    LL g, _x0, _y0;
    g = gcd_ex(C, H, _x0, _y0);

    LL dx = -H / g;
    LL dy = C / g;

    set<LL> ss;
    for (int i = 0; i < n; ++i) {
        ss.insert((c[i] - _x0) * dy);
    }
    set<LL> sss;
    for (int i = 0; i < m; ++i) {
        LL target = (h[i] - _y0) * dx;
        if (ss.find(target) != ss.end()) {
            sss.insert( h[i] % dy );
        }
    }

    while (k--) {
        LL p, q;
        cin >> p >> q;

        if (p > H * q || p < C * q) {
            cout << "NO\n";
            continue;            
        }

        LL A = p - q * C;
        LL B = q * H - p;

        LL g = gcd(A, B);
        A /= g;
        B /= g;
    }
    
    return 0;
}
