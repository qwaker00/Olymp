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

unsigned a[22][633];
int ed[1111111], okn[1111111];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n, m, k, x, nn;
    bool ok[22][22];
     
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &x);
            a[i][x >> 5] |= (1u << (x & 31));
        }
    }

    nn = (n + 31) >> 5;
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j) {
            ok[i][j] = true;
            for (int l = 0; l < nn; ++l) if (a[i][l] & a[j][l]) {
                ok[i][j] = false;
                break;
            }
        }

    okn[0] = 1;
    int ans = 0;
    for (int i = 1; i < (1 << m); ++i) {
        ed[i] = ed[i & (i - 1)] + 1;
        if (!okn[i & (i - 1)]) continue;
        for (int j = 0; j < m; ++j) if ((1u << j) & i) {
            okn[i] = 1;
            for (int l = j + 1; l < m; ++l)
                if (((1u << l) & i) && !ok[j][l]) {
                    okn[i] = 0;
                    break;
                }
            break;
        }
        if (ed[i] <= ans || !okn[i]) continue;
        ans = ed[i];
    }

    printf("%d\n", ans);
    
    return 0;
}
