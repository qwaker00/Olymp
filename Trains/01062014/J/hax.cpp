#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>
#include <string>

using namespace std;
typedef long long LL;

LL calc(LL a, LL b, LL p, LL m) {
    if (a < 0 || b < 0) return 0;

    LL v2 = (b + p) / p;
    LL v1 = (b + 1) / p;

    LL c2 = (b % p) + 1;
    LL c1 = p - c2;

    LL ans = LL(a / p) * (v1 * c1 + v2 * c2);

    LL call = a % p + 1;
    if (m >= c2 - 1) {
        if (a % p >= m) {
            ans += c2 * v2 + (call - c2) * v1;
        } else {
            if (a % p >= m - c2 + 1) {
                ans += (m - c2 + 1) * v1 + (call - (m - c2 + 1)) * v2;
            } else {
                ans += call * v1;
            }
        }
    } else {
        if (a % p <= m) {
            ans += call * v2;
        } else {
            if (a % p <= m + c1) {
                ans += (m + 1) * v2 + (call - (m + 1)) * v1;
            } else {
                ans += c1 * v1 + (call - c1) * v2;
            }
        }
    }

    return ans;
}

LL calc(int a, int b, int c, int d, int p, int m) {
    return calc(b, d, p, m) - calc(a - 1, d, p, m) - calc(b, c - 1, p, m) + calc(a - 1, c - 1, p, m);
}

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    int it = 0;
    while(T--) {
        ++it;
        int a, b, c, d, p, m;
        scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &p, &m);
        LL cnt = calc(a, b, c, d, p, m);
        LL denum = LL(b - a + 1) * (d - c + 1);
        LL g = gcd(denum, cnt);
        printf("Case #%d: %lld/%lld\n", it, cnt / g, denum / g);
    }

    return 0;
}
