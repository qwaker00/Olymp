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

    LL n, x, y, q;
    cin >> n >> x >> y >> q;
    while (q--) {
        LL k;
        cin >> k;
        --k;
        int l = 0, e[2] = {0, 0};
        while (k) {
            e[l & 1] += k & 1;
            k >>= 1;
            ++l;
        }
        if (n & 1) swap(e[0], e[1]);
        cout << e[0] + ((n + 1) / 2) - e[1] << " " << e[1] + (n / 2) - e[0] << endl;
    }

    return 0;
}
