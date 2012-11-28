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
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL f[22], c[22];
LL tt[1111111], cc[1111111];
int n, m;
LL V, T;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> f[i] >> c[i];
    }

    tt[0] = 0;
    cc[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) if (i & (1 << j)) {
            tt[i] = f[j] + tt[i ^ (1 << j)];
            cc[i] = c[j] + cc[i ^ (1 << j)];
            break;
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> V >> T;
        LL ans = LL(1e18);
        for (int k = 1; k < (1 << n); ++k) {
            LL ho = (V + tt[k] - 1) / tt[k];
            if (ho <= T) {
                ans = min(ans, cc[k]);
            }
        }
        cout << "Case " << (i + 1) << ": ";
        if (ans > 1e17) cout << "IMPOSSIBLE\n";else  cout << ans << endl;
    }
    
    return 0;
}
