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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, z = 0, o = 0, t = 0;
        LL ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if (x == 0) {
                ans += i;
                ++z;
            } else
            if (x == 1) {
                ans += i;
                ++o;
            } else
            if (x == 2) {
                ans += z + o + t;
                ++t;
            } else
                ans += z + o;
        }
        printf("%lld\n", LL(n) * (n - 1) / 2 - ans);
    }
    
    return 0;
}
