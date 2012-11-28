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

typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int main() {
    freopen("business.in", "r", stdin);
    freopen("business.out", "w", stdout);

    LL n; int m;
    cin >> n >> m;

    ll ans = n * ll(2000);
    while (m--) {
        ll d, u;
        cin >> u >> d;

        ll cnt = (n * d + u + d - 1) / (u + d);
        if (cnt * d == u + d) ++cnt;

        if (cnt >= n) cnt = n;
        
        ll can = cnt * u - (n - cnt) * d;
        if (can <= 0) {
            can = n * u;
        }
        ans = min(ans, can);
    }

    cout << ans << endl;

    return 0;
}
                      