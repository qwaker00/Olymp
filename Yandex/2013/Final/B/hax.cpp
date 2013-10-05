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

#define MAX 65536
int n, m, k, x;
int a[MAX], b[MAX], aa[MAX], bb[MAX];
LL ans[MAX], A[MAX];
int was[MAX], ed[MAX];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    ed[0] = 0;
    for (int i = 1; i < MAX; ++i) {
        ed[i] = ed[i & (i - 1)] + 1;
    }

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++a[x];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        ++b[x];
    }
    for (int i = 0; i < MAX; ++i) {
        if (a[i]) {
            for (int j = i; j; j = (j - 1) & i) aa[j] += a[i];
            aa[0] += a[i];
        }
        if (b[i]) {
            for (int j = i; j; j = (j - 1) & i) bb[j] += b[i];
            bb[0] += b[i];
        }
    }
    for (int i = 0; i < MAX; ++i) A[i] = LL(aa[i]) * bb[i];

    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        if (was[x]) {
            cout << ans[x] << '\n';
            continue;
        }
        was[x] = true;
        LL& sum = ans[x] = 0;
            
        for (int j = (MAX - 1) ^ x; j; j = (j - 1) & ((MAX - 1) ^ x)) {
            int jj = (MAX - 1) ^ j;

            if ( ((ed[jj] + ed[x]) & 1) == 0)
                sum += A[jj];else
                sum -= A[jj];
        }
        if ( ((ed[MAX - 1] + ed[x]) & 1) == 0) sum += A[MAX - 1];else sum -= A[MAX - 1];
    
        cout << sum << '\n';
    }
    
    return 0;
}
