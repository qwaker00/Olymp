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


int x[1111], y[1111], z[1111], n;
char ans[1111];

inline LL det(LL b1, LL b2, LL b3, LL b4, LL b5, LL b6, LL b7, LL b8, LL b9) {
    return b1 * b5 * b9 + b2 * b6 * b7 + b3 * b4 * b8 - b3 * b5 * b7 - b1 * b6 * b8 - b2 * b4 * b9;
}

bool good(int i1, int i2, int i3, int& gr) {
    int v1x = x[i2] - x[i1];
    int v1y = y[i2] - y[i1];
    int v1z = z[i2] - z[i1];

    int v2x = x[i3] - x[i1];
    int v2y = y[i3] - y[i1];
    int v2z = z[i3] - z[i1];

    if (v1x * v2y == v2x * v1y &&
        v1x * v2z == v2x * v1z &&
        v1z * v2y == v2z * v1y
    ) return false;

    ++gr;
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; ++i) if (i != i1 && i != i2 && i != i3)
    {
        LL d = det(v1x, v1y, v1z,
                   v2x, v2y, v2z,
                   x[i] - x[i1], y[i] - y[i1], z[i] - z[i1]
                  );
        if (d <= 0) t1++;
        if (d >= 0) t2++;        
    }
    return (t1 == n - 3 || t2 == n - 3);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i] >> z[i];
            ans[i] = 'F';
        }
        int gr = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k) {
                    if (good(i, j, k, gr)) {
                        ans[i] = ans[j] = ans[k] = 'T';
                    }
                }
        if (gr == 0) {
            for (int i = 0; i < n; ++i) ans[i] = 'T';
        }
        ans[n] = 0;
        puts(ans);
    }    
    
    return 0;
}
