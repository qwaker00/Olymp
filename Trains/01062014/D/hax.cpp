#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>

using namespace std;
typedef long double LD;

int c[5][111];
//    T     N   K  B
int f[222][111][5][5];

struct Tp {
    int y, t, c;
    Tp() {}
    Tp(int y, int t, int c) : y(y), t(t), c(c) {}
};
vector<Tp> g[111];


void maximize(int&x , int y) {
    if (y > x) x = y;
}

#define good(i, j) (((i) != 1 && (i) != N) || ((j) == 0))
#define good2(i, j) (((i) != 1 && (i) != N))

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T;
    cin >> T;
    int it = 0;
    while(T--) {
        ++it;

        int N, M, B, K, R, T;
        scanf("%d%d%d%d%d%d", &N, &M, &B, &K, &R, &T);
        for (int i = 0; i < K; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf("%d", &c[i][j]);
            }
        }
        for (int i = 0; i < M; ++i) {
            int x, y, t, c;
            scanf("%d%d%d%d", &x, &y, &t, &c);
            g[x].push_back(Tp(y, t, c));
        }

        memset(f, 128 + 63, sizeof(f));
        f[0][1][0][0] = R;
        for (int t = 0; t < T; ++t) {
            for (int i = 1; i < N; ++i) {
                int fi = (i == 1 || i == N) ? 1 : K;
                for (int j = 0; j < fi; ++j) {
                    for (int s = 0; s <= B; ++s) if (f[t][i][j][s] >= 0) {
                        int nextu = (j + 1) % K;

                        //cerr << t << " " << i << " " << j << " " << s << " " << f[t][i][j][s] << endl;

                        // no trade
                        if (good(i, nextu))
                            maximize(f[t + 1][i][nextu][s], f[t][i][j][s]);
                        for (int l = 0; l < (int)g[i].size(); ++l) {
                            if (good(g[i][l].y, j) && t + g[i][l].t <= T && f[t][i][j][s] >= g[i][l].c)
                                maximize(f[t + g[i][l].t][g[i][l].y][j][s], f[t][i][j][s] - g[i][l].c);
                        }

                        // buy
                        if (s + 1 <= B) {
                            if (good2(i, nextu) && f[t][i][j][s] >= c[nextu][i])
                                maximize(f[t + 1][i][(j + 1) % K][s + 1], f[t][i][j][s] - c[nextu][i]);
                            for (int l = 0; l < (int)g[i].size(); ++l) {
                                if (good2(g[i][l].y, j) && t + g[i][l].t <= T && f[t][i][j][s] >= c[j][g[i][l].y] + g[i][l].c)
                                    maximize(f[t + g[i][l].t][g[i][l].y][j][s + 1], f[t][i][j][s] - g[i][l].c - c[j][g[i][l].y]);
                            }
                        }

                        // sell
                        if (s > 0) {
                            if (good2(i, nextu))
                                maximize(f[t + 1][i][(j + 1) % K][s - 1], f[t][i][j][s] + c[nextu][i]);
                            for (int l = 0; l < (int)g[i].size(); ++l) {
                                if (good2(g[i][l].y, j) && t + g[i][l].t <= T && f[t][i][j][s] >= g[i][l].c)
                                    maximize(f[t + g[i][l].t][g[i][l].y][j][s - 1], f[t][i][j][s] - g[i][l].c + c[j][g[i][l].y]);
                            }
                        }
                   }
                }
            }
        }

        for (int i = 1; i <= N; ++i) g[i].clear();

        int ans = -1;
        for (int t = 0; t <= T; ++t)
            maximize(ans, f[t][N][0][0]);

        if (ans == -1) {
            cout << "Case #" << it << ": Forever Alone\n";
        } else {
            cout << "Case #" << it << ": " << ans << "\n";
        }
    }

    return 0;
}
