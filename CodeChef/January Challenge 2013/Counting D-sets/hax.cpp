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

LL pow2[66];

LL pow2m(LL y) {
	LL res = 1;
	int i = 0;
	while (y) {
		if (y & 1)
			res = (res * pow2[i]) % M;
		y >>= 1;
		++i;
	}
	return res;
}

LL powm(LL x, LL y) {
	LL res = 1;
	while (y) {
		if (y & 1)
			res = (res * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return res;
}


//int C[1010][1010];
LL p1[1010], p2[1010], p3[1010];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

/*	for (int i = 0; i <= 1000; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
		}
	}*/
	pow2[0] = 2;
	for (int i = 1; i <= 60; ++i) pow2[i] = (pow2[i - 1] * pow2[i - 1]) % M;

    int T;
	cin >> T;
	while (T--) {
		int n, d;
		cin >> n >> d;

		p1[0] = p2[0] = p3[0] = 1;
		for (int i = 1; i <= n; ++i) {
			p1[i] = (p1[i - 1] * (d + 1)) % (M - 1);
			p2[i] = (p2[i - 1] * (d)) % (M - 1);
			p3[i] = (p3[i - 1] * (d - 1)) % (M - 1);
		}

		LL ans = 0;
		LL Cni = 1;
		for (int i = 0; i <= n; ++i) {
//			cerr << n << " " << i << " = " << Cni << endl;
			if (i & 1) {
				ans = (ans - Cni * pow2m((p1[n - i] * p2[i]) % (M - 1)) + M) % M;
				ans = (ans + Cni * pow2m((p2[n - i] * p3[i]) % (M - 1)) + M) % M;
			} else {
				ans = (ans + Cni * pow2m((p1[n - i] * p2[i]) % (M - 1)) + M) % M;
				ans = (ans - Cni * pow2m((p2[n - i] * p3[i]) % (M - 1)) + M) % M;
			}
			Cni = ((Cni * (n - i)) % M * powm(i + 1, M - 2)) % M;
		}
		cout << ans  << endl;
	}
	
    return 0;
}
