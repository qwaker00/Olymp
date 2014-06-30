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

LL solve(int* cnt, int m) {
    LL f[41][41];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j <= i; ++j) {
            f[i + 1][j] += f[i][j];
            f[i + 1][j + 1] += f[i][j] * ((1ll << cnt[i + 1]) - 1);
        }
    }
    LL ans = 0;
    for (int j = m; j <= 40; ++j)
        ans += f[40][j];
    return ans;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, c[41], p[41], cnt[41] = {0};

        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &c[i], &p[i]);
            ++cnt[c[i]];
        }

        LL total = solve(cnt, m);

        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = cnt[c[i]];
            cnt[c[i]] = 0;
            LL vars = solve(cnt, m - 1);
            cnt[c[i]] = t;
            vars *= (1ll << (cnt[c[i]] - 1));
            ans += vars * p[i];
        }
        printf("%.12lf\n", (double)ans / total);
    }    
    
    return 0;
}
