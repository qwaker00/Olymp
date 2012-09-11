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

int a[1000111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T, n, m, w, x, y, z;
   	scanf("%d", &T);

    while (T--) {
    	scanf("%d%d", &n, &m);

    	for (int i = 0; i < m; i++) {
	    	scanf("%d%d%d%d", &w, &x, &y, &z);
    		if (w == 1) {
	    		a[x] += z;
	    		a[y + 1] -= z;
	    	} else {
	    		a[x] -= z;
	    		a[y + 1] += z;
	    	}
    	}

    	int mi = 2e9, ma = -2e9;
    	x = 0;
    	for (int i = 1; i <= n; i++) {
    		x += a[i] + 1;
    		if (x > ma) ma = x;
    		if (x < mi) mi = x;
    	}
    	cout << ma - mi << endl;

    	memset(a, 0, sizeof(int) * (n + 2));
    }

    return 0;
}
