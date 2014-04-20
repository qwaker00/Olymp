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

const int MOD = 1000000009;
const int N = 111111;
const int M = 111;

int a[N], c[M];
LL to[M], rev[N], f[2][M];

LL powmod(LL x, LL y) {
    LL res = 1;
    while (y) {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 1; i <= 100000; ++i) rev[i] = powmod(i, MOD - 2);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        while (q--) {
            int m;
            scanf("%d", &m);
            memset(c, 0, sizeof(c[0]) * m);

            for (int i = 0; i < n; ++i) {
                ++c[((a[i] % m) + m) % m];
            }

            memset(f[0], 0, sizeof(f[0][0]) * m);
            f[0][0] = 1;
            for (int i = 0; i < m; ++i) {
                memset(to, 0, sizeof(to[0]) * m);
                LL Cij = 1;
                for (int j = 0; j <= c[i]; ++j) {
                    to[(i * j) % m] += Cij;
                    Cij = (Cij * (c[i] - j)) % MOD;
                    Cij = (Cij * rev[j + 1]) % MOD;
                }
                for (int j = 0; j < m; ++j) to[j] %= MOD;

                LL* fr = f[i & 1];
                LL* fw = f[1 - (i & 1)];
                memset(fw, 0, sizeof(fw[0]) * m);
                for (int j = 0; j < m; ++j) {
                    fw[j] = 0;
                    for (int k = 0; k < m; ++k) {
                        fw[j] = (fw[j] + fr[(j - k + m) % m] * to[k]) % MOD;
                    }
                }
            }

            printf("%d\n", (int)f[m & 1][0]);
        }
    }

    return 0;
}
