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

int n, pr[111], IT, was[111];
vector<int> g[111];
LD ans = 0, t, disA[111], disB[111], d[111][111];
struct {
    LD x, y;
} a[111], b[111];

bool kuhn(int x) {
    if(was[x] == IT) return false;
    was[x] = IT;
    for (int i = 0; i < g[x].size(); ++i)
        if (pr[g[x][i]] == -1 || kuhn(pr[g[x][i]])) {
            pr[g[x][i]] = x;
            return true;
        }
    return false;
}

bool Can(LD c) {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        for (int j = 0; j < n; ++j) {
            if (c >= d[i][j] * 2 + disA[i] + disB[j]) {
                g[i].push_back(j);
            }
        }
    }
    memset(pr, -1, sizeof(pr));
    for (int i = 0; i < n; ++i) {
       ++IT;
        if (!kuhn(i)) return false;
    }
    return true;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> t;    
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 0; i < n; ++i) cin >> b[i].x >> b[i].y;
    for (int i = 0; i < n; ++i) {
        disA[i] = min(min(a[i].x, a[i].y), min(1 - a[i].x, 1 - a[i].y));
        disB[i] = min(min(b[i].x, b[i].y), min(1 - b[i].x, 1 - b[i].y));
        for (int j = 0; j < n; ++j) {
            d[i][j] = sqrtl(sqr(a[i].x - b[j].x) + sqr(a[i].y - b[j].y));
        }
    }
    LD left = 0;
    LD right = 100;
    while ((right - left) > 1e-4) {
        LD c = (left + right) / 2;
        if (Can(c)) right = c;else left = c;
    }
    cout.precision(12);
    cout <<fixed;
    cout << (right + left) / (2 * t) << endl;
    
    return 0;
}
