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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

int a[N];
int m, n, q, was[N];
LL ans[N], s[N];

LL Sum(int l, int r) {
    if (r < 0) return 0;
    if (l < 0) l = 0;
    if (l == 0) return s[r];    
    return Sum(0, r) - Sum(0, l - 1);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, greater<int>());
    s[0] = a[0];
    for (int i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q);
        if (was[q]) {
            cout << ans[q] << " ";
            continue;
        }

        LL sum = 0;
        LL step = 1;
        LL offset = 1;
        for (int j = 1; offset < n; ++j) {
            step *= q;
            sum += Sum(offset, min(LL(n) - 1, offset + step - 1)) * j;                
            offset += step;
        }

        cout << sum << " ";

        ans[q] = sum;
        was[q] = true;
    }
    
    return 0;
}
