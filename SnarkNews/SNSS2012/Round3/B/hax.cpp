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

int n, m, r, T, x, y, z, ans[111];
int d[111][111], yy[111111], pp[111111], xx[111], pr[111], was[111], kk, out[111];

bool kuhn(int x) {
	if (was[x]) return false;
	was[x] = true;

	for (int i = xx[x]; i ; i= pp[i])
		if (pr[yy[i]] == -1 || kuhn(pr[yy[i]])) {
			pr[yy[i]] = x;
			return true;
		}

	return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> T;
    while (T--) {
    	kk = 0;
    	memset(xx, 0, sizeof(xx));

    	cin >> m >> n >> r;
    	memset(d, 63, sizeof(d));
    	for (int i = 0; i < r ;++i) {
    		cin >> x >> y >> z;
    		x--, y--;
    		d[x][y] = d[y][x] = z;
    	}

    	for (int k = 0; k < n; k++)
    		for (int i = 0; i < n; i++)
    			for (int j = 0; j < n; j++)
    				if (d[i][k] + d[k][j] < d[i][j]) {
    					d[i][j] = d[i][k] + d[k][j];
	    			}

		for (int it = 0; it < m; it++) {
			cin >> x >> z;
			x--;
			if (z == 0) {
				ans[it] = x;
			} else {
				for (int i = 0; i < n; i++) if (d[x][i] == z) {
					yy[++kk] = i;
					pp[kk] = xx[it];
					xx[it] = kk;
				}
			}
		}

		int ans = 0;
		memset(pr, -1, sizeof(pr));
		for (int i = 0; i < m; i++) {
			if (pr[i] == -1) {
				memset(was, 0, sizeof(was));
				if (kuhn(i)) ++ans;
			}
		}
		if (ans != m) {
			cout << -1 << endl;
			continue;
		}
		bool stop = false;
		for (int x = 0; x < m; x++) {
			memset(was, 0, sizeof(was));
			for (int i = xx[x]; i ; i = pp[i])
				if (pr[yy[i]] != x && (pr[yy[i]] == -1 || kuhn(pr[yy[i]]))) {
					cout << -1 << endl;
					stop = true;
					break;
				}
			if (stop) break;
		}
		if (!stop) {
			for (int i = 0; i < n; i++) if (pr[i] != -1) out[pr[i]] = i + 1;
			for (int i =0 ; i < m; i++) cout << out[i] << " ";
			cout << endl;
		}
    }               

    return 0;
}
