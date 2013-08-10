#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


struct TPlan {
    LL r, a, m;
    TPlan(LL rate, LL abon, LL month) : r(rate), a(abon), m(month) { }

    bool Better(const TPlan& p, LL minutes) {
        LL mm = m / __gcd(p.m, m) * p.m;
        LL c1 = mm * minutes * r + mm / m * a;
        LL c2 = mm * minutes * p.r + mm / p.m * p.a;
        return c1 < c2;
    }
};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        double r0;
        int n, m;
        cin >> r0 >> m >> n;

        int found = -1;
        TPlan best(r0 * 100 + 1e-8, 0, 1);
        for (int i = 0; i < n; ++i) {
            LL mon, abon;
            double rat;
            cin >> mon >> rat >> abon;
            TPlan p(rat * 100 + 1e-8, abon * 100, mon);
            if (p.Better(best, m)) {
                best = p;
                found = i;
            }
        }
        printf("%d\n", found + 1);
    }
    
    return 0;
}
