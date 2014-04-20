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

#define M 1000000007

LL powm(LL x, LL y, LL m) {
	LL res = 1;
	while (y) {
		if (y & 1)
			res = (res * x) % m;
		x = (x * x) % m;
		y >>= 1;
	}
	return res;
}

int C[1010][1010];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	for (int i = 0; i <= 1000; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
		}
	}

    int T;
	cin >> T;
	while (T--) {
		LL n, d;

		cin >> n >> d;

		LL ans = 0;
		for (int i = 0; i <= n; ++i) {
			int p1 = (powm(d + 1, n - i, M - 1) * powm(d, i, M - 1)) % (M - 1);
			int p2 = (powm(d, n - i, M - 1) * powm(d - 1, i, M - 1)) % (M - 1);
			if (i & 1) {
				ans = (ans - C[n][i] * powm(2, p1, M) + M) % M;
				ans = (ans + C[n][i] * powm(2, p2, M) + M) % M;
			} else {
				ans = (ans + C[n][i] * powm(2, p1, M) + M) % M;
				ans = (ans - C[n][i] * powm(2, p2, M) + M) % M;
			}
		}
		cout << ans  << endl;
	}
	
    return 0;
}
