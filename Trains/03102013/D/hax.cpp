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
    int x, y, z;

    bool operator<(const Tp& b) const {
        return z > b.z;
    }
} a[111111];
int fr[111111], pr[111111];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, c, fn = 0;

        scanf("%d%d%d", &n, &m, &c);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
        }
        sort(a, a + m);
        for (int i = 1; i <= n; ++i) pr[i] = i;
        for (int i = 0; i < m; ++i) {
            int x = fs(a[i].x), y = fs(a[i].y);
            if (x != y) {
                pr[x] = y;
            } else {
                fr[fn++] = i;
            }
        }

        LL ans = 0;
        int needbuild = -1, change = 0;
        for (int i = 1; i <= n; ++i) if (pr[i] == i) ++needbuild;
        for (int i = fn - 1; i >= 0 && needbuild > 0; --i) {
            if (a[ fr[i] ].z > c) break;
            --needbuild;
            ++change;
            ans += a[ fr[i] ].z;
        }
        ans += LL(c) * needbuild;
        cout << needbuild << " " << change << " " << ans << endl;
    }    

    return 0;
}
