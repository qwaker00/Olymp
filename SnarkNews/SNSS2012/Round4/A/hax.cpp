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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL x, y, n, m, tx, ty, c, ntx, nty;
long double ans;
int sign[] = {-1, 1};

long double dist(long double x, long double y, long double xx, long double yy) {
	return sqrtl((x-xx)*(x-xx) + (y-yy)*(y-yy));
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    while (true) {
	    cin >> n >> m >> x >> y >> tx >> ty >> c;
	    if (n == m && n == 0) break;

    	ans = 1e100;

	    for (int ry = 0; ry <= c; ry++) {
			int rx = c - ry;
	    	for (int i = 0; i < 4; i++) {
	    		if (x == tx && ry > 1) {
	    			continue;
	    		}
	    		if (y == ty && rx > 1) {
	    			continue;
	    		}
	    		if (x == tx && ry == 1) {
	    			if (y < ty && sign[i&1] < 0)
		    			continue;
	    			if (y > ty && sign[i&1] > 0)
		    			continue;
	    		}
	    		if (y == ty && rx == 1) {
	    			if (x < tx && sign[i >> 1] < 0)
		    			continue;
	    			if (x > tx && sign[i >> 1] > 0)
		    			continue;
	    		}

	    		if (ry & 1) {
    				nty = m - ty;
	    		} else {
    				nty = ty;
	    		}
				nty += sign[i&1] * ry * m;

    			if (rx & 1) {
		    		ntx = n - tx;
    			} else {
    				ntx = tx;
	    		}
				ntx += sign[i >> 1] * rx * n;

				ans = min(ans, dist(x, y, ntx, nty));
			}
	    }

	    cout.precision(20);
	    cout << fixed;
		cout << ans << endl;
	}

    return 0;
}
