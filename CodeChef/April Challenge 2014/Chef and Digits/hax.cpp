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


int ans[111111];
int n, m, cnt[10];
char s[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d\n%s", &n, &m, s);
    for (int i = 0; i < n; ++i) {
        int cur = s[i] - '0';

        for (int j = 0; j < cur; ++j) ans[i] += LL(cur - j) * cnt[j];
        for (int j = cur + 1; j < 10; ++j) ans[i] += LL(j - cur) * cnt[j];

        ++cnt[cur];
    }

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x - 1]);
    }

    return 0;
}
