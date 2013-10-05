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

#define N 555

char s[N][N];
int l[N][N], u[N][N], r[N][N], d[N][N];
int pr[555], prn = 0;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    for (int i = 2; i < 500; ++i) {
        int j = 0;
        for (; j < prn; ++j)
            if (i % pr[j] == 0)
                break;
        if (j == prn) {
            pr[prn++] = i;
        }
    }

    int T;
    scanf("%d\n", &T);
    while (T--) {
        int n, m, ans = 0;
        scanf("%d%d\n", &n, &m);
        for (int i = 0; i < n; ++i) gets(s[i]);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '^') {
                    if (i == 0) u[i][j] = 0;else u[i][j] = u[i - 1][j] + 1;
                    if (j == 0) l[i][j] = 0;else l[i][j] = l[i][j - 1] + 1;
                } else
                    u[i][j] = l[i][j] = -1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (s[i][j] == '^') {
                    if (i == n - 1) d[i][j] = 0;else d[i][j] = d[i + 1][j] + 1;
                    if (j == m - 1) r[i][j] = 0;else r[i][j] = r[i][j + 1] + 1;

                    int t = min(min(r[i][j], l[i][j]), min(d[i][j], u[i][j]));
                    ans += lower_bound(pr, pr + prn, t + 1) - pr;
                } else
                    d[i][j] = r[i][j] = -1;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
