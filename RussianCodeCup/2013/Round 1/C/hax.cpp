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

int a[111], b[111], va[111], vb[111];
LL f[111][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int an = 0, bn = 0;
        while (n > 0) {
            a[an++] = n & 1;
            va[an - 1] = n;
            n >>= 1;
        }
        va[an] = 0;

        while (m > 0) {
            b[bn++] = m & 1;
            vb[bn - 1] = m;
            m >>= 1;
        }
        vb[bn] = 0;

        for (int i = 0; i < an; ++i) {
            for (int j = 0; j < bn; ++j) {
                if (i == 0 && j == 0) {f[i][j] = 0; continue; }
                LL& ff = f[i][j] = 1e18;
                if (i > 0 && a[i - 1] == 0) ff = min(ff, f[i - 1][j]);
                if (j > 0 && b[j - 1] == 0) ff = min(ff, f[i][j - 1]);
                if (i > 0 && a[i - 1] == 1) ff = min(ff, f[i - 1][j] + vb[j]);
                if (j > 0 && b[j - 1] == 1) ff = min(ff, f[i][j - 1] + va[i]);
            }
        }
        cout << f[an - 1][bn - 1] << endl;
    }
     
    return 0;
}
