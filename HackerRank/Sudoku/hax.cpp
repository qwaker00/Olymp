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

int di[9], dj[9], dd[3][3], a[9][9], lg[1024];

bool solve(int st) {	

    for (int i = 0; i < 81; ++i, ++st) {
    	if (st >= 81) st = 0;

    	int x = st / 9;
    	int y = st % 9;
		int msk = di[x] & dj[y] & dd[x % 3][y % 3];

		if ((msk & (msk - 1)) == 0) {
			a[x][y] = lg[msk];
			if (solve(st))
		}
			
    }
	
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (msk & (msk - 1)) {
				
			}
		}
	}


	for (int i = 0; i < 9; ++i)
		if ((di[i] & (di[i] - 1)) == 0) {
			for (int j = 0; j < 9; ++j) if (a[i][j] == 0) {
				a[i][j] = lg[di[i]];
    			di[i] ^= (1 << a[i][j]);
    			dj[j] ^= (1 << a[i][j]);
    			dd[i % 3][j % 3] ^= (1 << a[i][j]);

				solve();

				a[i][j] = 0;
    			di[i] ^= (1 << a[i][j]);
    			dj[j] ^= (1 << a[i][j]);
    			dd[i % 3][j % 3] ^= (1 << a[i][j]);

				break;
			}
		}
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    for (int i = 0; i <= 9; ++i) lg[1 << i] = i;

    int T;
    scanf("%d", &T);
    while (T--) {
    	for (int i = 0; i < 9; ++i)
    		di[i] = dj[i] = dd[i % 3][i / 3] = (1 << 10) - 2;
    	for (int i = 0; i < 9; ++i) {
    		for (int j =0 ; j < 9; ++j) {
    			scanf("%d", &a[i][j]);
    			di[i] ^= (1 << a[i][j]);
    			dj[j] ^= (1 << a[i][j]);
    			dd[i % 3][j % 3] ^= (1 << a[i][j]);
    		}
    	}
    	solve();
    	for (int i = 0; i < 9; ++i) {
    		for (int j = 0; j < 9; ++j)
    			printf("%d ", a[i][j]);
			puts("");
		}
    }
    
    return 0;
}
