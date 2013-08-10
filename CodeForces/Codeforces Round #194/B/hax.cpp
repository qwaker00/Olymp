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


int n, m, x, y, a[1111][1111];
bool canx[1111], cany[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n >> m;
    memset(canx, 1, sizeof(canx));
    memset(cany, 1, sizeof(cany));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
        canx[x] = false;
        cany[y] = false;
    }
    int ans = 0;
    for (int i = 2; i < n; ++i) {
        ans += canx[i];
        ans += cany[i];
    }
    if (n & 1)
        ans -= canx[n / 2 + 1] && cany[n / 2 + 1];
    cout << ans << endl;
    
    return 0;
}
