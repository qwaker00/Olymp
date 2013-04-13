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

LL a[11111];
LL C[10111][5055];

inline int GetC(int n, int m) {
    if (m + m > n) m = n - m;
    return C[n][m];
}
                             
int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
          
    for (int i = 0; i < 10111; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i && j < 5055; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    int T;
    scanf("%d", &T);
    for (int __it = 1; __it <= T; ++ __it) {
        int n, k;

        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        LL sum = 0;
        for (int i = k - 1; i < n; ++i) {
            sum = (sum + a[i] * C[i][k - 1]) % MOD;
        }
        printf("Case #%d: %d\n", __it, int(sum));
    }
          
    return 0;
}
