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

int n, m, k;
int a[111111], b[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);    
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    for (; i < n && j < m;) {
        if (a[i] > b[j]) {
            ++j;
        }
        if (b[j] >= a[i]) {
            ++i;
            ++j;
        }
    }
    if (i == n)
        puts("NO");else puts("YES");    
    return 0;
}
