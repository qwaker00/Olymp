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


int pr[111111];
int ans[6][111111];
int t, a, b, k;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i <= 100000; ++i) if (pr[i] == 0) {
        for (int j = i; j <= 100000; j += i) {
            ++pr[j];
        }
    }
    for (int k = 1; k <= 5; ++k) {
        ans[k][0] = 1;
        for (int i = 1; i <= 100000; ++i) ans[k][i] = ans[k][i - 1] + (pr[i] == k);
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &k);
        printf("%d\n", ans[k][b] - ans[k][a - 1]);
    }                      
    
    return 0;
}
