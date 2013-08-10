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


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    LL x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    LD r1 = sqrtl(x1 * x1 + y1 * y1);
    LD r2 = sqrtl(x2 * x2 + y2 * y2);
    LD a1 = atan2(y1, x1);
    LD a2 = atan2(y2, x2);
    LD da = min(fabsl(a1 - a2), 2 * PI - fabsl(a1 - a2));
    LD ans = 0;
    if (da > 2) 
        ans = r1 + r2;else
        ans = fabsl(r1 - r2) + da * min(r1, r2);
    cout.precision(13);
    cout << fixed << ans << endl;
    
    return 0;
}
