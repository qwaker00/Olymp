#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 111111;
vector<int> g[N];
int color[N], was[N], maxcol;

void dfs(int x) {
    bool can[3] = {1, 1, 1};
    was[x] = 1;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (was[g[x][i]]) {
            can[color[g[x][i]]] = 0;
        }
    }
    color[x] = 0;
    while (!can[color[x]]) ++color[x];
    if (color[x] > maxcol) maxcol = color[x];
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (!was[g[x][i]]) {
            dfs(g[x][i]);
        }
    }
}

int main() {
    freopen("coloring.in", "r", stdin);
    freopen("coloring.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int k, x;
        scanf("%d%d", &k, &x);
        for (int j = 1; j < k; ++j) {
            int y;
            scanf("%d", &y);
            g[x].push_back(y);
            g[y].push_back(x);
            x = y;
        }
    }

    dfs(1);

    printf("%d\n", maxcol + 1);
    for (int i = 1; i <= n; ++i)
        printf("%d ", color[i] + 1);
    printf("\n")   ;

    return 0;
}
