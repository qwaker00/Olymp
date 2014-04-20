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

bool byl(int x, int y) {
    return log(x) * y < log(y) * x;
}

int a[111111], b[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        sort(a, a + n, byl);
        sort(b, b + n, byl);

        double ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && byl(b[j], a[i])) {
                ++j;
            }
            ans += j;
        }
        ans /= n;
        printf("%.12lf\n", ans);
    }    
    return 0;
}
