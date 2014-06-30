#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

typedef long long LL;
typedef long double LD;

struct Tp {
    int x1, y1, x2, y2;
} a[5555];
LL DD[5555];
int was[5555];
int D[5555][5555];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;
    int S = n;
    int F = n + 1;
    //memset(D, 63, sizeof(D));
    D[S][F] = D[F][S] = h;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

        D[i][S] = D[S][i] = a[i].y1;
        D[i][F] = D[F][i] = h - a[i].y2;

        for (int j = 0; j < i; ++j) {
            int d = max(max(a[i].y1 - a[j].y2, a[j].y1 - a[i].y2), max(a[i].x1 - a[j].x2, a[j].x1 - a[i].x2));
            D[i][j] = D[j][i] = d;
        }
    }

    memset(DD, 63, sizeof(DD));
    DD[S] = 0;
    for (int it = 0; it <= F; ++it) {
        LL mind = 1e18;
        int mi = -1;
        for (int i = 0; i <= F; ++i) if (!was[i] && DD[i] < mind) {
            mind = DD[i];
            mi = i;
        }
        if (mi == -1) continue;
        was[mi] = 1;
        for (int i = 0; i <= F; ++i)
            if (DD[mi] + D[mi][i] < DD[i])
                DD[i] = DD[mi] + D[mi][i];
    }
    cout << DD[F] << endl;

    return 0;
}
