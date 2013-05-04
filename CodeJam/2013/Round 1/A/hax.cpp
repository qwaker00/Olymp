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

int a, n, b[222];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        cin >> a >> n;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(b, b + n);

        int eat = 0;
        int ans = n;
        int dbl = 0;
        while (eat < n) {
            ans = min(ans, dbl + n - eat);
            if (b[eat] < a) {
                a += b[eat];
                ++eat;
            } else {
                if (a == 1) break;
                dbl++;
                a = a + a - 1;
            }
            ans = min(ans, dbl + n - eat);
        }
        cout << "Case #" << __it << ": " << ans << endl;
    }    
    
    return 0;
}
