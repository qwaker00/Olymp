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

LL s;
char _sc; int _sd;
int n;

struct Tp {
    LL x, y;
} a[111111];
LL ansx, ansy;

LL gcd(LL a, LL b, LL& x, LL& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL x1, y1;
	LL d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
 
bool find_any_solution (LL a, LL b, LL c, LL& x0, LL& y0) {
	LL g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

LL divup(LL d1, LL d2) {
    LL r = d1 / d2;
    if ((r - 1) * d2 >= d1)
        return r - 1;
    if (r * d2 >= d1)
        return r;
    return r + 1;
}

LL divdown(LL d1, LL d2) {
    LL r = d1 / d2;
    if ((r + 1) * d2 <= d1)
        return r - 1;
    if (r * d2 <= d1)
        return r;
    return r - 1;
}

bool solve(Tp& p1, Tp& p2, LL s,
           LL A1, LL B1, LL C1,
           LL A2, LL B2, LL C2
           )
{
    LL x0, y0, tMax = 1e18, tMin = -1e18;
    LL n = p1.y - p2.y;
    LL m = p2.x - p1.x;
    LL k = p2.x * p1.y - p2.y * p1.x - s;
    if (find_any_solution(m, n, k, x0, y0)) {
        LL d1 = A1 * x0 + B1 * y0 + C1;
        LL d2 = B1 * m - A1 * n;
        if (d2 < 0) tMin = max(tMin, divup(d1, d2)); else tMax = min(tMax, divdown(d1, d2));

        d1 = A2 * x0 + B2 * y0 + C2;
        d2 = B2 * m - A2 * n;
        if (d2 >= 0) tMin = max(tMin, divup(d1, d2)); else tMax = min(tMax, divdown(d1, d2));

        const int B = 1000000;
        d1 = -B - x0;
        d2 = n;
        if (d2 >= 0) tMin = max(tMin, divup(d1, d2)); else tMax = min(tMax, divdown(d1, d2));
        d1 = -B + x0;
        d2 = n;
        if (d2 >= 0) tMin = max(tMin, divup(d1, d2)); else tMax = min(tMax, divdown(d1, d2));

        d1 = -B - y0;
        d2 = -m;
        if (d2 >= 0) tMin = max(tMin, divup(d1, d2)); else tMax = min(tMax, divdown(d1, d2));
        d1 = -B + y0;
        d2 = -m;
        if (d2 >= 0) tMin = max(tMin, divup(d1, d2)); else tMax = min(tMax, divdown(d1, d2));

        if (tMin <= tMax) {
            ansx = x0 + tMin * n;
            ansy = y0 - tMin * m;
            return true;
        }
    }
    return false;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    cin >> n >> s >> _sc >> _sd;
    --n;
    s = s + s + _sd * 2 / 10;

    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].x = x;
        a[i].y = y;
    }
    a[n] = a[0];

    LL s0 = 0;
    for (int i = 0; i < n; ++i) {
        s0 += (a[i].x - a[i - 1].x) * (a[i].y + a[i - 1].y);
    }    
    s0 = abs(s0);

    cerr << "s: " << s << " " << s0 << endl;

    for (int i = 1; i < n; ++i) {
        Tp& pr = a[(i + n - 1) % n];
        Tp& nx = a[(i + 2) % n];
        if (solve(a[i], a[i + 1], s - s0,
                  nx.y - a[i + 1].y, a[i + 1].x - nx.x, -a[i + 1].x * (nx.y - a[i + 1].y) - a[i + 1].y * (a[i + 1].x - nx.x),
                  pr.y - a[i].y, a[i].x - pr.x, -a[i].x * (pr.y - a[i].y) - a[i].y * (a[i].x - pr.x)
                 )
           )
        {
            cout << ansx << " " << ansy << endl;
            return 0;
        }
    }

    return 0;
}
