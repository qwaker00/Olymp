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

#define M 21111
#define N 211

int n, m;
int xx[M], yy[M], pp[M], ff[M], cc[M], mm[M], kk = 0;
int D[N], P[N], st[N], F[N];

inline void add(int x, int y, int ff1, int cc1) {
    ++yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;
    ff[kk] = ff1, cc[kk] = cc1, mm[kk] = kk + 1;
    ++yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk;
    ff[kk] = 0, cc[kk] = -cc1, mm[kk] = kk - 1;
}

bool bfs() {
    deque<int> q;
    memset(D, 63, sizeof(D));
    memset(st, 0, sizeof(st));
    D[0] = 0;
    F[0] = 2e9;
    st[0] = 1;
    q.push_back(0);
    while (!q.empty()) {
        int x = q.front(); q.pop_front();
        st[x] = 2;
        for (int i = xx[x]; i; i = pp[i]) {
            int y = yy[i];
            if (!ff[i] || (D[y] < D[x] + cc[i] || (D[y] == D[x] + cc[i] && F[y] >= min(F[x], ff[i])) ) ) continue;
            D[y] = D[x] + cc[i];
            P[y] = i;
            F[y] = min(F[x], ff[i]);
            if (st[y] == 2)
                q.push_front(y);else
            if (st[y] == 0)
                q.push_back(y);
            st[y] = 1;
        }
    }
    return D[n + 1] < 1e9;
}

int main() {
    freopen("rentacar.in", "r", stdin);
    freopen("rentacar.out", "w", stdout);

    int in = 0, out = 0; 
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int t, r;
        cin >> t >> r;
        if (t < r) {
            add(0, i, r - t, 0);
            in += r - t;
        } else {
            add(i, n + 1, t - r, 0);
            out += t - r;
        }
    }
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        add(x, y, 1e9, c);
        add(y, x, 1e9, c);
    }
    assert(in == out);

    int fl = 0;
    LL cost = 0;
    while (bfs()) {
        int x = n + 1;
        int fladd = F[n + 1];
        while (x != 0) {
            ff[P[x]] -= fladd;
            ff[mm[P[x]]] += fladd;
            x = yy[mm[P[x]]];
        }
        fl += fladd;
        cost += LL(D[n + 1]) * fladd;
    }
    if (fl != out || fl != in) {
        cout << -1 << endl;
    } else {
        cout << cost << endl;
    }
    
    return 0;
}
