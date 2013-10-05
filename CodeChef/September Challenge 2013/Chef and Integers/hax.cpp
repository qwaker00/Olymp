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


int n;
int x;
int a[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &x);
    sort(a, a + n);
    while (n > 0 && a[n - 1] >= 0) --n;
    
    LL ans = 0;
    if (x < n) {
        ans = LL(x) * (-a[x - 1]);
        for (int i = 0; i < x - 1; ++i) ans += a[x - 1] - a[i];
    } else {
        for (int i = 0; i < n; ++i) ans += -a[i];
    }
    cout << ans << endl;

    return 0;
}
