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

int c[1111111];

LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    sort(c, c + n);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += LL(c[i]) * ((i + 1) - (n - i - 1));
        ans += LL(c[i]) * (i - (n - i - 1));
    }
    LL g = gcd(ans, n);
    cout << ans / g << ' ' << n / g << endl;
    

    return 0;
}
