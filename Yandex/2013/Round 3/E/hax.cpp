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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111
#define M 555555

vector<int> g[N], gg[N];
int c[N], v[N], vn = 0, n, m, was[N], mark[N], x, y, D[N];

void dfs(int x) {
    if (was[x]) return;
    was[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
        dfs(g[x][i]);
    v[vn++] = x;
}

void dfs2(int x, int y) {
    if (was[x]) return;
    was[x] = true;
    mark[x] = y;
    for (int i = 0; i < gg[x].size(); ++i)
        dfs2(gg[x][i], y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        gg[y].push_back(x);
    }

    memset(was, 0, sizeof(was));
    for (int i = 1; i <= n; ++i) if (!was[i]) dfs(i);
    memset(was, 0, sizeof(was));
    for (int i = 1; i <= n; ++i)
        if (!was[v[n - i]]) {
            dfs2(v[n - i], i);
        }

    memset(D, 127, sizeof(D));
    priority_queue< pair<int, int> > q;
    for (int i = 0; i < g[1].size(); ++i) {
        D[g[1][i]] = c[g[1][i]];
        q.push(make_pair(-c[g[1][i]], g[1][i]));
    }
    while (!q.empty()) {
        pair<int, int> t = q.top(); q.pop();
        int x = t.second;
        int d = -t.first;
        if (D[x] != d) continue;
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i];
            int dd = d + ((mark[x] == mark[y]) ? 0 : c[y]);
            if (dd < D[y]) {
                D[y] = dd;
                q.push(make_pair(-dd, y));
            }
        }
    }
    cout << D[n] << endl;
    
    return 0;
}
