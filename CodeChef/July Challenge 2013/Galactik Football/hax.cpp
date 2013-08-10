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

int n, m;

inline void getx(int& x) {
    char c;
    while ((c = getchar()) < '-');
    if (c == '-') {
        x = getchar() - 48;
        while ((c = getchar()) >= '0') x = x * 10 + c - 48;
        x = -x;
        return;
    }
    x = c - 48;
    while ((c = getchar()) >= '0') x = x * 10 + c - 48;
}

int pr[111111], cost[111111], vn, v[111111];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

bool ByCost(int x, int y) {
    return cost[x] < cost[y];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    scanf("%d%d", &n, &m);

    memset(cost, 127, sizeof(cost));
    for (int i = 1; i <= n; ++i) pr[i] = i;

    for (int i = 0; i < m; ++i) {
        int x, y;
//        getx(x); getx(y);
        scanf("%d%d", &x, &y);

        pr[fs(x)] = fs(y);
    }
    for (int i = 1; i <= n; ++i) {
        int c;
        int x = fs(i);

        scanf("%d", &c);
        if (c >= 0) cost[x] = min(c, cost[x]);
    }

    for (int i = 1; i <= n; ++i) if (fs(i) == i) {
        v[vn++] = i;
    }
    if (vn == 1) {
        cout << 0 << endl;
        return 0;
    }
    sort(v, v + vn, ByCost);

    LL ans = 0;
    for (int i = 1; i < vn; ++i) {
        if (cost[v[i]] > 1e9) {
            cout << -1 << endl;
            return 0;
        }
        ans += cost[v[0]] + cost[v[i]];
    }
    cout << ans << endl;

    return 0;
}
