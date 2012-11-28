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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 211111
#define M N+N

int was[N], xx[N], yy[M], pp[M], d[N], n, m, x, y, kk = 0, del[M];
vector<int> ans;

int dfs(int x) {
    was[x] = true;
    int open = ((d[x]&1) == 0);
    for (int i = xx[x]; i; i = pp[i]) {
        int y = yy[i];
        if (was[y]) continue;

        if (dfs(y)) {
            del[i] = true;
            open = open ^ 1;
        }
    }
    return open;
}

int main() {
    freopen("odd.in", "r", stdin);
    freopen("odd.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;
        yy[++kk] = x, pp[kk] = xx[y], xx[y] = kk;
        d[x]++;
        d[y]++;
    }

    for (int i = 1; i <= n; i++) if (!was[i]) {
        if (dfs(i) != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) if (!del[i + i] && !del[i + i - 1]) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    puts("");
    
    return 0;
}
