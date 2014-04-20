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

int n, m, vn, v[N], was[N], pr[N];

int fs(int x) {
	if (pr[x] != x) pr[x] = fs(pr[x]);
	return pr[x];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	v[vn++] = x;
    	v[vn++] = y + 1;
    	if (pr[x] == 0) pr[x] = x;
    	if (pr[y+1] == 0) pr[y+1] = y+1;
    	pr[fs(x)] = fs(y + 1);
    }
    sort(v, v + vn);
    vn = unique(v, v + vn) - v;

    int ansn = vn;
    for (int i = 0; i < vn; ++i)
    	if (pr[v[i]] == v[i]) {
	    	--ansn;
    	}
    int ans = 1;
    while (ansn--) ans = (ans + ans) % 1000000007;
    printf("%d\n", ans);

    return 0;
}
