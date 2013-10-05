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

int a[4444];


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, cnt = 0, s = 0;
    cin >> n;
    for (int i = 0; i < n + n; ++i) {
        int p1;
        scanf("%d.%d", &p1, &a[i]);
        s += a[i];
        if (a[i] == 0) ++cnt;
    }

    int ans = 2e9;
    for (int i = max(0, cnt - n); i <= n && i <= cnt; ++i)
        if (abs(s - 1000 * (n - i)) < ans)
            ans = abs(s - 1000 * (n - i));

    printf("%d.%03d\n", abs(ans) / 1000, abs(ans) % 1000);
    return 0;
}
