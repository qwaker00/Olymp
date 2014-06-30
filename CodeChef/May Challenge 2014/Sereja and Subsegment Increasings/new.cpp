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
#include <assert.h>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int a[111111], _f1[311], _f2[311], *f1 = _f1, *f2 = _f2;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
   
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            assert(a[i] >= 0 && a[i] <= 3);
        }
        memset(f1, 63, sizeof(_f1));
        f1[0] = 0;
        for (int i = 0; i < n; ++i) {
            memset(f2, 63, sizeof(_f2));

            int b;
            scanf("%d", &b);
            assert(b >= 0 && b <= 3);

            int newv = (b - a[i] + 4000) & 3;
            for (int j = 0; j <= 300; ++j) {
                int d1 = (newv - j + 4000) & 3; 
                f2[j + d1] = min(f2[j + d1], f1[j] + d1);
                int d2 = (j - newv + 4000) & 3;
                if (j >= d2) f2[j - d2] = min(f2[j - d2], f1[j]);
            }

            swap(f1, f2);
        }
        int ans = 1e9;
        for (int i = 0; i <= 50; ++i) {
            ans = min(ans, f1[i]);
            cerr << (f1[i] > 1e9 ? -1 : f1[i]) << " ";
        }
        cerr << endl;
        printf("%d\n", ans);
    }
    
    return 0;
}
