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

#include <ext/rope>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n;
int c[111111];
int a[111];

LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    cin >> n;
    for (int i= 0; i < n; ++i) cin >> c[i];

    LL ans = 0;
    for (int i = 0; i < n; ++i) a[i] = i;
    do {
        int s = 0;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            s += abs(last - c[a[i]]);
            last = c[a[i]];
        }
        ans += s;
    } while (std::next_permutation(a, a + n));
    LL d = 1;
    for (int i = 1; i <= n; ++i) {
        LL g = gcd(ans, i);
        ans /= g;
        d *= i / g;
    } 
    cout << ans << ' ' << d << endl;

    return 0;
}
