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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 222222
#define NONE -2147483646

int w[N], n, m, hw[N], bs[N], pr[N], d[N], ll[20][N*2], ln = 0, frst[N], lg[N*2];
int was[N];
vector<int> g[N];

struct TreeData {
    int sum;
    int left;
    int right;
    int best;

    TreeData() : best(NONE) {}
    TreeData(int w, int len) {
        sum = w * len;
        if (w > 0) {
            left = right = best = sum;
        } else {
            left = right = best = w;
        }
    }

    TreeData Merge(const TreeData& r) const {
        if (best == NONE) return r;
        if (r.best == NONE) return *this;
        TreeData t;
        t.sum = sum + r.sum;
        t.left = max(sum + r.left, left);
        t.right = max(r.sum + right, r.right);
        t.best = max(max(r.best, best), max(right + r.left, max(t.left, t.right)));
        return t;
    }
};

struct TreeItem {
    int l, r;
    int setall;
    TreeData data;
} Tbuf[N * 3 * 2];

int TreeCount = 0;
int TreeStart[N];
int TBufCounter = 0;
int TreeByV[N], PosByV[N];
int TreeHead[N];

inline void TreeSetall(TreeItem& t, int w) {
    t.setall = w;
    t.data = TreeData(w, t.r - t.l + 1);
}

void TreeInit(TreeItem* T, int x, int l, int r, int* v) {
    T[x].l = l, T[x].r = r;
    T[x].setall = NONE;
    if (l < r) {
        TreeInit(T, x + x, l, (l + r) >> 1, v);
        TreeInit(T, x + x + 1, (l + r + 2) >> 1, r, v);
        T[x].data = T[x + x].data.Merge(T[x + x + 1].data);
    } else {
        T[x].data = TreeData(w[ v[l] ], 1);
    }
}

void TreeSet(TreeItem* T, int x, int l, int r, int w) {
    if (r < T[x].l || l > T[x].r) return;
    if (l <= T[x].l && r >= T[x].r) {
        TreeSetall(T[x], w);
        return;
    }
    if (T[x].setall != NONE) {
        TreeSetall(T[x + x], T[x].setall);
        TreeSetall(T[x + x + 1], T[x].setall);
    }
    TreeSet(T, x + x, l, r, w);
    TreeSet(T, x + x + 1, l, r, w);
    T[x].setall = NONE;
    T[x].data = T[x + x].data.Merge(T[x + x + 1].data);
}

TreeData TreeGet(TreeItem* T, int x, int l, int r) {
    if (r < T[x].l || l > T[x].r) return TreeData();
    if (l <= T[x].l && r >= T[x].r) return T[x].data;
    if (T[x].setall != NONE) {
        TreeSetall(T[x + x], T[x].setall);
        TreeSetall(T[x + x + 1], T[x].setall);
    }
    return TreeGet(T, x + x, l, r).Merge(TreeGet(T, x + x + 1, l, r));
}

void BuildTree(int x) {
    TreeStart[TreeCount] = TBufCounter;    

    int vn = 0;
    static int v[N];

    while (bs[x]) {
        #ifdef DEBUG
        cerr << x << " ";
        #endif
        v[vn++] = x;
        PosByV[x] = vn - 1;
        TreeByV[x] = TreeCount;
        x = bs[x];
    }
    #ifdef DEBUG
    cerr << "\n";
    #endif

    TreeHead[TreeCount] = v[0];
    TreeInit(Tbuf + TBufCounter, 1, 0, vn - 1, v);
    int sz = 1;
    while (sz < vn) sz *= 2;
    TBufCounter += sz * 2 + 1;
    ++TreeCount;
}

void HLDoT(int x) {
    ll[0][++ln] = x;
    frst[x] = ln;
    was[x] = true;
    hw[x] = 1;
    int& bestson = bs[x] = -1;
    for (size_t i = 0; i < g[x].size(); ++i) {
        if (!was[g[x][i]]) {
            pr[g[x][i]] = x;
            d[g[x][i]] = d[x] + 1;
            HLDoT(g[x][i]);
            hw[x] += hw[ g[x][i] ];
            if (bestson == -1 || hw[bestson] < hw[ g[x][i] ]) {
                if (bestson != -1) BuildTree(bestson);
                bestson = g[x][i];
            } else
                BuildTree(g[x][i]);
            ll[0][++ln] = x;
        }
    }
}

void BuildLca() {
    lg[1] = 0;
    for (int i = 2; i <= ln; ++i) lg[i] = lg[i >> 1] + 1;
    for (int j = 1; (1 << j) <= ln; ++j)
        for (int i = 1; i + (1 << j) - 1 <= ln; ++i)
            if (d[ ll[j - 1][i] ] < d[ ll[j - 1][i + (1 << (j - 1))] ])
                ll[j][i] = ll[j - 1][i];else
                ll[j][i] = ll[j - 1][i + (1 << (j - 1))];
}

inline int Lca(int x, int y) {
    x = frst[x];
    y = frst[y];
    if (x > y) swap(x, y);
    int t = lg[y - x + 1];
    if (d[ ll[t][x] ] < d[ ll[t][y - (1 << t) + 1] ] )
        return ll[t][x];else
        return ll[t][y - (1 << t) + 1];
}

int main() {
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    pr[1] = 0;
    d[1] = 1;
    HLDoT(1);
    BuildTree(1);
    BuildLca();

    while (m--) {
        int t, a, b, c;
        scanf("%d%d%d%d", &t, &a, &b, &c);
        if (t == 1) {
            int p = Lca(a, b);
            while (d[a] >= d[p]) {
                int t = TreeByV[a];
                TreeSet(Tbuf + TreeStart[t], 1, (d[TreeHead[t]] > d[p]) ? 0 : PosByV[p], PosByV[a], c);
                a = pr[TreeHead[t]];
            }
            while (d[b] > d[p]) {
                int t = TreeByV[b];
                TreeSet(Tbuf + TreeStart[t], 1, (d[TreeHead[t]] > d[p]) ? 0 : PosByV[p] + 1, PosByV[b], c);
                b = pr[TreeHead[t]];
            }
        } else {
            #ifdef DEBUG
            cout << a << " " << b << " -> ";
            #endif

            TreeData ans1, ans2;
            int p = Lca(a, b);
            while (d[a] >= d[p]) {
                int t = TreeByV[a];
                ans1 = TreeGet(Tbuf + TreeStart[t], 1, (d[TreeHead[t]] > d[p]) ? 0 : PosByV[p], PosByV[a]).Merge(ans1);
                a = pr[TreeHead[t]];
            }
            while (d[b] > d[p]) {
                int t = TreeByV[b];
                ans2 = TreeGet(Tbuf + TreeStart[t], 1, (d[TreeHead[t]] > d[p]) ? 0 : PosByV[p] + 1, PosByV[b]).Merge(ans2);
                b = pr[TreeHead[t]];
            }
            swap(ans1.left, ans1.right);
            printf("%d\n", ans1.Merge(ans2).best);
        }
    }
    
    return 0;
}