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


    LL X, Y;
    cin >> X >> Y;

    LL ans = 9e18;
    LL c = 0;
    while (Y > X) {
        ans = min(ans, c + (Y - X) / 2 + ((Y - X) & 1) );
        if (Y & 1) --Y, ++c;
        Y /= 2;
        ++c;
    }
    if (Y == X) ans = min(ans, c);

    cout << ans << endl;
    
    return 0;
}
