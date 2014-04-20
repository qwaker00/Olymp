#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <assert.h>
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL sum(LL l, LL r) {
    if (l <= 0) {
        LL c = ((r - 1) / 2);
        return c * (c + 1) + ((r & 1) == 0 ? (r / 2) : 0);
    } else {
        return sum(0, r) - sum(0, l - 1);
    }
}

LL calc(LL n) {
    LL ans = sum(n - (n - 2), n - (n + 2) / 3);
    ans -= (n - 1) * (((n + 1) / 2) - ((n + 2) / 3));
    LL l = (n + 2) / 3;
    LL r = (n + 1) / 2 - 1;
    if (r >= l) ans += (r + l) * (r - l + 1);
    return ans;
}
LL calcbrute(LL n) {
    LL ans = 0;
    for (int k = (n + 1) / 2; k <= n - 2; ++k) ans += (n - k) / 2;
    for (int k = (n + 2) / 3; k < (n + 1) / 2; ++k) ans += (n - k) / 2 - (n - 2 * k - 1);
    return ans;
}
LL calcbrute2(LL n) {
    int ans = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i; j <= n - i - j; ++j) {
            ++ans;
        }
    return ans;
}

LL solve(LL v) {
    LL l = 1;
    LL r = 2000000000ll;
    while (l < r) {
        LL c = (l + r + 1) / 2;
        if (calc(c) > v) r = c - 1;else l = c;
    }
    return l;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    

/*    for (int i = 1; i <= 10; ++i) {
        cerr << i << " " << calc(i) << endl;
        assert(calc(i) == calcbrute(i));
        assert(calc(i) == calcbrute2(i));
    }
*/
    LL l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;

    return 0;
}
