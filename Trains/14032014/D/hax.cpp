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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 222;

struct Tp {
    int x, y;

    bool operator<(const Tp& t) const {
        return y < t.y || (y == t.y && x < t.x);
    }
} a[N], A[N];
int h[N], hn = 0, hy[N], hny, l[N], r[N];

bool InDoubled(int x, int y) {    
    for (int i = 0; i < n; ++i) {
        
    }
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        h[hn++] = a[i].x;
        A[i] = a[i];
    }
    A[n] = A[0];

    sort(h, h + hn);
    hn = unique(h, h + hn) - h;

    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && a[j + 1].y == a[i].y) ++j;

        hy[hny] = a[i].y;
        l[hny] = -1;
        r[hny] = -1;

        for (int k = 0; k < hn; ++k)
            if ( InDoubled(h[k] + h[k + 1], a[i].y * 2) ) {
                if (l[hny] == -1)
                    l[hny] = k;
                r[hny] = k + 1;
            }

        ++hny;
    }
    
    return 0;
}
