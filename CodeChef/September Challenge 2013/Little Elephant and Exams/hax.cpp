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

int a[22], b[22];
LD p[22], q[22];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int P;
            scanf("%d%d%d", &P, &a[i], &b[i]);
            a[i]--;
            b[i]--;
            p[i] = LD(P) / 100;
            q[i] = LD(100 - P) / 100;
        }
        if (n > 16) {
            puts("0.0");
            continue;
        }
        LD ans = 0;
        for (int msk = 0; msk < (1 << n); ++msk) {
            int was = 0, bad = 0;
            LD pr = 1;
            for (int j = 0; j < n; ++j)
                if (msk & (1 << j)) {
                    if (was & (1 << a[j])) {
                        bad = 1;
                        break;
                    }
                    was |= (1 << a[j]);
                    pr *= p[j];
                } else {
                    if (was & (1 << b[j])) {
                        bad = 1;
                        break;
                    }
                    was |= (1 << b[j]);
                    pr *= q[j];
                }
            if (bad) continue;
            ans += pr;
        }
        printf("%.15lf\n", double(ans));
    }
        
    return 0;
}
