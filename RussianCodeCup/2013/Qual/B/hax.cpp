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

LL a[5555], b[5555], c[5555], Sum[5555];
int n, bn;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        int bans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k) if (a[j] == a[k])
                    for (int l = k + 1; l < n; ++l) if (a[i] + a[j] + a[k] > a[l]) {
                        ++bans;
                    }
        cerr << bans << endl;
        
        bn = 0;
        for (int i = 0; i < n; ++i)
            if (i == 0 || a[i] != a[i - 1]) {
                b[bn++] = a[i];
                c[bn - 1] = 1;
            } else ++c[bn - 1];
        b[bn] = 1e18;
        c[bn] = 0;
        Sum[0] = c[0];
        for (int i = 1; i <= bn; ++i) Sum[i] = Sum[i - 1] + c[i];

        LL ans = 0;
        for (int i = 0; i < bn; ++i) {
            if (c[i] > 1) {
                LL pr = LL(c[i]) * (c[i] - 1) / 2;

                if (c[i] >= 4)
                    ans += pr * (c[i] - 2) * (c[i] - 3) / 12;

                for (int j = i, k = bn; j >= 0; --j) {
                    while (k > i && b[i] + b[i] + b[j] <= b[k]) --k;
                    if (j == i) {
                        ans += pr * (c[j] - 2) * (Sum[k] - Sum[i]) / 3;
                    } else {
                        ans += pr * c[j] * (Sum[k] - Sum[i]);
                        ans += pr * c[j] * (c[i] - 2) / 3;
                    }
                }
            }
        }
        cout << ans << endl;
        cerr << ans << endl;
    }    
    
    return 0;
}
