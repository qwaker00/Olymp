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

#define N 5555
#define M 555555

int n, m;
int yy[M], pp[M], xx[N], a[N], kk = 0, p[N];
unsigned A[N][157], B[157];

int main() {
    freopen("bombing.in", "r", stdin);
    freopen("bombing.out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        p[a[i]] = i;
        A[i + 1][(i + 1) >> 5] |= (1 << ((i + 1) & 31));
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (p[x] > p[y]) swap(x, y);
        yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;

        A[x][y >> 5] |= (1 << (y & 31));
        A[y][x >> 5] |= (1 << (x & 31));
    }
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        memset(B, 0xFF, sizeof(B));
        for (int j = xx[x]; j; j = pp[j]) {
            unsigned* Aj = A[yy[j]];
            for (int k = 0; k < 157; ++k) B[k] &= Aj[k];
        }
        for (int j = xx[x]; j; j = pp[j]) {
            int y = yy[j];
            if (!(B[y >> 5] & (1 << (y & 31)))) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
