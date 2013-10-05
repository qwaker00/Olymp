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
#include <assert.h>

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
pair<int, int> b[N], c[N];
LL cnt[N], ccc[N], out[N];
int bc[N], h[N];

bool ByD(const Tp& A, const Tp& B) {
    return A.d < B.d;
}
LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, hn = 0;
        LL teams = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int y, m, d;
            scanf("%d/%d/%d %d", &y, &m, &d, &a[i].r);
            a[i].d = y * 10000 + m * 100 + d;
            a[i].r = -a[i].r;
            a[i].i = i;
            cnt[i] = 0;

            h[hn++] = a[i].r;
        }
        sort(h, h + hn);
        hn = unique(h, h + hn) - h;
        for (int i = 0; i < n; ++i) a[i].r = lower_bound(h, h + hn, a[i].r) - h;
        assert(hn == n);

        sort(a, a + n, ByD);
        for (int i = 1; i + 1 < n; ++i) {
            int bn = 0, cn = 0;

            memset(bc, 0, sizeof(bc));
            for (int j = 0; j < i; ++j) bc[a[j].r] = j + 1;
            for (int j = 0; j < hn; ++j) if (bc[j]) b[bn++] = make_pair(j, bc[j] - 1);

            memset(bc, 0, sizeof(bc));
            for (int j = i + 1; j < n; ++j) bc[a[j].r] = j + 1;
            for (int j = 0; j < hn; ++j) if (bc[j]) {
                ccc[cn] = 0;
                c[cn++] = make_pair(j, bc[j] - 1);
            }
            ccc[cn] = 0;

//            for (int j = 0; j < i; ++j) {
//                b[bn++] = make_pair(a[j].r, j);
//            }
//            for (int j = i + 1; j < n; ++j) {
//                ccc[cn] = 0;
//                c[cn++] = make_pair(a[j].r, j);
//            }

//            sort(b, b + bn);
//            sort(c, c + cn);

            for (int j = 0, k = 0; j < bn && b[j].first < a[i].r; ++j) {
                while (k < cn && c[k].first < b[j].first) ++k;
                ++ccc[k];
                teams += k;
                cnt[i] += k;
                cnt[b[j].second] += k;
            }
            for (int j = cn - 1; j >= 0; --j) {
                ccc[j] += ccc[j + 1];
                cnt[ c[j].second ] += ccc[j + 1];
            }
        }
        if (teams == 0) {
            puts("Rules Should Be Changed!");
            continue;
        }
//        cerr << clock() << endl;
        for (int i = 0; i < n; ++i) {
            out[ a[i].i ] = cnt[i];
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
//    cerr << clock() << endl;
    
    return 0;
}
