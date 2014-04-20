#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>

typedef unsigned long long ULL;
using namespace std;

ULL f[66][66][66][2];

ULL Calc(ULL n, int x) {
    int dn = 0;
    bool d[66];
    while (n > 0) {
        d[dn++] = n % 2;
        n /= 2;
    }
    if (x > dn) return 0;
    reverse(d, d + dn);

    memset(f, 0, sizeof(f));
    f[0][0][0][1] = 1;
    for (int i = 0; i < dn; ++i)
        for (int j = 0; j <= i; ++j)
            for (int k = 0; k < x; ++k)
                for (int l = 0; l < 2; ++l) if (f[i][j][k][l])
                    for (int dig = 0; dig < 2; ++dig) {
                        if (l == 1 && dig > d[i]) continue;
                        f[i + 1][j + dig][(k * 2 + dig) % x][l && dig == d[i]] += f[i][j][k][l];
                    }
    return f[dn][x][0][0] + f[dn][x][0][1];
}


int main() {
    ULL n, ans = 0;
    cin >> n;
    for (int i = 1; i <= 63; ++i) ans += Calc(n, i);
    cout << ans << endl;
    return 0;
}
