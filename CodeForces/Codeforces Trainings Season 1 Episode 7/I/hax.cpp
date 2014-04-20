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

int n, a[444][444], s1[444][444], s2[444][444];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            s1[i][j] = s1[i - 1][j - 1] + a[i][j];
        }
        for (int j = n; j >= 1; --j) {
            s2[i][j] = s2[i - 1][j + 1] + a[i][j];
        }
    }

    LL ma = LL(-2e18);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; i + k <= n && j + k <= n; ++k) {
                LL s = (s1[i + k][j + k] - s1[i - 1][j - 1]) - (s2[i + k][j] - s2[i - 1][j + k + 1]);
                if (s > ma) ma = s;
            }
        }
    }
    cout << ma << endl;
    
    return 0;
}
