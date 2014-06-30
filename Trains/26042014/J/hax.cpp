#include <cstdio>
#include <memory.h>

int dn[11111];
int d[11111][111];
int s[33333];
bool f[33333][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 1; i <= 100; ++i)
        for (int j = 1; j <= 100; ++j) {
            d[i * j][dn[i * j]++] = i;
        }

    int n, x, y, a[22], it = 0;
    while (1) {
        ++it;

        scanf("%d", &n);
        if (n == 0) break;

        scanf("%d%d", &x, &y);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

        s[0] = 0;
        for (int i = 0; i < (1 << n); ++i) {
            s[i] = 0;
            for (int j = 0; j < n; ++j) if (i & (1 << j)) {
                s[i] = s[i ^ (1 << j)] + a[j];
            }
        }

        bool ans = false;
        if (s[(1 << n) - 1] == x * y) {

            for (int i = 1; i < (1 << n); ++i) {
                memset(f[i], 0, sizeof(f[i]));

                if ((i & (i - 1)) == 0) {
                    for (int ai = 0; ai < dn[s[i]]; ++ai) {
                        f[i][d[s[i]][ai]] = 1;
                    }
                } else {
                    for (int ai = 0; ai < dn[s[i]]; ++ai) {
                        int a = d[s[i]][ai];
                        if (f[i][a]) continue;
                        for (int j = (i - 1) & i; j; j = (j - 1) & i) {
                            if (f[j][a] && f[i ^ j][a]) {
                                f[i][a] = 1;
                                f[i][s[i] / a] = 1;
                                break;
                            }
                        }
                    }
                }

            //    for (int j = 0; j < 111; ++j) if (f[i][j]) {
            //        printf("%d %d\n", i, j);
            //    }
            }
            ans = f[(1 << n) - 1][x];
        }
        if (ans)
            printf("Case %d: Yes\n", it);else
            printf("Case %d: No\n", it);
    }

    return 0;
}
