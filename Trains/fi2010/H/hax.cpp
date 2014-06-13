#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef unsigned long long ULL;

int a[555];
int f[555];
int g[555][555];
int good[555][555];
int was[555], IT;
int minim[555][555];
int cnt[555][555];

int main() {
    //freopen(".in", "r", stdin);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        minim[i][i] = a[i];
        for (int j = i + 1; j <= n; ++j)
            minim[i][j] = min(minim[i][j - 1], a[j]);
    }
    for (int i = 1; i <= n; ++i) {
        memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
        for (int j = a[i]; j < 555; ++j) ++cnt[i][j];
    }

    for (int _l = 1; _l <= n; ++_l) {
        for (int i = 1; i + _l - 1 <= n; ++i) {
            int j = i + _l - 1;

            g[i][j] = 1e9;

            bool noeq = 1;
            ++IT;
            for (int k = i; k <= j; ++k) {
                if (was[a[k]] == IT) noeq = 0;
                was[a[k]] = IT;
            }
            if (!noeq) continue;

            good[i][j] = 1;
            for (int k = 1; k <= j - i + 1; ++k) {
                if (was[k] != IT) {
                    good[i][j] = 0;
                    break;
                }
            }

            if (i == j) g[i][j] = 0;else
            for (int k = i; k < j; ++k) {
                int m1 = minim[i][k];
                int m2 = minim[k + 1][j];
                int add = 0;
                if (m1 < m2) {
                    add = (j - i + 1) - (cnt[k][m2 - 1] - cnt[i - 1][m2 - 1]);
                } else {
                    add = (j - i + 1) - (cnt[j][m1 - 1] - cnt[k][m1 - 1]);
                }
                g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j] + add);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        f[i] = 1e9;
        for (int j = 0; j < i; ++j)
            if (good[j + 1][i])
                f[i] = min(f[j] + g[j + 1][i], f[i]);
    }
    if (f[n] > 1e9 -1)
        cout << "impossible\n";else
        cout << f[n] << endl;

    return 0;
}
