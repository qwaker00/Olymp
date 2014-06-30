#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <vector>

using namespace std;
const int N = 111;
vector< int > g[N];
int ke;
int a[N], b[N], c[N];
int from[N], to[N];
bool used[N];
int f[N], bsum[N];

struct cell {
    int a, b;

    cell(int ax = 0, int ay = 0) : a(ax), b(ay) {}

    bool operator <(const cell& A) const {
        return a - b < A.a - A.b;
    }
};
vector< cell > sons[N];

void dfs(int x) {
    used[x] = true;
    sons[x].clear();
    bsum[x] = b[x];

    int A = 0, B = 0;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (!used[y]) {
            dfs(y);
            bsum[x] += bsum[y];
            sons[x].push_back( cell(f[y], bsum[y]) );
        }
    }
    sort(sons[x].begin(), sons[x].end());

    int cura = 0;
    for (int i = 0; i < sons[x].size(); ++i) {
        cura = max(cura, sons[x][i].a - sons[x][i].b);
        cura += sons[x][i].b;
    }
    f[x] = max(a[x], cura + b[x]);
}

int main() {
    int it = 0;
    int n;
    while (true) {
        ++it;
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", a + i, b + i, c + i);
            b[i] += c[i];
        }
        for (int i = 0; i < n; ++i) g[i].clear();

        ke = 0;
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            memset(used, 0, sizeof(used));
            dfs(i);
            ans = min(ans, f[i]);
        }

        printf("Case %d: %d\n", it, ans);
    }

    return 0;
}
