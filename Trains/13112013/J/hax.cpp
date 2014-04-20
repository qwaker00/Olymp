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
    int s, d;
    int p;

    bool operator<(const Tp& b) const {
        return s > b.s || (s == b.s && s + d < b.s + b.d);
    }
} a[5555];
int f[5555], g[5555];
int n;

inline void maximize(int& x ,int y) {
    if (x < y) x = y;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i].s, &a[i].d, &a[i].p);
    }
    sort(a, a + n);
    int ans = 0;
//    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        f[i] = a[i].p;
        for (int j = 0; j < i; ++j)
            if (a[j].s + a[j].d <= a[i].s + a[i].d) {
//                ++cnt;
                maximize(f[i], a[i].p + g[j]);
            }
        g[i] = f[i];
        for (int j = i - 1; j >= 0; --j)
            if (a[j].s >= a[i].s + a[i].d) {
//                ++cnt;
                maximize(g[j], f[j] + f[i]);
            }
        cerr << a[i].s << " " << a[i].d << " - " << f[i] << " " << g[i] << endl;
    }
    for (int i = 0; i < n; ++i) if (g[i] > ans) {
        ans = g[i];
        cerr << a[i].s << " " << a[i].d << endl;
    }
//    cerr << cnt << endl;
    cout << ans << endl;
    cerr << clock() << endl;
    
    return 0;
}
