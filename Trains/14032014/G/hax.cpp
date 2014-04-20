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
vector<int> g[N], gr[N], gi[N], gri[N];
int sum[N], pa[N], pb[N], na, nb, m;

int was[N];

int dfs1(int x) {
    was[x] = 1;

    int s = 0;
    if (x <= -1 + na && x >= -na + na) {
        s = pa[-(x - na)];
    }

    for (int i = 0; i < (int)gr[x].size(); ++i) {
        if (!was[ gr[x][i] ]) {
            int t = dfs1(gr[x][i]);
            sum[ gri[x][i] ] += t;
            s += t;
        }
    }

    if (x >= 1 + na && x <= nb + na) {
        int t = min(s, pb[x - na]);
        pb[x - na] -= t;
        s -= t;
    }

    return s;
}

int dfs2(int x) {
    was[x] = 1;

    int s = 0;
    if (x >= 1 + na && x <= nb + na) {
        s = pb[x - na];
    }

    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (!was[ g[x][i] ]) {
            int t = dfs2(g[x][i]);
            sum[ gi[x][i] ] += t;
            s += t;
        }
    }

    return s;
}

int main() {
    freopen("transport.in", "r", stdin);
    freopen("transport.out", "w", stdout);
    
    int s1 = 0;
    scanf("%d%d%d", &na, &nb, &m);
    for (int i = 1; i <= na; ++i) {
        scanf("%d", &pa[i]);
        s1 += pa[i];
    }
    for (int i = 1; i <= nb; ++i) {
        scanf("%d", &pb[i]);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x += na;
        y += na;
        g[x].push_back(y);
        gi[x].push_back(i);
        gr[y].push_back(x);
        gri[y].push_back(i);
    }

    memset(was, 0, sizeof(was));
    dfs1(-1 + na);
    memset(was, 0, sizeof(was));
    dfs2(-1 + na);

    puts("YES");
    for (int i = 0; i < m; ++i) {
        assert(sum[i] <= s1);
        printf("%d ", sum[i]);
    }
    puts("");
    
    return 0;
}
