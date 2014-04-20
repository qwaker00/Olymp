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

int T;
int n;
int msk[22];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int d;
            cin >> d;
            msk[i] = 1 << i;
            for (int j = 0; j < d; ++j) {
                int x;
                cin >> x;
                msk[i] |= (1 << (x - 1));
            }
        }
        int ans = n;
        for (int i = 0; i < (1 << n); ++i) {
            int m = 0, cnt = 0;
            for (int j = 0; j < n; ++j) if ( (1 << j) & i ) {
                m |= msk[j];
                ++cnt;
            }
            if (cnt < ans && m == (1 << n) - 1) ans = cnt;
        }
        cout << ans << endl;
    }
    
    return 0;
}
