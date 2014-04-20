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

const int N = 222222;

struct Te {
    int x, y;
} e[N];

struct Tp {
    int l, r, ll, i;

    bool operator<(const Tp& t) const {
        return ll < t.ll || (ll == t.ll && r < t.r);
    }
} a[N];
int ans[N];
//int ans2[N];

int pr[N]/*, rank[N]*/, comp;
int IT = 0, was[N], fakepr[N], /*fakerank[N],*/ fakecomp;

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

inline void unite(int x, int y) {
    x = fs(x);
    y = fs(y);
    if (x == y) return;
    --comp;
    pr[y] = x;
}

int fakefs(int x) {
    if (was[x] != IT) {
        fakepr[x] = pr[x];
//        fakerank[x] = rank[x];
        was[x] = IT;
    }
    if (fakepr[x] != x) fakepr[x] = fakefs(fakepr[x]);
    return fakepr[x];
}

inline void fakeunite(int x, int y) {
    x = fakefs(x);
    y = fakefs(y);
    if (x == y) return;    
    --fakecomp;
    fakepr[y] = x;
}

inline int request(int l, int r) {
    ++IT;
    fakecomp = comp;
    while (l <= r) {
        fakeunite(e[l].x, e[l].y);
        ++l;
    }
    return fakecomp;
}


int brute(int n, int l, int r) {
    for (int i = 1; i <= n; ++i) pr[i] = i;
    int ans = n;
    for (int i = l; i <= r; ++i) {
        int x = fs(e[i].x);
        int y = fs(e[i].y);
        if (x != y) {
            pr[x] = y;
            --ans;
        }
    }    
    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);

        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &e[i].x, &e[i].y);
        }
                
        int sq = sqrt(n) + 1;
        for (int i = 0; i < q; ++i) {
            scanf("%d%d", &a[i].l, &a[i].r);
            --a[i].l;
            --a[i].r;

//            ans2[i] = brute(n, a[i].l, a[i].r);

            a[i].ll = a[i].l / sq;
            a[i].i = i;
        }
        sort(a, a + q);

        for (int i = 0; i < q; ) {
            for (int j = 1; j <= n; ++j) {
                pr[j] = j;
//                rank[j] = 1;
            }
            comp = n;

            int ll = a[i].ll;
            while (i < q && a[i].r / sq == ll) {
                ans[a[i].i] = request(a[i].l, a[i].r);
                ++i;
            }
            int rr = (ll + 1) * sq, r = rr;
            while (i < q && a[i].ll == ll) {
                while (r <= a[i].r) {
                    unite(e[r].x, e[r].y);
                    ++r;
                }
                ans[a[i].i] = request(a[i].l, rr - 1);
                ++i; 
            }
        }
        for (int i = 0; i < q; ++i) {
            printf("%d\n", ans[i]);
//            if (ans[i] != ans2[i]) {
//                cerr << i << endl;
//                throw 1;
//            }
        }
    }
    cerr << clock() << endl;
    
    return 0;
}
