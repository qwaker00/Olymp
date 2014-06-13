#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int f[66666][17], ed[66666];
int cool[17], stay[17], n, m, l, s, t, d[333][333], x, y, z;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
    --s;
    memset(d, 63, sizeof(d));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        --x; --y;
        d[x][y] = d[y][x] = z;
    }
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 0; i < l; ++i) {
        scanf("%d%d", &cool[i], &stay[i]);
        --cool[i];
    }

    memset(f, 63, sizeof(f));
    for (int i = 0; i < l; ++i) {
        f[1 << i][i] = d[s][cool[i]] + stay[i];
    }
    ed[0] = 0;
    int ans = 0;
    for (int i = 1; i < (1 << l); ++i) {
        ed[i] = ed[i & (i - 1)] + 1;
        for (int k = 0; k < l; ++k) if (f[i][k] < 1e9) {
            if (f[i][k] + d[cool[k]][s] <= t && ed[i] > ans) {
                ans = ed[i];
            }
            for (int kk = 0; kk < l; ++kk)
                if ( ((1 << kk) & i) == 0 && f[i | (1 << kk)][kk] > f[i][k] + d[cool[k]][cool[kk]] + stay[kk]) {
                    f[i | (1 << kk)][kk] = f[i][k] + d[cool[k]][cool[kk]] + stay[kk];
                }
        }
    }
    printf("%d\n", ans);

    return 0;
}

