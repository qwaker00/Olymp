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

#define MOD 1000000007

int Pow(int x, int y, int m) {
    int res = 1;
    while (y) {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int v[111];
ULL c[111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int up, d, m, n;
        cin >> up >> d >> m >> n;

        for (int i = 0; i < n; ++i) {
            v[i] = Pow(i, d, n);
            if (up >= i) {
                c[i] = (up - i) / n + 1;
            } else
                c[i] = 0;
        }

        ULL ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((v[i] + v[j] + v[k]) % n == m) {
                        ans = (((c[i] * c[j]) % MOD) * c[k] + ans) % MOD;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
