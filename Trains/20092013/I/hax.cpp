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

int f[666][666], sf[666][666];
vector<int> g[666];
int n, m, p;
int start[666];
int d[666];
int was[666];
int IT = 0;
int xx[111111], yy[111111];

void Add(int x, int y, int p) {
    sf[x][y] = p;
    f[x][y] = p;
    f[y][x] = 0;
    g[x].push_back(y);
    g[y].push_back(x);
}

bool bfs() {
    memset(d, 63, sizeof(d));
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0, y; i < g[x].size(); ++i)
            if (f[x][y = g[x][i]] > 0 && d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
    }
    return d[n + m + 1] < 1e9;
}

int dfs(int x, int fl = 2e9) {
    if (x == n + m + 1) return fl;
    if (was[x] == IT) return 0;
    was[x] = IT;
    int totfl = 0;
    for (int& i = start[x], y; i < g[x].size(); ++i)
        if (f[x][y = g[x][i]] > 0 && d[y] == d[x] + 1) {
            int ff = dfs(y, min(fl - totfl, f[x][y]));
            if (ff) {
                f[x][y] -= ff;
                f[y][x] += ff;
                totfl += ff;
                if (totfl == fl) break;
            }
        }
    return totfl;
}

void fail() {
    puts("-1");
    exit(0);
}

int main() {
    freopen("trade.in", "r", stdin);
    freopen("trade.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i) Add(0, i + 1, 2);
    for (int i = 0; i < p; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        xx[i] = x;
        yy[i] = y;
        Add(x, y + n, 1);
    }
    for (int i = 0; i < m; ++i) Add(i + 1 + n, n + m + 1, 2);

    int tot = 0;
    while (bfs()) {
        memset(start, 0, sizeof(start));
        ++IT;
        tot += dfs(0);
    }

    for (int i = 1; i <= n; ++i) {
        int fl = 0;
        for (int j = 0, y; j < g[i].size(); ++j)
            if (sf[i][y = g[i][j]] == 1) {
                if (f[i][y] == 0) {
                    ++fl;
                }
            }
        if (fl < 2) {
            for (int j = 0, y; j < g[i].size(); ++j)
                if (sf[i][y = g[i][j]] == 1) {
                    if (f[i][y] == 1) {
                        ++fl;
                        f[i][y]--;
                        f[y][i]++;
                        if (fl == 2) break;
                    }
                }
        }
        if (fl < 2) {
            fail();
        }
    }
    for (int i = n + 1; i <= n + m; ++i) {
        int fl = 0;
        for (int j = 0, y; j < g[i].size(); ++j)
            if (sf[y = g[i][j]][i] == 1) {
                if (f[y][i] == 0) {
                    ++fl;
                }
            }
        if (fl < 2) {
            for (int j = 0, y; j < g[i].size(); ++j)
                if (sf[y = g[i][j]][i] == 1) {
                    if (f[y][i] == 1) {
                        ++fl;
                        f[y][i]--;
                        f[i][y]++;
                        if (fl == 2) break;
                    }
                }
        }
        if (fl < 2) {
            fail();
        }
    }

    vector<int> ans;
    for (int i = 0; i < p; ++i) {
        if (f[xx[i]][yy[i] + n] == 0) {
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    puts("");


    
    return 0;
}
