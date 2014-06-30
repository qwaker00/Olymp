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
#include <assert.h>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int a[111111], _f1[311], _f2[311], *f1 = _f1, *f2 = _f2;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
   
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            int b;
            scanf("%d", &b);
            int v = (b - a[i] + 4000) & 3;


        }
        int ans = 1e9;
        for (int i = 0; i <= 300; ++i) {
            ans = min(ans, f1[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
