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


int p[111];
int r, u, n;
LL a[111], b[111], k[111];
LL buf[111][111];
LL ans = -LL(1E18);

void Rec(LL* a, int cnt, int lastXor) {
	if (((u - cnt) & 1) == 0) {
		LL sum = 0;
		for (int i = 0; i < n; i++) sum += k[i] * a[i];
		if (sum > ans) ans = sum;
		if (cnt == u) return;
	}

	if (!lastXor) {
		for (int i = 0; i < n; i++) buf[cnt][i] = a[i] ^ b[i];
		Rec(buf[cnt], cnt + 1, true);
	}
	for (int i = 0; i < n; i++) buf[cnt][i] = a[p[i] - 1] + r;
	Rec(buf[cnt], cnt + 1, false);
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> u >> r;
	for (int i =0 ; i < n; i++) cin >> a[i];
	for (int i =0 ; i < n; i++) cin >> b[i];
	for (int i =0 ; i < n; i++) cin >> k[i];
	for (int i =0 ; i < n; i++) cin >> p[i];

	Rec(a, 0, 0);
	cout << ans << endl;

	return 0;
}
