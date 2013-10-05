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

#define N 5555

struct Tp {
    int d, r, i;
} a[N];
int out[N];

LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".outans", "w", stdout);

    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        LL teams = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int y, m, d;
            scanf("%d/%d/%d %d", &y, &m, &d, &a[i].r);
            a[i].d = y * 10000 + m * 100 + d;
            a[i].r = -a[i].r;
            out[i] = 0;
        }
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k) {
                    if (a[i].r < a[j].r && a[i].d > a[k].d &&
                        a[j].r < a[k].r && a[k].d > a[j].d)
                        {
                            out[i]++;
                            out[j]++;
                            out[k]++;
                            teams++;

//                            cerr << k << " " << j << " " << i << endl;
                        }
                }
//        cerr << teams << endl;
        if (teams == 0) {
            puts("Rules Should Be Changed!");
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (out[i] == 0) printf("0/1");else {
                LL g = gcd(teams, out[i]);
                printf("%I64d/%I64d", out[i] / g, teams / g);
            }
            if (i + 1 < n) putchar(' ');
        }
        puts("");
    }

    return 0;
}
