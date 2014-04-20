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

inline void solve(ULL l, ULL r, vector<ULL>& ans) {
    while (l < r) {
        ULL x = l, step = 1;
        while (x > 1) {
            ULL p = x >> 1;

            bool good = true;
            ULL yy = r;
            while (yy >= p) {
                if (yy == p) {
                    good = false;
                    break;
                }
                yy >>= 1;
            }
            if (!good) break;

            yy = l - 1;
            while (yy >= p) {
                if (yy == p) {
                    good = false;
                    break;
                }
                yy >>= 1;
            }
            if (!good) break;

            step += step;
            x = p;
        }
        ans.push_back(x);
        l += step;
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    ULL a[1111];
    int n, R;
    cin >> n >> R;
    for (int i = 1; i <= R; ++i) {
        cin >> a[i];
    }
    a[0] = (1ull << n) - 1;
    a[R + 1] = (1ull << (n + 1));
    sort(a, a + R + 2);

    vector<ULL> ans;
    for (int i = 1; i <= R + 1; ++i) {
        solve(a[i - 1] + 1, a[i], ans);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i + 1 != ans.size()) cout << " ";
    }
    cout << endl;
        
    return 0;
}
