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


int n, m, a[101], b[101];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            ++a[x];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int c;
            scanf("%d", &c);
            for (int j = 0; j < c; ++j) scanf("%d", &b[j]);
            sort(b, b + c);
            for (int j = max(c - a[i], 0); j < c; ++j) ans += b[j];
        }
        printf("%d\n", ans);
    }    
    return 0;
}
