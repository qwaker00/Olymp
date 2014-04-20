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

const int N = 111111;

LL s[N];
int n, k, a[N];

bool ByS(int x, int y) {
    return s[x] < s[y];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d", &n, &k);
    s[0] = 0;
    for (int i = 1; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] + x;
    }

    for (int i = 0; i < n; ++i) a[i] = i;
    sort(a, a + n, ByS);

    LL ss = 0, ans = 1e18, ansi = 1;
    for (int i = 1; i < n; ++i) {
        ss += llabs(s[a[i]] - s[a[i - 1]]);
        if (i >= k) ss -= llabs(s[a[i - k + 1]] - s[a[i - k]]);
        if (i >= k - 1 && ss < ans) {
            ans = ss;
            ansi = i;
        }
    }

    cout << ans << endl;
    for (int i = ansi - k + 1; i <= ansi; ++i) {
        printf("%d ", a[i] + 1);
    } 
    puts("");

    return 0;
}
