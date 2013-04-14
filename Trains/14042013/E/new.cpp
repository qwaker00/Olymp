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

#define N 5555
#define M 11111

vector< pair<int, int> > g[N];
int w1[N], w2[N];
int n1, n2, m, pr[N], was[N];
int ex[M], ey[M], IT = 0;
pair<int, int> p[N];
int lastit[N], lastans[N];

int trykuhn(int y) {    
    if (pr[y] == -1) return w2[y];
    if (lastit[y] == IT) return lastans[y];
    lastit[y] = IT;
    lastans[y] = -1;

    int x = pr[y], maxx = -1;
    for (int i = 0; i < g[x].size(); ++i)
        if (g[x][i].second != y)
            maxx = max(maxx, trykuhn(g[x][i].second));

    lastans[y] = maxx;
    return maxx;
}

void makekuhn(int x, int y) {
    if (pr[y] == -1) {
        pr[y] = x;
        return;
    }
    int py = pr[y];
    for (int i = 0; i < g[py].size(); ++i)
        if (g[py][i].second != y)
            if (lastans[y] == lastans[g[py][i].second]) {
                pr[g[py][i].second] = py;
                pr[y] = x;
                makekuhn(py, g[py][i].second);
                return;
            }
}


bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;

    int maxx = -1, maxy = 0;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].second;

        int d = trykuhn(y);
        if (d > maxx) {
            maxx = d;
            maxy = y;
        }
    }
    if (maxx >= 0) {
        int y = maxy;
        makekuhn(x, y);
        pr[y] = x;
        return true;
    }

    return false;
}

int main() {
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 1; i <= n1; ++i) {
        scanf("%d", &w1[i]);
        p[i - 1].second = i;
        p[i - 1].first = w1[i];
    }
    for (int i = 1; i <= n2; ++i) {
        scanf("%d", &w2[i]);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(make_pair(-w2[y], y));
        ex[i] = x;
        ey[i] = y;
    }
    for (int i = 1; i <= n1; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    sort(p, p + n1);

    memset(pr, -1, sizeof(pr));
    for (int i = n1 - 1; i >= 0; --i) {
        ++IT;
        kuhn(p[i].second);
    }

    LL w = 0;
    int cnt = 0;
    for (int i = 1; i <= n2; ++i) if (pr[i] != -1) {
        ++cnt;
        w += w1[pr[i]] + w2[i];
    }
    
    cout << w << endl;
    cout << cnt << endl;
    for (int i = 0; i < m; ++i) {
        if (pr[ey[i]] == ex[i]) {
            cout << i + 1 << " ";
            pr[ey[i]] = -1;
        }
    }
    puts("");
    
    return 0;
}
