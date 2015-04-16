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

typedef LD matr[26][26];

matr ans, t, a;

inline void mul(matr& x, matr& b, matr& c) {
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < 26; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(12);
    cout << fixed;

    int T;
    scanf("%d", &T);
	while (T--) {
		int n, k;
		char w[5];
		scanf("%d%d\n%s", &n, &k, w);
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				double x;
				scanf("%lf", &x);
				a[i][j] = x;
			}
		}
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 26; ++i) ans[i][i] = 1;
		while (k) {
			if (k & 1) {
				mul(a, ans, t);
				memcpy(ans, t, sizeof(t));
			}
			k >>= 1;
			mul(a, a, t);
			memcpy(a, t, sizeof(t));
		}

		set<string> was;
		char ww[5];
		LD out = 0;
		for (int i = 0; i < n; ++i) {
			LD res = 1;
			scanf("%s", ww);

			if (strlen(ww) != strlen(w)) continue;
			if (was.count(ww)) continue;

			was.insert(ww);
			for (int j = 0; w[j]; ++j) {
				if (ww[j] >= 'a' && ww[j] <= 'z') {
					res *= ans[w[j] - 'a'][ww[j] - 'a'];
				} else {
					res = 0;
					break;
				}
			}

			out += res;
		}
		cout << double(out) << "\n";
	}

    return 0;
}
