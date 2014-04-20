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

int b[1111][1111];
int a[1111], p[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
    	int n, m, k;    	
    	int ans = 0;
    	scanf("%d%d%d", &n, &m, &k);
    	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 1; j <= m; ++j) {
    			scanf("%d", &b[i][j]);
    		}
    	}
    	int pn = 0;
    	for (int i = 0; i < n; ++i) {
    		int maxp = -2e9;
    		for (int j = 1; j <= m; ++j) {
    			int x;
    			scanf("%d", &x);
    			if (j != a[i]) b[i][j] -= x;
    			if (b[i][j] > maxp) maxp = b[i][j];
    		}
    		if (maxp > b[i][a[i]]) {
	    		p[pn++] = maxp - b[i][a[i]];
	    	}
    		ans += b[i][a[i]];
    	}
    	sort(p, p + pn, greater<int>());
		for (int i = 0; i < k && i < pn; ++i) ans += p[i];
		printf("%d\n", ans);
    }

    return 0;
}
