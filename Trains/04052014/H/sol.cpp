#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>


using namespace std;
typedef long long ll;

const int N = 1000111;
vector<int> g[N];
int h[N];
bool used[N];
bool was[N];
int f[N], cnt[N];
int root;
vector<int> q;

void dfs1(int x) {
    f[x] = h[x];
    int sons = 0;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (used[y]) {
            f[x] = min(f[x], h[y]);
        } else {
            ++sons;
            used[y] = true;
            h[y] = h[x] + 1;
            dfs1(y);
            if (x != 1 && f[y] >= h[x]) {
                root = x;
            }
            f[x] = min(f[x], f[y]);
        }
    }

    if (x == 1 && sons > 1) {
        root = x;
    }
}

void dfs2(int x) {
    f[x] = h[x];
    cnt[x] = 1;
    int sons = 0;
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (used[y]) {
            f[x] = min(f[x], h[y]);
        } else {
            ++sons;
            used[y] = true;
            h[y] = h[x] + 1;
            dfs2(y);

            cnt[x] += cnt[y];
            if (was[y]) was[x] = true;
            if (f[y] >= h[x]) {
                was[x] = true;
                if (!was[y]) q.push_back(cnt[y]);
            }
            f[x] = min(f[x], f[y]);
        }
    }
}

int main() {
    int n;
    int tests = 0;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;

        ++tests;
        for (int i = 0; i <= n + 2; ++i) g[i].clear();
        int x, y;
        int mx = 0;
        while (n--) {
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
            mx = max(mx, max(x, y));
        }
        n = mx;
        memset(used, 0, sizeof(used[0]) * (mx + 10));

        root = -1;
        h[1] = 0;
        used[1] = true;
        dfs1(1);

        if (root == -1) {
            printf("Case %d: %d %lld\n", tests, 2, ll(mx) * ll(mx - 1) / 2);
            continue;
        }

        q.clear();
        h[root] = 0;
        memset(used, 0, sizeof(used[0]) * (mx + 10));
        memset(was, 0, sizeof(was[0]) * (mx + 10));
        used[root] = true;
        dfs2(root);

        ll ans = 1;
        for (int i = 0; i < q.size(); ++i) ans *= ll(q[i]);
        printf("Case %d: %d %lld\n", tests, int(q.size()), ans);


    }

    return 0;
}
