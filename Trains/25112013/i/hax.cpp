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

struct Tp {
    LL x, y, f, r;
} a[555], b[555];
LL f[555][555];
LL D[555];
vector<int> g[555];
int start[555];

void add(int x, int y, int ff) {
    g[x].push_back(y);
    f[x][y] = ff;
    g[y].push_back(x);
    f[y][x] = 0;
}

bool bfs(int x, int finish) {
    memset(D, 63, sizeof(D));
    queue<int> q;
    q.push(x);
    D[x] = 0;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (size_t i = 0, y; i < g[x].size(); ++i)
            if (D[y = g[x][i]] > D[x] + 1 && f[x][y] > 0) {
                D[y] = D[x] + 1;
                q.push(y);
            }
    }
    return D[finish] < 1e18;
}

LL dfs(int x, int finish, LL fl) {
    if (x == finish) return fl;
    LL totfl = 0;
    int y;
    for (int& i = start[x]; i < g[x].size(); ++i)
        if (D[y = g[x][i]] == D[x] + 1 && f[x][y] > 0) {
            LL ff = dfs(y, finish, min(fl - totfl, f[x][y]));
            if (ff) {
                f[x][y] -= ff;
                f[y][x] += ff;
                totfl += ff;
                if (totfl == fl) break;
            }
        }
    return totfl;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;    
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].f >> a[i].r;
        }

        LL tot = 0;
        for (int i = 0; i <= n + m; ++i) g[i].clear();
        memset(f, 0, sizeof(f));

        for (int i = 0; i < m; ++i) {
            cin >> b[i].x >> b[i].y >> b[i].f;
            if ( sqr(a[0].x - b[i].x) + sqr(a[0].y - b[i].y) <= sqr(a[0].r) ) {
                a[0].f += b[i].f;
                b[i].f = 0;
            }
        }
        for (int i = 0; i < m; ++i) if (b[i].f) {
            bool any = false;
            for (int j = 1; j < n; ++j) {
                if ( sqr(a[j].x - b[i].x) + sqr(a[j].y - b[i].y) <= sqr(a[j].r) ) {
                    add(j, i + n, b[i].f);
                    any = true;
                }
            }
            if (any) {
                add(i + n, m + n, b[i].f);
                tot += b[i].f;
            }
        }

        bool ans = true;
        for (int i = 1; i < n; ++i) {
            if (a[i].f > a[0].f) {
                ans = false;
                break;
            } else {
                add(0, i, a[0].f - a[i].f);
            }
        }

        if (ans)
            while (bfs(0, n + m)) {
                memset(start, 0, sizeof(start));
                tot -= dfs(0, n + m, 2e9);
            }
        if (tot != 0) ans = false;

        puts(ans ? "Suiting Success" : "Lonesome Willy");
    }
    
    return 0;
}
