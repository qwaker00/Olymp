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


int n;
struct Tp {
    LL x, y;
} a[222];

LD at[222][222];
bool can[222][222];

#define eps 1e-12


inline bool AngBetween(LD a, LD l, LD r) {
    if (a < l) a += 2 * PI;
    return a >= l - eps && a <= r + eps;
}

bool Can(LD angle) {
    memset(can, 0, sizeof(can));
    queue< pair<int, int> > q;
    for (int i = 1; i < n; ++i) {
        can[0][i] = 1;
        q.push(make_pair(0, i));
    }
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        LD a1 = at[t.second][t.first];

        for (int i = 0; i < n; ++i) if (i != t.second && !can[t.second][i]) {
           LD a2 = at[i][t.second];
           if (AngBetween(a2, a1, a1 + angle)) {
               if (i == 0) return true;

               can[t.second][i] = true;
               q.push(make_pair(t.second, i));
           }
        }
    }
//    for (int i = 1; i < n; ++i) if (can[i][0]) return true;
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j)
            at[i][j] = atan2l(a[j].y - a[i].y, a[j].x - a[i].x);
    }


    LD left = 0;
    LD right = PI;
    for (int it = 0; it < 50; ++it) {
        LD center = (left + right) / 2;
        if (Can(center)) right = center;else left = center;
    }
    cout.precision(16);
    cout << fixed << 180 * left / PI << endl;
    cerr << clock() << endl;
    
    return 0;
}
