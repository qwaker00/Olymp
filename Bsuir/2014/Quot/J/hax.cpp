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

//int f[111][111][111];

bool Oracle(LL x, LL y, LL z) {
    if ((x + y + z) & 1) return 1;
    if ((x & 1) && ( (abs(x - y) == 1 && (y&1) == 0) || (abs(y - z) == 1 && (z&1) == 0))) return 1;
//    if ((x + y) & 1) return 1;
//    if ((x + z) & 1) return 1;
//    if ((z + y) & 1) return 1;
    return 0;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    

/*    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            for (int k = 0; k < 100; ++k) {
                if (j && j == k) f[i][j][k] = f[i][j][0];else
                if (i && i == k) f[i][j][k] = f[i][j][0];else
                if (i && i == j) f[i][j][k] = f[i][0][k];else {
                    f[i][j][k] = 0;
                    if (i > 0 && f[i - 1][j][k] == 0) f[i][j][k] = 1;
                    if (j > 0 && f[i][j - 1][k] == 0) f[i][j][k] = 1;
                    if (k > 0 && f[i][j][k - 1] == 0) f[i][j][k] = 1;
                }
            }
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            for (int k = 0; k < 100; ++k) {
                if (i < j && j < k && f[i][j][k] != Oracle(i, j, k))
                    cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
            }
*/
    int n;
    LL a[3];
    cin >> n;
    for (int i= 0; i < n; ++i) cin >> a[i];
    sort(a, a + 3);
    cout << 2 - Oracle(a[0], a[1], a[2]) << endl;            
    return 0;
}
