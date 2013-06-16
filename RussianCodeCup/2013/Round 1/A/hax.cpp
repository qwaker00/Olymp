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

LL a[1111111];
LL t, n, u1, u2, b1, L1, b2, L2, tt;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> tt;
    for (int it = 0; it < tt; ++it) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }   
        cin >> u1 >> u2 >> t;
        cin >> b1 >> L1 >> b2 >> L2;

        LL ans = 9223372036854775807ll;
        if (b1 == b2) {
            if (b1 == 2) swap(u1, u2);
            if (L1 > L2) swap(L1, L2);

            ans = u1 * (L2 - L1);
            LL ns = t * 2;
            int p1 = lower_bound(a, a + n, L1) - a;
            int p2 = lower_bound(a, a + n, L2) - a;
            int p3 = ((p1 == 0) ? 0 : (p1 - 1));
            int p4 = ((p2 == 0) ? 0 : (p2 - 1));
            if (p1 == n) p1 = n - 1;
            if (p2 == n) p2 = n - 1;

            ns += min(
                    min(llabs(L1 - a[p1]) * u1 + llabs(L2 - a[p2]) * u1 + llabs(a[p1] - a[p2]) * u2,
                        llabs(L1 - a[p1]) * u1 + llabs(L2 - a[p4]) * u1 + llabs(a[p1] - a[p4]) * u2),
                    min(llabs(L1 - a[p3]) * u1 + llabs(L2 - a[p2]) * u1 + llabs(a[p3] - a[p2]) * u2,
                        llabs(L1 - a[p3]) * u1 + llabs(L2 - a[p4]) * u1 + llabs(a[p3] - a[p4]) * u2)
                  );
            if (ns < ans) ans =  ns;
        } else {
            if (b1 > b2) {
                swap(b1, b2);
                swap(L1, L2);
            }
            for (int i = 0; i < n; ++i) {
                LL T = t + u1 * llabs(L1 - a[i]) + u2 * llabs(L2 - a[i]);
                if (T < ans) ans = T;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
