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

const int N = 111111;

struct Tp {
    int x, y;
} a[N];

LL gcd(LL x, LL y) {
    assert(x >= 0);
    assert(y >= 0);
    while (x && y) {
        if (x > y) x %= y;else y %= x;
    }
    return x + y;
}

LL rect(LL a, LL b) {
    assert(a >= 0);
    assert(b >= 0);
    return a * b;
}

LL segment(LL x, LL y, LL xx, LL yy) {
    LL dx = llabs(x - xx);
    LL dy = llabs(y - yy);
    return gcd(2 * dx, 2 * dy) - gcd(2 * dx, dy) - gcd(dx, 2 * dy) + gcd(dx, dy);
}

/*LL right_triangle_on(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {   
    assert(x1 == x2 && y1 == y3 || y1 == y2 && x1 == x3);

    LL dx = x1 == x2 ? x3 - x1 : x2 - x1;
    LL dy = y1 == y2 ? y3 - y1 : y2 - y1;
//    cerr << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << " = " << (rect(llabs(dx), llabs(dy)) + segment(x1, y1 + dy, x1 + dx, y1)) << endl;
    return (rect(llabs(dx), llabs(dy)) + segment(x1, y1 + dy, x1 + dx, y1)) / 2;
}
*/
LL right_triangle_on_2(LL dx, LL dy) {   
    return (rect(llabs(dx), llabs(dy)) + segment(0, dy, dx, 0)) / 2;
}

const LL INF = 9e18;

LL triangle_off_calc(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3, bool ss) {
    LL S = ss ? llabs( (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) ) : 0;
    LL ret = S + 2 - gcd(llabs(x1 - x2), llabs(y1 - y2)) - gcd(llabs(x1 - x3), llabs(y1 - y3)) - gcd(llabs(x3 - x2), llabs(y3 - y2));

//    cerr << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << " = " << ret << endl;

    return ret;
}
LL triangle_off(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
    return (triangle_off_calc(x1 * 2, y1 * 2, x2 * 2, y2 * 2, x3 * 2, y3 * 2, false)
           - triangle_off_calc(x1 * 2, y1, x2 * 2, y2, x3 * 2, y3, false)
           - triangle_off_calc(x1, y1 * 2, x2, y2 * 2, x3, y3 * 2, false)
           + triangle_off_calc(x1, y1, x2, y2, x3, y3, true)) / 2;
}


int main() {
    freopen("semi-cool.in", "r", stdin);
    freopen("semi-cool.out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }

    LL ans = segment(a[0].x, a[0].y, a[1].x, a[1].y);
    for (int i = 1; i + 1 < n; ++i) {
        ans += triangle_off(a[0].x, a[0].y, a[i].x, a[i].y, a[i + 1].x, a[i + 1].y);
        ans += segment(a[i].x, a[i].y, a[i + 1].x, a[i + 1].y);
        ans += segment(a[0].x, a[0].y, a[i + 1].x, a[i + 1].y);
    }
    cout << ans << endl;
    
    return 0;
}
