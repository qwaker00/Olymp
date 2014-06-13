#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ULL;
typedef long double LD;
ULL C[100][100];
int prime[22], pn;
ULL ans;

void rec(ULL x, int c, int pi, ULL n, int up) {
    if (c > 0 && n == 1) {
        if (x < ans) {
            ans = x;
        }
        return;
    }
    ULL v = x * prime[pi];
    LD vv = LD(x) * prime[pi];
    for (int i = 1; vv < 1.3e19 && i <= up; ++i) {
        if (C[c + i][i] > n) break;
        if ((n % C[c + i][i]) == 0) rec(v, c + i, pi + 1, n / C[c + i][i], i);
        v *= prime[pi];
        vv *= prime[pi];
    }
}

int main() {
    //freopen(".in", "r", stdin);
    for (int i = 0; i < 100; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    for (int i = 2; pn < 20; ++i) {
        bool g = 1;
        for (int j = 0; j < pn; ++ j) if ((i % prime[j]) == 0) {
            g = 0;
            break;
        }
        if (g) prime[pn++] = i;
    }

    ULL n;
    while (cin >> n) {
        ans = ULL(1) << 63;
        rec(1, 0, 0, n, 100);
        cout << n << " " << ans << endl;
    }

    return 0;
}
