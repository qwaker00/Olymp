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

int a[111];
double MEM[111][111];
bool MEM2[111][111];
int was[111][111];

bool calc2(int* a, int n, int g, int steps) {
    if (g == 1) return 1;
    if (steps == n) return 0;

    if (was[g][steps])
        return MEM2[g][steps];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int gg = __gcd(g, a[i]);
        if (gg == g) ++cnt;
    } 
         
    bool ok = false;
    if (steps < cnt && !calc2(a, n, g, steps + 1)) {
        ok = true;
    }

    if (!ok) {
        for (int i = 0; i < n; ++i) {
            int gg = __gcd(g, a[i]);
            if (gg != g && !calc2(a, n, gg, steps + 1)) {
                ok = true;
                break;
            }
        }
    }
    was[g][steps] = 1;
    MEM2[g][steps] = ok;
    return ok;
}


double calc(int* a, int n, int g, int steps) {
    if (g == 1) return 1;
    if (steps == n) return 0;

    if (was[g][steps])
        return MEM[g][steps];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int gg = __gcd(g, a[i]);
        if (gg == g) ++cnt;
    } 

    double res = 0;
    if (steps < cnt)
        res += (1 - calc(a, n, g, steps + 1)) * (cnt - steps);

    for (int i = 0; i < n; ++i) {
        int gg = __gcd(g, a[i]);
        if (gg != g) {
            res += 1 - calc(a, n, gg, steps + 1);
        }
    } 

    res /= n - steps;

    was[g][steps] = 1;
    MEM[g][steps] = res;
    return res;
}

int main() {
   // freopen(".in", "r", stdin);
   // freopen(".out", "w", stdout);
    
    int T;
    cin >> T;    
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        memset(was, 0, sizeof(was));
        int ok = 0;
        for (int i = 0; i < n; ++i)
            if (!calc2(a, n, a[i], 1)) {
                ok = 1;
                break;
            }

        memset(was, 0, sizeof(was));
        double ok2 = 0;
        for (int i = 0; i < n; ++i)
            ok2 += 1 - calc(a, n, a[i], 1);
        ok2 /= n;

        printf("%d %.4lf\n", ok, ok2);
    }
    
    return 0;
}
