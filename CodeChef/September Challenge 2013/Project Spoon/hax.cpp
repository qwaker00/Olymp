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

ULL c[66][66];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    for (int i = 0; i < 65; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            assert(c[i][j] < 2e18);
        }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        ULL x;
        scanf("%lld", &x);
        int i = 1;
        for (; i < 65; ++i) if (c[i][i / 2] >= x) break;
        printf("%d\n", i);
    }
    
    return 0;
}
