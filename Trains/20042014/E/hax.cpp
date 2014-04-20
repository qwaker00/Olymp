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

struct Tp {
    int t;
    char c;
    double p;

    bool operator<(const Tp& T) const {
        return t < T.t;
    }
} a[111111];

LD mypow(LD x, int y) {
    LD res = 1;
    while (y) {
        if (y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i= 0; i < n; ++i) {
        scanf("%d %c %lf", &a[i].t, &a[i].c, &a[i].p);
    }
//    sort(a, a + n);

    LD ptl = 1, ptr = 0;
    LD ans = 0;
    for (int i = 0; i < n; ++i) {
        LD pl = (mypow(LD(1) - 2 * a[i].p, a[i].t) + 1) / 2;
        LD pr = LD(1) - pl;
        if (a[i].c == 'R') swap(pl, pr);
        ans += ptl * pl + ptr * pr;
        ptl = pr;
        ptr = pl;
    }
    cout.precision(12);
    cout << fixed << ans << endl;

    return 0;
}
