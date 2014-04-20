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

#define N 211

int q, p, n, x, y;
struct Tp {
    int x, y;
    int i;

    bool operator<(const Tp& b) const {
        return y < b.y || (y == b.y && x < b.x);
    }
} a[N], b[N], st1[N], st2[N];

int mul(Tp& a, Tp& b, Tp& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool in(Tp* s, int n, int x) {
    for (int i = 0; i < n; ++i)
        if (s[i].i == x)
            return true;
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &p, &q, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
            a[i].i = i;
        }
        int stn1 = 0, stn2 = 0;
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            while (stn1 > 1 && mul(st1[stn1 - 2], st1[stn1 - 1], a[i]) > 0) --stn1;
            while (stn2 > 1 && mul(st2[stn2 - 2], st2[stn2 - 1], a[i]) < 0) --stn2;
            st1[stn1++] = a[i];
            st2[stn2++] = a[i];
        }
        int face = 0;
        int dent = 0, opendent = 0;
        for (int i = st1[0].i; i < st1[0].i + n; ++i) {
            if ( (in(st1, stn1, i % n) || in(st2, stn2, i % n)) && (in(st1, stn1, (i + 1) % n) || in(st2, stn2, (i + 1) % n)) ) {
                ++face;
            } else 
            if ( (in(st1, stn1, i % n) || in(st2, stn2, i % n)) && !(in(st1, stn1, (i + 1) % n) || in(st2, stn2, (i + 1) % n))) {
                ++dent;
            }
        }
        cout << max(0, face * q - dent * p) << endl;
    }
    
    return 0;
}
