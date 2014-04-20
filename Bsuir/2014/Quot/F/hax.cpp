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
    
    int n;
    LL m;
    cin >> n >> m;
    LL prevt = 0;
    LL t, ans = 0;
    for (int i = 0; i < n; ++i) {
        prevt = t;
        cin >> t;
        if (i == 0) {
            ans = m * t;
        } else {
            if (t >= prevt)
                ans = ans - m * prevt + prevt + m * t;
            else
                ans = ans + t;
        }
        cout << ans << "\n";
    }
    
    return 0;
}
