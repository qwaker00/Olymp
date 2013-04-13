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

int IT = 0, was[355][355];
int t, n, a[355][355];
int id[10000005];
bool f[10000005];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int cnt = 0;
    for (int i = 2; i < 10000000; ++i) if (!f[i]) {
        id[i] = ++cnt;
        if (i < 45000)
        for (int j = i * i; j < 10000000; j += i)
            f[j] = true;
    }

    int IT = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &a[i][j]);
        
        ++IT;
        LL ans = 0;
        queue< pair<int, int> > q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (id[ a[i][j] ]) {
                    ans += id[ a[i][j] ] - 1;
                } else {
                    if (was[i][j] == IT) continue;

                    ans += (a[i][j] >> 1);
                    if (a[i][j] & 1) ans += 2;

                    q.push(make_pair(i, j));
                    was[i][j] = IT;
                    while (!q.empty()) {
                        pair<int, int> fr = q.front(); q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int xx = fr.first + dx[k];
                            int yy = fr.second + dy[k];
                            if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
                            if (was[xx][yy] == IT || id[ a[xx][yy] ] || ((a[xx][yy] + a[i][j]) & 1)) continue;
                            was[xx][yy] = IT;
                            q.push(make_pair(xx, yy));
                        }
                    }
                }
        cout << ans << endl;
    }

    return 0;
}
