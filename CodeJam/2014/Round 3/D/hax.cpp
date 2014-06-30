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

const int N = 88;

int c[N], c2[N];
int d[N][N], d2[N][N];
int cc[N][N];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    for (int __it = 1; __it <= T; __it++) {
        
        int n;
        cin >> n;
        memset(d, 63, sizeof(d));
        for (int i = 1; i <= n; ++i) cin >> c[i];
        for (int x = 1; x < n; ++x) {
            int y;
            cin >> y;

            d[x][y] = 1;
            d[y][x] = 1;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        int ans = 0;
        for (int sx = 1; sx <= n; ++sx) {
            for (int sy = 1; sy <= n; ++sy) if (sx != sy) {
                int x = sx;
                int y = sy;
                int cx = 0;    
                int cy = 0;
                int turn = 0;
                memcpy(c2, c, sizeof(c));
                memcpy(d2, d, sizeof(d));
                while (true) {
                    if ((++turn) & 1) {
                        if (x == -1) continue;

                        int to = -1;                        
                        for (int j = 1; j <= n; ++j) {
                            if (d2[x][j] == 1 && d2[j][y] >= d2[x][y]) {
                                ans = max(ans, cx + maxcost(x, j));
                            } else
                            if (d2[x][j] == 1) {
                                to = j;
                            }
                        }
                        x += c2[x];
                        c2[x] = 0;

                        if (to != -1)
                            d[x][to] = d[to][x] = 0;

                        x = to;
                    } else {
                        
                    }
                }

            }
        }

        cout << "Case #" << __it << ": " << ans << endl;
    }
    
    return 0;
}
