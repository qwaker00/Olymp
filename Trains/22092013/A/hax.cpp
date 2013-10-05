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

const int INF = 2e9;
int n, m;

struct E {
    int y, f, c, m;
};
vector<E> g[111];

void Add(int x, int y, int f, int c) {
    E e;
    e.y = y;
    e.f = f;
    e.c = c;
    e.m = g[y].size();
    g[x].push_back(e);

    e.y = x;
    e.f = 0;
    e.c = -c;
    e.m = g[x].size() - 1;
    g[y].push_back(e);
}
int D[111], st[111], prx[111], pri[111], ff[111];

int shortest(int S, int T) {
    memset(D, 63, sizeof(D));
    memset(st, 0, sizeof(st));
    deque<int> q;
    D[S] = 0;
    ff[S] = INF;
    q.push_back(S);
    st[S] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop_front();
        st[x] = 2;
        for (size_t i = 0; i < g[x].size(); ++i) {
            E& e = g[x][i];
            if (e.f > 0 && (D[x] + e.c < D[e.y] || (D[x] + e.c == D[e.y] && ff[x] > ff[e.y] && e.f > ff[e.y]))) {
                if (st[e.y] == 2) {
                    q.push_front(e.y);
                } else
                if (st[e.y] == 0) {
                    q.push_back(e.y);
                }
                prx[e.y] = x;
                pri[e.y] = i;
                st[e.y] = 1;
                D[e.y] = D[x] + e.c;
                ff[e.y] = min(ff[x], e.f);
            }
        }
    }
    return D[T];
}

int main() {
    freopen("beer.in", "r", stdin);
    freopen("beer.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
        int ai;
        scanf("%d", &ai);

        Add(i, n + 1, INF, -ai);
    }
    for (int i = 0; i < m; ++i) {
        int x, y, f, c;
        scanf("%d%d%d%d", &x, &y, &f, &c);
        Add(x, y, f, c);
        Add(y, x, f, c);
    }

    LL ans = 0;
    while (shortest(1, n + 1) < 0) {
        int x = n + 1;
        int fl = ff[x];
        while (x != 1) {
            g[prx[x]][pri[x]].f -= fl;
            g[x][ g[prx[x]][pri[x]].m ].f += fl;

            ans += g[prx[x]][pri[x]].c * fl;
            x = prx[x];
        }
    }
    cout << -ans << endl;
    
    return 0;
}
