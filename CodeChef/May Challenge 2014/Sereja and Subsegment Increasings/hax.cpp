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

int a[111111];

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
        int last = 0, ans = 0, opened = 0;
        for (int i = 0; i < n; ++i) {
            int b;
            scanf("%d", &b);
            int diff = (b - a[i] + 4) & 3;
            if ( ((last - diff + 4) & 3) <= opened) {
                opened -= ((last - diff + 4) & 3);
            } else {
                opened += ((diff - last + 4) & 3);
                ans += ((diff - last + 4) & 3);
            }
            last = diff;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
