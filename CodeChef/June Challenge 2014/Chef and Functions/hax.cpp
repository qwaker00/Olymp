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

const int MOD = 1000000007;

LL p[11][66];

pair<LL, double> mypow(LL x, int y) {
    if (y == 1) return make_pair(x, x);
    pair<LL, double> t = mypow(x, y >> 1);
    if (y & 1)
        return make_pair(t.first * t.first * x, t.second * t.second * x);
    return make_pair(t.first * t.first, t.second * t.second);
}

LL mypowcache(LL x, int y) {
    if (x <= 9) return p[x][y];
    pair<LL, double> t = mypow(x, y);
    if (t.second > 2e18) return 2e18;
    return t.first;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    for (int x = 2; x <= 9; ++x) {
        p[x][0] = 1;
        for (int i = 1; p[x][i - 1] <= 1e18 + 1000; ++i) {
            p[x][i] = p[x][i - 1] * x;
        }
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        LL preans = 0;
        int a[66];

        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            if (i >= 60) preans += x;else {
                a[i] = (x + MOD) % MOD;
            }
        }
        preans = (preans % MOD + MOD) % MOD;

        while (q--) {
            LL x;
            scanf("%lld", &x);

            LL ans = (preans + (x % MOD) * a[1]) % MOD;
            LL rr = sqrt(x) * 2;
            int cnt = 0;
            for (int i = 2; i < 60 && i <= n; ++i) {
                LL left = 1;
                LL right = rr;
                while (left < right) {
                    LL center = (left + right + 1) / 2;
                    LL t = mypowcache(center, i);
                    if (t > x) {
                        right = center - 1;
                    } else {
                        left = center;
                    }
                }
                rr = left;

                ans = (ans + left * a[i]) % MOD;
            }

            printf("%d ", (int)ans);
        }
        puts("");
    }
//    cerr << clock() << endl;
    
    return 0;
}
