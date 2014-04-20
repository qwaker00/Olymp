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

#define N 211111

int f[N][2];
int p[N][2];
int c[N], cc[N][2][2];
char anss[N];
char CH[] = {'F', 'B'};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);    
    while (T--) {
        int n, t;
        scanf("%d%d", &n, &t);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d%d", &c[i], &cc[i][1][0], &cc[i][1][1], &cc[i][0][0], &cc[i][0][1]);
        }
        int ans = t + 1;
        for (int frs = 0; frs < 2; ++frs) {
            memset(f, 63, sizeof(f));
            f[0][frs] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) if (f[i][j] < ans) {
                    for (int k = 0; k < 2; ++k) {
                        if (f[i + 1][k] > f[i][j] + cc[i][j][k] + c[i]) {
                            f[i + 1][k] = f[i][j] + cc[i][j][k] + c[i];
                            p[i + 1][k] = j;
                        }
                    }
                }
            }
            if (f[n][frs] < ans) {
                ans = f[n][frs];
                int way = frs;
                for (int j = n; j > 0; --j) {
                    anss[j - 1] = CH[ p[j][way] ];
                    way = p[j][way];
                }
                anss[n] = 0;
            }
        }
        if (ans <= t) {
            puts(anss);
        } else {
            puts("IMPOSSIBLE");
        }
    }
    
    return 0;
}
