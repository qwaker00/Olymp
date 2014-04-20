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

#define N 11111

int v[N], vn = 0;
vector<int> g[N];
int was[N], n, m, pos[N];

void dfs(int x) {
    was[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
        if (!was[g[x][i]])
            dfs(g[x][i]);
    v[vn++] = x;
    pos[x] = vn - 1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
        
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i<= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        vn = 0;
        memset(was, 0, sizeof(was));
        for (int i = 1; i <= n; ++i) if (!was[i]) dfs(i);

        int one = true;
        int error = false;
        for (int i = 0; i < vn; ++i) {
            int x = v[i];
            int nei = 0;
            for (int j = 0; j < g[x].size(); ++j) {
                if (pos[g[x][j]] > i) {
                    error = 1;
                    break;
                }
                if (pos[g[x][j]] == i - 1) nei = true;
            }
            if (i > 0 && !nei) one = false;
            if (error) break;
        }
        if (error) {
            puts("recheck hints");
            continue;
        }
        if (!one) {
            puts("missing hints");
            continue;
        }
        for (int i = vn - 1; i >= 0; --i) {
            printf("%d ", v[i]);
        }
        puts("");
    }
        
    return 0;
}
