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

#define MOD 1000000007

inline void Add(int& x, int y) {
	x = (x + y) % MOD;
//	x += y;
//	if (x >= MOD) x -= MOD;
}

int T, n;
char s[11111];
int f[3][10][5];
int C[11111][5];
int go[10][255];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
//	cerr << sizeof(f) + sizeof(s) << endl;

	C[0][0] = 1;
	for (int i = 1; i <= 10000; ++i) {
		C[i][0] = 1;
		for (int j = 1; j < 5; ++j) {
			C[i][j] = C[i - 1][j];
			Add(C[i][j], C[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j) 
			go[i][j + 48] = (i * 10 + j) % 9;

    scanf("%d\n", &T);
    while (T--) {
    	gets(s);
    	n = strlen(s);

    	int zero = 0;
    	for (int i = 0; i < n; ++i) zero += (s[i] == '0');
    	int zeroans = C[zero][0];
    	Add(zeroans, C[zero][1]);
    	Add(zeroans, C[zero][2]);
    	Add(zeroans, C[zero][3]);
    	Add(zeroans, C[zero][4]);

    	memset(f, 0, sizeof(f));
    	f[0][0][0] = 1;
    	for (int i = 1, r, w; i <= n; i++) {
    		w = i & 1;
    		r = 1 - w;

    		memcpy(f[w], f[r], 200);
    		for (int j = 0; j < 9; ++j) {
    			for (int l = 0; l < 4; l++) {
	    			Add(f[w][go[j][s[i - 1]]][l + 1], f[r][j][l]);
	    		}
    		}
    	}

    	int ans = MOD - zeroans;
    	Add(ans, f[n&1][0][0]);
    	Add(ans, f[n&1][0][1]);
    	Add(ans, f[n&1][0][2]);
    	Add(ans, f[n&1][0][3]);
    	Add(ans, f[n&1][0][4]);

    	cout << ans << endl;
    }
   
//    cerr << clock() << endl;

    return 0;
}
