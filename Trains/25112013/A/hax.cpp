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

inline LL calc(LL n, LL x) {
    LL ans = 0;
    while (n >= x) {
        n /= x;
        ans += n;
    }
    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        LL n, k;
        cin >> n >> k;

        LL ans = 8e18;
        for (LL i = 2; i * i <= k; ++i) if (k % i == 0) {
            int c = 0;
            while (k % i == 0) {
                ++c;
                k /= i;
            }
            ans = min(ans, calc(n, i) / c);
        }
        if (k > 1) {
            ans = min(ans, calc(n, k));
        }

        cout << ans << endl;
    }
    
        
    return 0;
}
