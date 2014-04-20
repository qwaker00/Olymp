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


const int N = 333333;
const LL INF = LL(9e18);

struct Tp {
    int t, l, r, a, d;
} q[N];
int h[N], hn = 0;


struct TSeg {
    LL d, a, l, r;

    bool operator<(const TSeg& t) const {
        return d < t.d;
    }

    LL calc(LL x) const {
        return a + x * d;
    }
};

typedef set< TSeg > TSegs;

struct TNode {
    int left, right;
    LL suma, sumd;

    TSegs segs;
} T[N * 4];
int P[N];

void init(int x, int l, int r) {
    T[x].left = l, T[x].right = r;
    if (l < r) {
        init(x + x, l, (l + r) >> 1);
        init(x + x + 1, (l + r + 2) >> 1, r);
    } else {
        P[l] = x;
    }
}

void set_law(int x, int l, int r, LL a, LL d) {
    if (l > T[x].right || r < T[x].left) return;
    if (l <= T[x].left && T[x].right <= r) {
        T[x].suma += a;
        T[x].sumd += d;
        return;
    }
    set_law(x + x, l, r, a, d);
    set_law(x + x + 1, l, r, a, d);
}

LL div_less(LL x, LL y) {
    LL t = x / y;
    if (t * y > x) --t;
    return t;
}

LL div_gr(LL x, LL y) {
    LL t = x / y;
    if (t * y < x) ++t;
    return t;
}

void set_product(int x, int l, int r, LL a, LL d) {
    if (l > T[x].right || r < T[x].left) return;
    if (l <= T[x].left && T[x].right <= r) {
        TSeg s;
        s.d = d;
        s.a = a;
        s.l = h[ T[x].left ];
        s.r = h[ T[x].right ];

        TSegs::iterator t = T[x].segs.lower_bound(s);

        TSegs::iterator l = t;
        bool erase = false;
        while (l != T[x].segs.begin()) {
            if (erase) {
                T[x].segs.erase(l--);
                erase = false;
            } else {
                --l;
            }

            if (s.calc(l->l) <= l->calc(l->l) && s.calc(l->r) <= l->calc(l->r)) {
                s.l = l->r + 1;
                break;
            } else
            if (s.calc(l->l) >= l->calc(l->l) && s.calc(l->r) >= l->calc(l->r)) {
                erase = true;
            } else {
                s.l = div_gr(l->a - s.a, s.d - l->d);

                TSeg lv = *l;
                lv.r = s.l - 1;
                T[x].segs.erase(l);
                T[x].segs.insert(lv);

                break;
            }
        }
        if (erase) T[x].segs.erase(l);

        TSegs::iterator r = t;
        while (r != T[x].segs.end()) {
            if (s.calc(r->l) <= r->calc(r->l) && s.calc(r->r) <= r->calc(r->r)) {
                s.r = r->l - 1;
                break;
            } else 
            if (s.calc(r->l) >= r->calc(r->l) && s.calc(r->r) >= r->calc(r->r)) {
                T[x].segs.erase(r++);
            } else {
                s.r = div_less(r->a - s.a, s.d - r->d);
                
                TSeg rv = *r;
                rv.l = s.r + 1;
                T[x].segs.erase(r);
                T[x].segs.insert(rv);

                break;
            }
        }

        if (s.l <= s.r)
            T[x].segs.insert(s);

        return;
    }
    set_product(x + x, l, r, a, d);
    set_product(x + x + 1, l, r, a, d);
}


struct ByR {
    bool operator()(const TSeg& a, const TSeg& b) const {
        return a.r < b.r;
    }
};

typedef set<TSeg, ByR> TSegsR;

LL get_max_product(TSegs& s, int x) {
    if (s.size() == 0) return -INF;

    TSeg ss;
    ss.r = x;

    TSeg res = *( ((TSegsR*)(&s))->lower_bound(ss) );
    return res.calc(x);
}

LL get_max(int x, int realx) {
    LL laws = 0;
    LL maxv = -INF;
    x = P[x];

    while (x) {
        maxv = max(maxv, get_max_product(T[x].segs, realx));
        laws += T[x].sumd * realx + T[x].suma;
        x >>= 1;
    }

    if (maxv == -INF) return -INF;
    return laws + maxv;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q[i].t);
        if (q[i].t == 3) {
            int x;
            scanf("%d", &q[i].a);
            h[hn++] = q[i].a;
        } else {
            int l, r, a, d;
            scanf("%d%d%d%d", &q[i].l, &q[i].r, &q[i].d, &q[i].a);
        }
    }

    sort(h, h + hn);
    hn = unique(h, h + hn) - h;

    init(1, 0, hn - 1);
    for (int i = 0; i < m; ++i) {
        if (q[i].t == 3) {
            LL ans = get_max( lower_bound(h, h + hn, q[i].a) - h, q[i].a );
            if (ans <= -INF) 
                puts("NA");
            else
                printf("%lld\n", ans);
        } else {
            int l = lower_bound(h, h + hn, q[i].l) - h;
            int r = upper_bound(h, h + hn, q[i].r) - h - 1;
            if (l <= r) {
                if (q[i].t == 1)
                    set_product(1, l, r, LL(q[i].a) - LL(q[i].l) * q[i].d, q[i].d);
                else
                    set_law(1, l, r, LL(q[i].a) - LL(q[i].l) * q[i].d, q[i].d);
            }
        }
    }
    
    return 0;
}
