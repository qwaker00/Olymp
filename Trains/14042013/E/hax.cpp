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

vector< pair<int, int> > g[N], g2[N];
int w1[N], w2[N];              
int n1, n2, m, pr[N], was[N], pr2[N];
int ex[M], ey[M], IT = 0;
pair<int, int> p[N];

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (size_t i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].second;
        if (pr[y] == -1) {
            pr[y] = x;
            pr2[x] = y;
            return true;
        }
    }
    for (int i = (int)g2[x].size() - 1; i >= 0; --i) {
        int y = g[x][i].second;
        if (kuhn(y)) {
            pr[y] = x;
            pr2[x] = y;
            return true;
        }
    }
    return false;
}

bool kuhn2(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (size_t i = 0; i < g2[x].size(); ++i) {
        int y = g2[x][i].second;
        if (pr2[y] == -1) {
            pr2[y] = x;
            pr[x] = y;
            return true;
        }
    }
    for (int i = (int)g2[x].size() - 1; i >= 0; --i) {
        int y = g2[x][i].second;
        if (kuhn2(y)) {
            pr2[y] = x;
            pr[x] = y;
            return true;
        }
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
        p[i - 1 + n1].second = i + n1;
        p[i - 1 + n1].first = w2[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(make_pair(-w2[y], y));
        g2[y].push_back(make_pair(-w1[x], x));
        ex[i] = x;
        ey[i] = y;
    }
    for (int i = 1; i <= n1; ++i) {
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 1; i <= n2; ++i) {
        sort(g2[i].begin(), g2[i].end());
    }

    sort(p, p + n1 + n2);

    memset(pr, -1, sizeof(pr));
    memset(pr2, -1, sizeof(pr2));

    for (int i = n1 + n2 - 1; i >= 0; --i) {
        ++IT;
        if (p[i].second >= n1) {
            if (pr2[p[i].second - n1] == -1)
                kuhn2(p[i].second - n1);
        } else {
            if (pr[p[i].second] == -1)
                kuhn(p[i].second);
        }
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
