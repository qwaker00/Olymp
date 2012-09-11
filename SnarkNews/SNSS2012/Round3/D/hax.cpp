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


int T, n;
double x[111], y[111];
double f[111][111], D[111][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> T;
    while (T--) {
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		cin >> x[i] >> y[i];
    		x[i + n] = x[i];
    		y[i + n] = y[i];
    	}
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++) {
    			D[i][j] = sqrtl((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
    			f[i][j] = 1e100;
    		}

    	for (int l = 3; l <= n; l++) {
    		for (int i = 0; i < n; i++) {
    			int j = i + l - 1, jn = j % n;
    			if (l == 3) {
    				f[i][jn] = 0;
    			} else {
					int x1 = (j - 1 + n) % n;
					int x2 = (i + 1) % n;
					f[i][jn] = min(D[i][x1] + f[i][x1], D[x2][jn] + f[x2][jn]);
    			}
    		}
    	}
    	double ans = 1e100;
    	cout.precision(10);
    	for (int i = 0; i < n; i++) ans = min(ans, f[i][(i + n - 1) % n]);
    	cout << fixed << ans << endl;
    }

    return 0;
}
