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

#define N 222222

int a[N], n, k;
LL sum = 0, prof[N], A[N], ans = 0;

LL GetMax(int x) {
	++x;

	LL ans = LL(-1e18);
	if (x < 1) {
		x = 1;
		ans = 0;
	}
	while (x <= n) {
		ans = max(ans, A[x]);
		x = (x | (x - 1)) + 1;
	}
	return ans;
}

LL Set(int i, LL x) {
	++i;

	while (i > 0) {
		A[i] = max(A[i], x);
		i &= i - 1;
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;

	memset(A, 63 + 128, sizeof(A));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
		prof[i] = GetMax(i - k) + sum;
		if (prof[i] > ans) ans = prof[i];
		if (i > 0) {
			Set(i, prof[i - 1] - sum);
		} else Set(0, -a[0]);
	}
	cout << ans << endl;

	return 0;
}
