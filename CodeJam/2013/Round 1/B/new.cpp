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

#define double LD
#define mp make_pair
typedef vector< pair<int, int> > vp;

map<vp, double> A[22];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        int n;
        cin >> n;

        int x, y;
        cin >> x >> y;

        if (x < 0) x = -x;
        int dnum = (x + y) / 2;
        int pirc = 2 * dnum * dnum - dnum;

        double ans = 0;
        if (n <= pirc) {
            ans = 0;
        } else {
            n -= pirc;
            if (n >= dnum * 4 + 1) {
                ans = 1.;
            } else {
                if (y == dnum * 2) {
                    ans = 0;                        
                } else {
                    if (n >= dnum * 2 + y + 1) {
                        ans = 1.;
                    } else {
                    LD Cnk = 1;
                    LD subans = 0;
                    for (int k = 0; k <= y; ++k) {
                        subans += Cnk;
                        Cnk *= LD(n - k) / (k + 1);
                    }
                    ans = 1. - subans / powl(2, n);
                    }
                }
            }
        }
//        if (ans < 0) ans = 0;
        cout.precision(12);
        cout << "Case #" << __it << ": " << fixed << ans << endl;
    }    
    
    return 0;
}
