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

int x[100100], y[100100];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x, x + n);
    sort(y, y + n);
    int cx = x[n / 2];
    int cy = y[n / 2];
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(x[i] - cx);
        ans += abs(y[i] - cy);
    }
    cout << ans << endl;
    
    return 0;
}
