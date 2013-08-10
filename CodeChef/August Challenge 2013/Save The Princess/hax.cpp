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
                
const int SH = 11111;
LD f[111][22222];
int a[111], p[111];
LD P[111], Q[111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int T;
    cin >> T;
    cout.precision(12);
    cout << fixed;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            P[i] = LD(p[i]) / 100;
            Q[i] = LD(100 - p[i]) / 100;
        }

        memset(f, 0, sizeof(f));
        int s = 0;
        f[0][0 + SH] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = SH - s; j <= SH + s; ++j) if (f[i][j]) {
                f[i + 1][j + a[i]] += f[i][j] * P[i];
                f[i + 1][j - a[i]] += f[i][j] * Q[i];
            }
            s += a[i];
        }
        LD ans = 0;
        for (int i = 0; i <= s; ++i) ans += f[n][SH + i];
        cout << ans << endl;
    }
    cerr << clock() << endl;
    return 0;
}
