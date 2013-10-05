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

#define N 222222

bool one[N];
int st[N], stn = 0, Left[N], Right[N], up[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T = 0;
    scanf("%d", &T);    
    while (T--) {
        int n, u, x;
        memset(one, 0, sizeof(one));
        scanf("%d%d", &n, &u);
        for (int i = 0; i < u; ++i) {   
            scanf("%d", &x);
            one[x - 1] = 1;
        }
        int ans = 0;
        for (int w = 1; w <= n; ++w) if (n % w == 0) {
            int h = n / w;
            int reader = 0;

            for (int j = 0; j < w; ++j) up[j] = 0;
            for (int i = 0; i < h; ++i) {
                for (int j = 0; j < w; ++j)
                    if (one[reader++]) up[j] = 0;else ++up[j];

                stn = 0;
                for (int j = 0; j < w; ++j) {
                    while (stn > 0 && up[st[stn - 1]] >= up[j]) --stn;
                    if (stn == 0)
                        Left[j] = 0;else
                        Left[j] = st[stn - 1] + 1;
                    st[stn++] = j;
                }
                stn = 0;
                for (int j = w - 1; j >= 0; --j) {
                    while (stn > 0 && up[st[stn - 1]] >= up[j]) --stn;
                    if (stn == 0)
                        Right[j] = w - 1;else
                        Right[j] = st[stn - 1] - 1;
                    st[stn++] = j;
                }

                for (int j = 0; j < w; ++j) {
                    if (up[j] * (Right[j] - Left[j] + 1) > ans) {
                        ans = up[j] * (Right[j] - Left[j] + 1);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
