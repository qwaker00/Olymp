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


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, k, p;
    cin >> n >> k >> p;
    if (p == 100) {
        cout << 1 << endl;
        cout << 0;
        for (int i = 2; i <= n; ++i) {
            cout << " " << 1;
        }
        cout << endl;
        return 0;
    } else if (p < 50) {
        for (int x = 0; x <= k; ++x) {
            if ((x * p % (50 - p)) == 0) {
                int y = x * p / (50 - p);
                if (x + y > 0 && y >= 0 && y <= (n - 1) * k) {

                    assert(p * (x + y)== 50 * y);

                    cout << 1 << endl;
                    cout << x;
                    for (int i = 2; i <= n; ++i) {
                        cout << " " << min(k, y);
                        y -= min(k, y);
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;

    return 0;
}
