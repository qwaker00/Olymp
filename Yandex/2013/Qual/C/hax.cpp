#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL f[33][2];

LL Xor(LL n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1 ^ 2;
    if (n == 3) return 0;
    int it = 0;
    while ( (1ll << (it + 1)) <= n) ++it;
    return (LL((n - (1ll << it) + 1) & 1) << it) | Xor(n - (1 << it));
}

int a[33], b[33];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    LL n;
    cin >> n;

    LL ans1 = n * (n + 1) / 2;
    LL ans2 = 0;

    LL totxor = Xor(n);
#ifdef DEBUG
    int tx = 0;
    for (int i = 1; i <= n; ++i) tx ^= i;
    if (tx != totxor) throw 2;
#endif

    if (totxor) {
        int it = 0;
        while ( (1ll << (it + 1)) <= totxor) ++it;
        int gn = n >> it;
        ans2 = (gn / 2) * (1ll << it);
        if (gn & 1) ans2 += (n & ((1ll << it) - 1)) + 1;
    } else {
        ans2 = 0;
    }

#ifdef DEBUG
    LL realans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) if ((totxor ^ i ^ (i - j)) == 0) {
            ++realans;
        }
    }
    if(realans != ans2) throw 1;
#endif

    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}
                            