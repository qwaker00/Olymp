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


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    cin >> T;
    while (T--) {
        cin >> n >> m >> k;

        memset(f, 0, sizeof(f));
        memset(c, 63, sizeof(c));

        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> z;
            f[x][y] = f[y][x] = n;
            c[x][y] = c[y][z] = min(c[y][x], z);
        }
        for (int i = 1; i <= k; ++i) {
            f[0][i] = f[i][0] = n;
            c[0][i] = c[i][0] = 0;
            f[n+1][n - i + 1] = f[n - i + 1][n+1] = n;
            c[n+1][n - i + 1] = c[n - i + 1][n+1] = 0;
        }

        LL sum = 0;
        for (int it = 0; it < k; ++it) {
            if (!bfs()) {
                sum = -1;
                break;
            }
            sum += D[n + 1];

            int x = n + 1;
            while (x) {
                --f[pr[x]][x];
                ++f[x][pr[x]];
            }
        }
        if (sum == -1) puts("No solution");else cout << sum << endl;
    }
    
    return 0;
}
