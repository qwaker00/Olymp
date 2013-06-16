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


#define MOD 1000000000

int a[111111];
int n, m, t, x, v, l, r;
LL f[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n >> m;

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] + f[i  - 2]) % MOD;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> x >> v;
            a[x] = v;
        } else
        if (t == 2) {
            cin >> l >> r;
            LL ans = 0;
            for (int j = 0; j <= r - l; ++j) ans = (ans + f[j] * a[j + l]) % MOD;
            cout << ans << endl;
        } else {
            cin >> x >> l >> r;
        }
    }
    
    return 0;
}
