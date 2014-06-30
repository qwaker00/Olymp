#include <cstdio>
#include <memory.h>
#include <algorithm>

using std::max;
using std::min;

int s[2222][2222], n, m;

inline int getsum(int x1, int y1, int x2, int y2) {
    x1 = max(min(x1, n + m), 1);
    y1 = max(min(y1, m + n), 1);
    x2 = max(min(x2, n + m), 1);
    y2 = max(min(y2, m + n), 1);
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int __it = 0;
    while (1) {
        int k, q;
        scanf("%d%d%d%d", &n, &m, &k, &q);
        if (n == 0) break;

        int shx, shy;
        memset(s, 0, sizeof(s[0]) * (n + m + 1));
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &shx, &shy);
            ++s[shx + shy][shx - shy + m];
        }
        for (int i = 1; i <= n + m; ++i)
            for (int j = 1; j <= n + m; ++j)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];

        ++__it;
        printf("Case %d:\n", __it);
        while (q--) {
            int r;
            scanf("%d", &r);
            int mx = -1;
            int ansx = 0;
            int ansy = 0;
            for (int j = 1; j <= m; ++j) {
               for (int i = 1; i <= n; ++i) {
                    int ss = getsum(i - r + j, i - r - j + m, i + r + j, i + r - j + m);
                    if (ss > mx) {
                        mx = ss;
                        ansx = i;
                        ansy = j;
                    }
                }
            }
            printf("%d (%d,%d)\n", mx, ansx, ansy);
        }
    }


    return 0;
}

