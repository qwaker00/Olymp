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

#define N 2111

struct Tp {
    int x, y;
} a[N];
int h[N], hn = 0, IT;
int was[N];
int pr[N];
vector<int> g[N];

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (int i = 0; i < g[x].size(); ++i) {
        if (pr[ g[x][i] ] == -1 || kuhn(pr[ g[x][i] ])) {
            pr[ g[x][i] ] = x;
            return true;
        }
    }
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        hn = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
            h[hn++] = a[i].x;
            h[hn++] = a[i].y;
        }
        sort(h, h + hn);
        hn = unique(h, h + hn) - h;

        for (int i = 0; i < hn; ++i) {
            pr[i] = -1;
            g[i].clear();
        }

        for (int i = 0; i < n; ++i) g[ lower_bound(h, h + hn, a[i].x) - h ].push_back(lower_bound(h, h + hn, a[i].y) - h);
        int ans = 0;
        for (int i = 0; i < hn; ++i) {
            ++IT;
            ans += kuhn(i);
        }
        printf("%d\n", ans);
    }
           
    return 0;
}
