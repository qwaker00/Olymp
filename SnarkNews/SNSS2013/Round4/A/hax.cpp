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

bool btw(int x, int y, int z) {
    return abs(x - y) + abs(x - z) == abs(y - z);
}

int n;
int sf, sx, sy;
int ff;
int was[5555];

struct Tp {
    int x, y, s, f;
} a[5555];

double Dist(int x, int y, int xx, int yy) {
    return sqrtl((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

double D[5555];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    scanf("%d%d", &sf, &ff);
    scanf("%d%d", &sx, &sy);
    if (sf == ff) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].s, &a[i].f);
        if (btw(sf, a[i].s, a[i].f) && sx == a[i].x && sy == a[i].y) sf = a[i].f;
    }

    for (int i = 0; i < n; ++i) D[i] = 1e100;
    for (int i = 0; i < n; ++i)
        if (btw(sf, a[i].s, a[i].f)) {
            D[i] = Dist(a[i].x, a[i].y, sx, sy);
        }
    while (true) {
        double mi = 1e100;
        int mii = -1;
        for (int j = 0; j < n; ++j) if (!was[j] && D[j] < mi) {
            mi = D[j];
            mii = j;
        }
        if (mii == -1) break;
        if (a[mii].f == ff) {
            cout.precision(12);
            cout << fixed;
            cout << mi << endl;
            return 0;
        }

        was[mii] = true;
        for (int j = 0; j < n; ++j) 
            if (!was[j] && btw(a[mii].f, a[j].s, a[j].f)) {
                double dd = mi + Dist(a[mii].x, a[mii].y, a[j].x, a[j].y);
                if (dd < D[j]) D[j] = dd;
            }
    }

    puts("-1");
    
    return 0;
}
