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

const int N = 105;

int __it;
int mem[N][202][N * 11];
int h[111], g[111];
int n, p, q;
const int INF = 1e9;

int calc(int i, int hi, int dt) {
    if (dt > 1) return -INF;
    if (i == n) return 0;
    int& ans = mem[i][hi][-dt + 1];
    if (ans != -1) return ans;
    ans = -INF;
    if (hi > p)
        ans = max(ans, calc(i, hi - p, dt + 1));
    else
        ans = max(ans, calc(i + 1, h[i + 1], dt + 1) + g[i]);
    if (hi > q)
        ans = max(ans, calc(i, hi - q, dt - 1));
    else
        ans = max(ans, calc(i + 1, h[i + 1], dt - 1));
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    for (__it = 1; __it <= T; __it++) {
        cerr << __it << endl;
        cin >> p >> q >> n;
        //if (__it == 78) cerr << p << " " << q << " " << n  << endl;
        for (int i = 0; i < n; ++i) {
            cin >> h[i] >> g[i];
            //if (__it == 78) cerr << h[i] << " " << g[i] << endl;           
        }    
        memset(mem, -1, sizeof(mem));
        int ans = calc(0, h[0], 0);
        cout << "Case #" << __it << ": " << ans << endl;
    }
    
    return 0;
}
