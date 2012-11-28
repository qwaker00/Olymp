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

#define N 222
#define M N*N

struct Tp {
    LL x, y;
} a[N];

LD Dist(Tp& a, Tp &b) {
    return sqrtl(LL(a.x - b.x) * (a.x - b.x) + LL(a.y - b.y) * (a.y - b.y));
}

int n, m, x, y, d;
LD len[M];
int xx[M], yy[M], pp[M], xxx[M], w[M];
LD D[M];
vector< pair<LD, int> > to[M];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[i].x = x;
        a[i].y = y;
    }

    int kk = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        --x; --y;
        yy[++kk] = y; pp[kk] = xx[x]; xx[x] = kk;
        xxx[kk] = x;
    }

    for (int i = 0; i < n; i++) {
        for (int j = xx[i]; j; j = pp[j]) {

            len[j] = Dist(a[xxx[j]], a[yy[j]]);
//            cerr << xxx[j] << " " << yy[j] << endl;

            int A = xxx[j];
            int B = yy[j];

            for (int k = xx[B]; k; k = pp[k]) {
                int C = yy[k];


                LD ang = (LL(a[B].x - a[A].x) * (a[C].x - a[B].x) + LL(a[B].y - a[A].y) * (a[C].y - a[B].y)) / len[j] / Dist(a[B], a[C]);
//                if (ang > PI) ang -= PI + PI;

                to[j].push_back(
                    make_pair(
                        fabsl( acosl(ang) * 180. / PI),
                        k
                    )
                );
            }
            sort(to[j].begin(), to[j].end());
        }
    }

    LD left = 0;
    LD right = 181.;
    for (int it = 0; it < 100; it++) {
        LD center = (left + right) / 2.;

        for (int i = 0; i <= m; i++) {
            D[i] = 1e18;
            w[i] = 0;
        }

        deque<int> q;

        bool found = false;
        for (int i = xx[0]; i; i = pp[i]) {
            if (len[i] > d) continue;
            if (yy[i] == n - 1) {
               found = true;
               break;
            }
            D[i] = len[i];
            q.push_back(i);
            w[i] = 1;
        }

        while (!q.empty() && !found) {
            int x = q.front(); q.pop_front();
            w[x] = 2;
//            cerr << xxx[x] << " " << yy[x] << " " << D[x] << endl;

            for (size_t i = 0; i < to[x].size(); ++i) {
                const pair<LD, int>& t = to[x][i];
                if (t.first > center) break;
                if (len[t.second] + D[x] > d) continue;

                if (len[t.second] + D[x] < D[t.second]) {
                    if (yy[t.second] == n - 1) {
                        found = true;
                        break;
                    }

                    D[t.second] = len[t.second] + D[x];
                    if (w[t.second] == 2)
                        q.push_front(t.second);else
                    if (w[t.second] == 0)
                        q.push_back(t.second);
                    w[t.second] = 1;
                }
            }
        }
        if (found) right = center;else left = center;

//        cerr << "===" << endl;
    }

    if (right > 180.5) {
        puts("Impossible");
    } else {
        cout.precision(15);
        cout << fixed << left << endl;
    }
    
    return 0;
}
