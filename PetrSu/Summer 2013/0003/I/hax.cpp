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

int n;
int x, y;
int w[N];
LL ans;
vector<int> g[N];

void dfs(int x, int p) {
    w[x] = 1;
    for (size_t i = 0; i < g[x].size(); ++i) {
        if (g[x][i] == p) continue;
        dfs(g[x][i], x);
        w[x] += w[g[x][i]];
    }
}

int findc(int x, int p) {
    for (size_t i = 0; i < g[x].size(); ++i) {
        if (g[x][i] == p) continue;
        if (w[ g[x][i] ] * 2 > n)
            return findc(g[x][i], x);
    }
    return x;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, -1);
    int c = findc(1, -1);
    vector< pair<int, int> > q;
    for (size_t i = 0; i < g[c].size(); ++i) {
        dfs(g[c][i], c);
        q.push_back(make_pair(w[g[c][i]], g[c][i]));
    }

    cout << n - 1 << ' ' << ans << endl;
    return 0;
}
