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

struct Tp { 
    int x, y;

    bool operator<(const Tp& B) const {
        return x < B.x || (x == B.x && y > B.y);
    }

} a[255], b[255];
int del[255];
LD D[255][255];
LL dg[255][255];
pair<LD, int> nei[255][255];


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, w;

        scanf("%d%d%d", &n, &m, &w);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &b[i].x, &b[i].y);
        }
        sort(b, b + m);

        memset(del, false, sizeof(del));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                if (b[j].y >= b[i].y) {
                    del[j] = true;
                }
            }
        }
        int mn = 0;
        for (int i = 0; i < m; ++i) if (!del[i])
            b[mn++] = b[i];
        m = mn;

        for (int i = 0; i < n; ++i) 
            for (int j = i; j < n; ++j)
                D[i][j] = D[j][i] = sqrtl(sqr(LL(a[i].x) - a[j].x) + sqr(LL(a[i].y) - a[j].y));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (i != j) {
                nei[i][j - (i <= j)] = make_pair(D[i][j], j);
            }
            sort(nei[i], nei[i] + n - 1);
        }
        

        LL ans = -1;
        memset(dg, 127, sizeof(dg));
        priority_queue< pair<LL, pair<int, int> > > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (a[i].y <= b[j].x) {
                dg[i][j] = b[j].y;
                q.push(make_pair(-dg[i][j], make_pair(i, j)));
                break;
            }
        }
        while (!q.empty()) {
            pair<LL, pair<int, int> > t = q.top(); q.pop();
            const LL d = -t.first;
            const pair<int, int> x = t.second;
            if (d != dg[x.first][x.second]) continue;
            
            if (x.first == n) {
                ans = d;
                break;
            }
            if (x.second + 1 < m) {
                LL dd = d + b[x.second + 1].y - b[x.second].y;
                if (dg[x.first][x.second + 1] > dd) {
                    dg[x.first][x.second + 1] = dd;
                    q.push(make_pair(-dd, make_pair(x.first, x.second + 1)));
                }
            }
            if (a[x.first].y + b[x.second].x >= w) {
                if (dg[n][0] > d) {
                    dg[n][0] = d;
                    q.push(make_pair(-d, make_pair(n, 0)));
                }
            }

            pair<LD, int>* nn = nei[x.first];
            for (int i = 0, j = 0; j < m && i + 1 < n; ) {
                if (nn[i].first - 1e-8 > b[x.second].x + b[j].x) {
                    ++j;
                    continue;
                }
                LL dd = d + b[j].y;
                if (dg[nn[i].second][j] > dd) {
                    dg[nn[i].second][j] = dd;
                    q.push(make_pair(-dd, make_pair(nn[i].second, j)));
                }
                ++i;
            }
        }
                               /*
        for (int i = 0; i < n; ++i) {
            cerr << a[i].x << "," << a[i].y << ": ";
            for (int j = 0; j < m; ++j) {
                if (dg[i][j] < 1e9) {
                    cerr << dg[i][j] << " ";
                } else {
                    cerr << "inf ";
                }
            }
            cerr << endl;
        }
                                 */
        if (ans == -1) {
            puts("impossible");
        } else {
            cout << ans << endl;
        }
    }
    
    return 0;
}
