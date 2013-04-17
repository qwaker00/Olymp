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

int a[55][55], d[55][55], T, n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i <= n + 1; i++) a[i][0] = 0;
        for (int i = 0; i <= m + 1; i++) a[0][i] = 0;
        for (int i = 0; i <= n + 1; i++) a[i][m + 1] = 0;
        for (int i = 0; i <= m + 1; i++) a[n + 1][i] = 0;

        memset(d, 63, sizeof(d));
        queue< pair<int, int> > q;
        q.push(make_pair(0, 0));
        d[0][0] = 0;
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int xx = t.first + dx[i];
                int yy = t.second + dy[i];
                if (xx < 0 || yy < 0 || xx > n + 1 || yy > m + 1) continue;
                if (d[xx][yy] <= max(d[t.first][t.second], a[xx][yy]) ) continue;
                d[xx][yy] = max(d[t.first][t.second], a[xx][yy]);
                q.push(make_pair(xx, yy));
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) ans += d[i][j] - a[i][j];
        cout << ans << endl;
    }    
    
    return 0;
}
