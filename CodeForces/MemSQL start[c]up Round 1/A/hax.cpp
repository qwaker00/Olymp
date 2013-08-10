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
    int x, y, xx, yy;
} a[11];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    int minx = 2e9, miny = 2e9, maxx = -2e9, maxy = -2e9;
    LL s1 = 0, s2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].xx >> a[i].yy;
        if (minx > a[i].x) minx = a[i].x;
        if (miny > a[i].y) miny = a[i].y;
        if (maxx < a[i].xx) maxx = a[i].xx;
        if (maxy < a[i].yy) maxy = a[i].yy;
        s1 += LL(a[i].xx - a[i].x) * LL(a[i].yy - a[i].y);
    }
    s2 = LL(maxx - minx) * LL(maxy - miny);
    if (s1 == s2 && (maxx -  minx == maxy - miny)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
