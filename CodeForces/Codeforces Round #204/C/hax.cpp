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

typedef LL TMat[444][444];

TMat d, t, e;
LL a[44], b[44];
int N;

void mul(TMat& c, TMat& a, TMat& b) {
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= N; ++j) {
            c[i][j] = 1e18;
            for (int k = 0; k <= N; ++k)
                if (a[i][k] + b[k][j] < c[i][j]) {
                    c[i][j] = a[i][k] + b[k][j];
                }
        }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    N = 60;

    memset(d, 63, sizeof(d));
    for (int i = 0; i < (1 << n); ++i) {
        int c = 0;
        int cost = 0;
        int mi = 0;
        for (int j = 0; j < n; ++j)
            if ((1 << j) & i) {
                ++c;
                cost += a[j];
            } else {
                --c;
                if (c < mi) mi = c;
                cost += b[j];
            }
        for (int j = -mi; j <= N; ++j)
            if (j + c >= 0 && j + c <= N) {
//                cerr << j << " " << j + c << " " << cost << endl;
                d[j][j + c] = min(d[j][j + c], (LL)cost);
            }
    }
    memset(e, 63, sizeof(e));
    for (int i = 0; i <= N; ++i) e[i][i] = 0;
    while (m) {
        if (m & 1) {
            mul(t, e, d);
            memcpy(e, t, sizeof(e));
        }
        m >>= 1;
        mul(t, d, d);
        memcpy(d, t, sizeof(d));
    }
    cout << e[0][0] << endl;
    cerr << clock() << endl;

    return 0;
}
