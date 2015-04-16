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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int Q = 27;
const int Z = 0;

char s[3][1000111];
int go[28][28][28][4][4];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);


    for (int f1 = 0; f1 < 2; ++f1) {
    	for (int f2 = 0; f2 < 2; ++f2) {
    		for (int c1 = 0; c1 < Q; ++c1)
    		for (int c2 = 0; c2 < Q; ++c2)
    		for (int c3 = 0; c3 < Q; ++c3) {
    			if (!f1 && c1 > c2) continue;
    			if (!f2 && c2 > c3) continue;
    			int m1 = f1 || (c1 < c2);
    			int m2 = f2 || (c2 < c3);

    			++go[c1][c2][c3][(f1 << 1) | f2][(m1 << 1) | m2];

    			if (c1)
	    			++go[Q][c2][c3][(f1 << 1) | f2][(m1 << 1) | m2];
	    		if (c2)
	    			++go[c1][Q][c3][(f1 << 1) | f2][(m1 << 1) | m2];
	    		if (c3)
	    			++go[c1][c2][Q][(f1 << 1) | f2][(m1 << 1) | m2];

	    		if (c1 && c2)
	    			++go[Q][Q][c3][(f1 << 1) | f2][(m1 << 1) | m2];
	    		if (c1 && c3)
	    			++go[Q][c2][Q][(f1 << 1) | f2][(m1 << 1) | m2];
	    		if (c2 && c3)
	    			++go[c1][Q][Q][(f1 << 1) | f2][(m1 << 1) | m2];

	    		if (c1 && c2 && c3)
	    			++go[Q][Q][Q][(f1 << 1) | f2][(m1 << 1) | m2];
    		}
    	}
    }

    int T;
    scanf("%d\n", &T);
  	while (T--) {  		
  		int l = 0;
		for (int i = 0; i < 3; ++i) {
			gets(s[i]);
			l = max(l, (int)strlen(s[i]));
		}
		for (int i = 0; i < 3; ++i) {
			int cl = strlen(s[i]);
			for (int j = 0; j < cl; ++j)
				if (s[i][j] == '?')
					s[i][j] = Q;
				else
					s[i][j] = s[i][j] - 'a' + 1;			
			for (int j = cl; j < l; ++j) s[i][j] = Z;
		}

		LL f[4] = {1, 0, 0, 0};
		const int MOD = 1000000009;
		for (int i = 0; i < l; ++i) {
			LL ff[4] = {0, 0, 0, 0};
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					ff[k] = (ff[k] + f[j] * go[s[0][i]][s[1][i]][s[2][i]][j][k]) % MOD;
				}
			}
			memcpy(f, ff, sizeof(ff));
		}
		printf("%d\n", (int)f[3]);
  	}

    return 0;
}
