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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

double l;
int n;
int w[111];

double f[111][111][111];

inline void relax(double &x, double y) {
    if (x > y) x = y;
}

struct Tp {
    double x;
    int t;
    bool operator<(const Tp& T) const  {
        return x < T.x || x == T.x && t > T.t;
    }
} ev[333], ev2[333], ev3[333];

inline double calc(int i, int j, int k, int kk) {
    if (i == j) {
        return 0;
    }

    double w1 = l;
    for (int it = i; it < j; ++it) w1 -= w[it];
    w1 /= j - i - 1;

    double w2 = l;
    for (int it = j; it < k; ++it) w2 -= w[it];
    w2 /= k - j - 1;

    double w3 = l;
    if (kk == n) {
        w3 = 1;
    } else {
        for (int it = k; it < kk; ++it) w3 -= w[it];
        w3 /= kk - k - 1;
    }

    double x;
    int en = 0;
    
    x = w[i];
    for (int it = i; it < j - 1; ++it) {
        ev[en].x =  x;
        ev[en].t = +1;
        ++en;

        ev[en].x =  x + w1;
        ev[en].t = -1;
        ++en;

        x += w[it + 1] + w1;
    }
    int en1 = en;

    x = w[j];
    for (int it = j; it < k - 1; ++it) {
        ev[en].x =  x;
        ev[en].t = +1;
        ++en;

        ev[en].x =  x + w2;
        ev[en].t = -1;
        ++en;

        x += w[it + 1] + w2;
    }
    int en2 = en;
    
    x = w[k];
    for (int it = k; it < kk - 1; ++it) {
        ev[en].x =  x;
        ev[en].t = +1;
        ++en;

        ev[en].x =  x + w3;
        ev[en].t = -1;
        ++en;

        x += w[it + 1] + w3;
    }
    int en3 = en;
    
    int eev1 = merge(ev, ev + en1, ev + en1, ev + en2, ev2) - ev2;
    int eev2 = merge(ev2, ev2 + eev1, ev + en2, ev + en3, ev3) - ev3;

    double ans = 0;
    int cnt = 0;
    for (int i = 0; i < eev2; ++i) {
        if (cnt == 3) {
            ans += ev3[i].x - ev3[i - 1].x;
        }
        if (ev3[i].t == +1) {
            ++cnt;
        } else {
            --cnt;
        }
    }

    return ans;
}

int main() {
    freopen("formatting.in", "r", stdin);
    freopen("formatting.out", "w", stdout);
    
    string s;
    cin >> l;
    while (cin >> s) w[n++] = s.length();

    for (int i = 0; i <= n; ++i) for (int j = i; j <= n; ++j) for (int k = j; k <= n; ++k) f[i][j][k] = 1e100;

    double ans = 1e100;
    f[0][0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = j; k <= n; ++k) if (f[i][j][k] < 1e100) {
//                cerr << i << " " << j << " " << k << " " << f[i][j][k] << endl;

                if (k + 1 == n) {
                    relax(f[j][k][n], f[i][j][k] + calc(i, j, k, n));                    
                } else {
                    int tl = w[k] + w[k + 1] + 1;
                    assert(tl <= l);
                    for (int kk = k + 2; kk <= n; ++kk) {
                        relax(f[j][k][kk], f[i][j][k] + calc(i, j, k, kk));

                        tl += w[kk] + 1;
                        if (tl > l) break;
                    }
                }
            }
            relax(ans, f[i][j][n]);
        }
    }
    cout << ans << endl;
    
    return 0;
}
