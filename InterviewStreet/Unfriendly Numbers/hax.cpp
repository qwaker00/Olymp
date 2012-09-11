#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, dn, dc[44], dcc[44], divn;
LL k, a[1111111], d[44], dd[44], x;
LL divs[111111];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

//	scanf("%d%I64d", &n, &k);
//	for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a[i] = __gcd(x, k);
	}

	/*
	int ans2 = 0;
	for (int i = 2; i <= k; i++) if (k % i == 0) {
		bool good = true;
		for (int j = 0; j < n; j++) if (a[j] % i == 0) {
			good = false;
			break;
		}
		if (good) {
//			cerr << i << endl;
			ans2++;
		}
	}
	*/

	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (a[i] % a[j] == 0)
			a[j] = a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;

	divs[divn++] = 1;
	for (int i = 2; i < 3222222 && k > 1; ++i) {
		if (k % i == 0) {
			d[dn] = i;
			dc[dn] = 0;
			while (k % i == 0) {
				++dc[dn];
				k /= i;
			}

			int sdivn = divn;
			LL xx = i;
			for (int dp = 1; dp <= dc[dn]; dp++) {
				for (int j = 0; j < sdivn; j++)
					divs[divn++] = divs[j] * xx;
				xx *= i;
			}

			++dn;
		}
	}
	if (k > 1) {
		d[dn++] = k;
		dc[dn - 1] = 1;
		int sdivn = divn;
		for (int j = 0; j < sdivn; j++)
			divs[divn++] = divs[j] * k;
	}

	LL ans = 0;
	for (int i = 0; i < divn; i++) {
		bool good = true;
		for (int j = 0; j < n; j++) if (a[j] % divs[i] == 0) {
			good = false;
			break;
		}
		if (good) ++ans;
	}

	cout << ans << endl;
//	if (ans2 != ans) {
//		cerr << ans << endl;
//		cerr << ans2 << endl;
//		throw 1;
//	}

	return 0;
}
