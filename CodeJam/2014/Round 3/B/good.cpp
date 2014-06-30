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

const int N = 5;

int __it, IT = 0;
int was[N][202][11 * N][11 * N];
int mem[N][202][11 * N][11 * N], h[111], g[111];
int n, p, q;
const int INF = 1e9;

int calc(int i, int hi, int t1, int t2) {
    if (t1 > t2 + 1) return -INF;
    if (i == n) return 0;
    if (t1 >= 11 * N || t2 >= 11 * N) return -INF;

    if (was[i][hi][t1][t2] == IT) return mem[i][hi][t1][t2];
    int& ans = mem[i][hi][t1][t2] = -INF;
    was[i][hi][t1][t2] = IT;

    if (hi > p)
        ans = max(ans, calc(i, hi - p, t1 + 1, t2));
    else
        ans = max(ans, calc(i + 1, h[i + 1], t1 + 1, t2) + g[i]);

    if (hi > q)
        ans = max(ans, calc(i, hi - q, t1, t2 + 1));
    else
        ans = max(ans, calc(i + 1, h[i + 1], t1, t2 + 1));

    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    for (__it = 1; __it <= T; __it++) {

        cin >> p >> q >> n;
        //if (__it == 78) cerr << p << " " << q << " " << n  << endl;
        for (int i = 0; i < n; ++i) {
            cin >> h[i] >> g[i];
            //if (__it == 78) cerr << h[i] << " " << g[i] << endl;           
        }

        ++IT;
        int ans = calc(0, h[0], 0, 0);
        cout << "Case #" << __it << ": " << ans << endl;
    }
    
    return 0;
}
