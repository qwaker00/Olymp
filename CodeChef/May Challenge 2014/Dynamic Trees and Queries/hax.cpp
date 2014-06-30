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

const int N = 222222;
const int MAX_NEWBIE = 666;

struct Tree {
    int left, right;
    LL sum, add;
    LL cnt;    
} T[N * 4];

vector<int> g[N];
int w[N], in[N], out[N], timer, revin[N], removed[N];
int newbie[N], parent[N], lastq[N], nlist[N], nl, tn;
LL value[N];

void treeinit(int x, int l, int r) {
    T[x].left = l;
    T[x].right = r;
    T[x].add = 0;
    if (l < r) {
        treeinit(x + x, l, (l + r) >> 1);
        treeinit(x + x + 1, (l + r + 2) >> 1, r);
        T[x].sum = T[x + x].sum + T[x + x + 1].sum;
        T[x].cnt = T[x + x].cnt + T[x + x + 1].cnt;
    } else {
        T[x].sum = value[ revin[l] ];
        T[x].cnt = 1;
    }
}

void treepropogate(int x, LL add = 0) {
    if (T[x].cnt == 0) return;
    if (T[x].left == T[x].right) {
        value[ revin[T[x].left] ] = T[x].sum + add;
        return;
    } 
    treepropogate(x + x, add + T[x].add);
    treepropogate(x + x + 1, add + T[x].add);
}

void treeadd(int x, int l, int r, LL val) {
    if (T[x].cnt == 0 || l > T[x].right || r < T[x].left) return;
    if (l <= T[x].left && r >= T[x].right) {
        T[x].add += val;
        T[x].sum += val * T[x].cnt;
        return;
    }
    treeadd(x + x, l, r, val);
    treeadd(x + x + 1, l, r, val);
    T[x].sum = T[x].add * T[x].cnt + T[x + x].sum + T[x + x + 1].sum;
}

void treeclear(int x, int l, int r) {
    if (T[x].cnt == 0 || l > T[x].right || r < T[x].left) return;
    if (l <= T[x].left && r >= T[x].right) {
        T[x].add = T[x].sum = T[x].cnt = 0;
        return;
    }
    treeclear(x + x, l, r);
    treeclear(x + x + 1, l, r);
    T[x].cnt = T[x + x].cnt + T[x + x + 1].cnt;
    T[x].sum = T[x].add * T[x].cnt + T[x + x].sum + T[x + x + 1].sum; 
}

LL treesum(int x, int l, int r, LL add = 0) {
    if (T[x].cnt == 0 || l > T[x].right || r < T[x].left) return 0;
    if (l <= T[x].left && r >= T[x].right) return T[x].sum + T[x].cnt * add;
    return treesum(x + x, l, r, add + T[x].add) + treesum(x + x + 1, l, r, add + T[x].add);
}

int n, qtimer = 0;

void CHECK_KEY(int key) {
    assert(!(key < 0 || key >= n || removed[key]));
}

void dfs(int x) {
    if (removed[x]) return;
    in[x] = ++timer;
    revin[timer] = x;
    for (int i = 0; i < (int)g[x].size(); ++i) dfs(g[x][i]);
    out[x] = timer;
}

inline void rebuild(bool first = false) {
    if (!first) {
        for (int i = 0; i < nl; ++i) newbie[nlist[i]] = 0;
        treepropogate(1);
    }
    timer = 0;
    nl = 0;
    tn = 0;
    cerr << clock() << endl;
    dfs(0);
    cerr << clock() << endl;
    tn = timer;
    treeinit(1, 1, tn);
}

inline void create(int key, LL val) {
    CHECK_KEY(key);
    ++qtimer;

    int nkey = n++;
    g[key].push_back(nkey);
    value[nkey] = val;
    nlist[nl++] = nkey;
    parent[nkey] = key;
    newbie[nkey] = 1;
    in[nkey] = out[nkey] = 0;
}

inline void add(int key, LL val) {
    CHECK_KEY(key);
    ++qtimer;
    if (nl > MAX_NEWBIE) {
        rebuild();
    }

    if (!newbie[key]) 
        treeadd(1, in[key], out[key], val);
    else {
        value[key] += val;
        lastq[key] = qtimer;
    }

    for (int i = 0; i < nl; ++i) {
        int x = nlist[i];
        if (removed[x]) continue;
        if ((newbie[parent[x]]  && lastq[parent[x]] == qtimer) ||
            (!newbie[parent[x]] && in[key] <= in[parent[x]] && out[key] >= out[parent[x]])
           )
        {
            lastq[x] = qtimer;
            value[x] += val;
        }
    }
}

inline void clear(int key) {
    CHECK_KEY(key);
    ++qtimer;
    if (nl > MAX_NEWBIE) {
        rebuild();
    }

    removed[key] = 1;
    if (!newbie[key]) 
        treeclear(1, in[key], out[key]);
    else {
        value[key] = 0;
        lastq[key] = qtimer;
    }

    for (int i = 0; i < nl; ++i) {
        int x = nlist[i];
        if (removed[x]) continue;
        if ((newbie[parent[x]]  && lastq[parent[x]] == qtimer) ||
            (!newbie[parent[x]] && in[key] <= in[parent[x]] && out[key] >= out[parent[x]])
           )
        {
            lastq[x] = qtimer;
            value[x] = 0;
            removed[x] = 1;
        }
    }
}

inline LL sum(int key) {
    CHECK_KEY(key);
    ++qtimer;
    if (nl > MAX_NEWBIE) {
        rebuild();
    }

    LL ans = 0;
    if (!newbie[key]) 
        ans += treesum(1, in[key], out[key]);
    else {
        ans += value[key];
        lastq[key] = qtimer;
    }

    for (int i = 0; i < nl; ++i) {
        int x = nlist[i];
        if (removed[x]) continue;
        if ((newbie[parent[x]]  && lastq[parent[x]] == qtimer) ||
            (!newbie[parent[x]] && in[key] <= in[parent[x]] && out[key] >= out[parent[x]])
           )
        {
            lastq[x] = qtimer;
            ans += value[x];
        }
    }
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        value[i] = x;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }

    rebuild(true);

    LL SPECIAL = 0;
    int q;
    scanf("%d", &q);
    while (q--) {
        LL key;
        int t, value;
        scanf("%d", &t);        
        switch (t) {
            case 1:
                scanf("%lld%d", &key, &value);
                create(key + SPECIAL, value);
            break;

            case 2:
                scanf("%lld%d", &key, &value);
                add(key + SPECIAL, value);
            break;

            case 3:
                scanf("%lld", &key);
                clear(key + SPECIAL);
            break;

            case 4:
                scanf("%lld", &key);
                SPECIAL = sum(key + SPECIAL);
                printf("%lld\n", SPECIAL);
//                SPECIAL = 0;
            break;
        }
    }
    cerr << clock() << endl;

    return 0;
}
