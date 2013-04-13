#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int N = 1111;
int a[N][N];
int d[N], u[N];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        memset(a, 0, sizeof(a));
        int n, m;
        scanf("%d%d", &n, &m);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            ++a[x][y];
        }

        memset(u, 0, sizeof(u));
        
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 1; j <= n; ++j)
                if (a[i][j]) {
                    int dx = a[i][j];
                    a[i][j] = cnt;
                    cnt += dx;
                } else {
                    a[i][j] = 1e9;
                }
        }

        u[1] = 1;
        memcpy(d, a[1], sizeof(d));
        d[1] = 0;
        if (n == 1) {
            puts("0");
            continue;
        }

        bool found = false;
        for (int it = 2; it <= n; ++it) {
            int cand = -1;
            for (int j = 2; j <= n; ++j)
                if (!u[j] && (cand == -1 || d[cand] > d[j])) cand = j;
            if (cand == -1 || d[cand] > 1e8) {
                break; 
            }

            if (cand == n) {
                found = true;
                break;
            }

            u[cand] = 1;
            for (int j = 2; j <= n; ++j)
                d[j] = min(d[j], d[cand] + a[cand][j]);
        }

        if (found) printf("%d\n", d[n]);
        else puts("-1");
    }

    return 0;
}

