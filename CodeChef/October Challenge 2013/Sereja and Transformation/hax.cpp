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

#define MOD 1000000007

ULL powmod(ULL x, ULL y) {
    ULL res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


/*    srand(time(0));
    for (int i = 0; i < 10; ++i) a[i] = rand() % 10;
    for (int it = 0; it < 10; ++it) {
        int s = accumulate(a, a + 10, 0);
        int mi = *min_element(a, a + 10);
        int ma = *max_element(a, a + 10);

        cout << ma - mi << endl;
        for (int i = 0; i < 10; ++i) a[i] = mi - a[i] + s;
    }
*/

    int T;
    cin >> T;
    while (T--) {
        int m, d, k, n;
        cin >> n >> m >> d >> k;
        if (d < m)        
            cout << ((m - d) * (powmod(d + 1, n) - 2 * powmod(d, n) + powmod(d - 1, n) + MOD + MOD)) % MOD << endl;else
            cout << 0 << endl;
    }
    
    return 0;
}
