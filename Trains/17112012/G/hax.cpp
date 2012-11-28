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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


#define N 111111

int w, n, ans = 0, x[N], y[N], xx[N], yy[N];


bool Eq(int x1, int y1,
        int x2, int y2,
        int x3, int y3,
        int x4, int y4)
{
    int A = y2 - y1;
    int B = x1 - x2;
    int C = -A * x1 - B * y1;

    return A * x3 + B * y3 + C == 0 &&
           A * x4 + B * y4 + C == 0;
}

bool Par(int x1, int y1,
        int x2, int y2,
        int x3, int y3,
        int x4, int y4)
{
    int A1 = y2 - y1;
    int B1 = x1 - x2;
    int A2 = y4 - y3;
    int B2 = x3 - x4;
    return A1 * B2 == A2 * B1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> xx[i] >> yy[i];
        bool bad = false;
        for (int j = 0; j < i; j++) if (Eq(x[i], y[i], xx[i], yy[i], x[j], y[j], xx[j], yy[j])) {
            bad = true;
            break;
        }
        ans += !bad;
    }

    bool allPar = true;
    for (int i = 1; i < n; i++) {
        allPar &= Par(x[i], y[i], xx[i], yy[i], x[i-1], y[i-1], xx[i-1], yy[i-1]);
    }

    int mi = 0;
    if (allPar) {
        if (ans + 1 >= w) {
            cout << 0 << endl;
            return 0;
        } else {
            mi = 1;
        }
    }

    cout << max(mi,  (w + 1)/2 - ans) << endl;
    
    return 0;
}
