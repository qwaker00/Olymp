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

double a[1111], b[1111];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int j = 0; j < n; ++j) cin >> b[j];
        sort(a, a + n);
        sort(b, b + n);

        int ans2 = 0, ans1 = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && a[i] >= b[j]) ++j;
            if (j == n) {
                ans2 = n - i;
                break;
            }
            ++j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && b[i] >= a[j]) ++j;
            if (j == n) {
                ans1 = n - i;
                break;
            }
            ++j;
        }

        cout << "Case #" << __it << ": ";
        cout << n - ans1 << " " << ans2;
        cout << endl;
    }

    return 0;
}
