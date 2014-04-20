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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n, mxv = -2e9, miv = 2e9, mxi = 0, mii = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int s = abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
        if (s >= mxv) {
            mxv = s;
            mxi = i;
        }
        if (s <= miv) {
            miv = s;
            mii = i;
        }
    }
    cout << mii + 1 << " " << mxi + 1 << endl;
    
    return 0;
}
