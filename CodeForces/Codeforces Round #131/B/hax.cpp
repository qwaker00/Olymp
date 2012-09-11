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

inline int Add(int x, int y) {
	return (x + y) % MOD;	
}
inline int Sub(int x, int y) {
	return (x - y + MOD) % MOD;	
}
inline int Mul(int x, int y) {
	return (LL(x) * y) % MOD;	
}
inline int Pow(int x, int y) {
	int res = 1;
	while (y) {
		if (y&1) res = Mul(res, x);
		x = Mul(x, x);
		y >>= 1;
	}
	return res;
}
inline int Div(int x, int y) {
	return Mul(x, Pow(y, MOD - 2));
}

int n, d[111], fact[111], pow10[111], C[111][111], f[111][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i< 10; i++) cin >> d[i];

    fact[0] = 1;
    for (int i = 1; i <= 100; i++) fact[i] = Mul(fact[i - 1], i);
    pow10[0] = 1;
    for (int i = 1; i <= 100; i++) pow10[i] = Mul(pow10[i - 1], 10);

    for (int i = 0; i <= 100; i++) {
    	C[i][0] = 1;
    	for (int j = 1; j <= i; j++) C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
		for (int fd = 1; fd < 10; fd++) {	
			bool noadd = false;
			if (d[fd]) d[fd]--;else noadd = true;

			int l = i - 1;
			int sum = 0;
			for (int j = 0; j < 10; j++) sum += d[j];
			if (sum > l) {
				if (!noadd) d[fd]++;
				continue;
			}

			memset(f, 0, sizeof(f));
			for (int k = d[9]; k <= l; k++) f[9][k] = 1;
			for (int k = 8; k >= 0; k--) {
				for (int j = d[k]; j <= l; j++) {
					for (int jj = d[k]; jj <= j; jj++) {
						f[k][j] = Add(f[k][j], Mul(C[j][jj], f[k + 1][j - jj]) );
					}
				}
			}
		    ans = Add(ans, f[0][l]);

			if (!noadd) d[fd]++;
		}
    }

    cout << ans << endl;

    return 0;
}
