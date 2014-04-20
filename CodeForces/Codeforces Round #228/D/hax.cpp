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

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int last = 0;
    for (int n = 1; n <= 25; ++n) {     
        int ans = 0;
        for (int i = 1; i < (1 << (n+1)); i += 2) {
            bool bad = false;
            for (int j = 0; j <= n && !bad; ++j) if (i & (1 << j))
                for (int k = j; k <= n; ++k) if (i & (1 << k))
                    if ((i & (1 << (j ^ k))) == 0) {
                        bad = true;
                        break;
                    }
            if (bad) continue;

          for (int j = 0; j <= n; ++j)
                if (i & (1 << j))
                    putchar('1');else
                    putchar('0');
            puts("");                      

            ++ans;
        }
        cout << n << ": " << ans << " " << ans - last << endl;
        last = ans;
    }                        

    return 0;
}
