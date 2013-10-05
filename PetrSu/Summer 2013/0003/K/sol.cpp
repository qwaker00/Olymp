#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int MOD = 1000000007;
const int N = 100111;

int cans[N];
int a[2][N];
int add[2][N];
int sum[2][N];
int sq;

char geto() {
	char c = getchar();
	while (c != '.' && c != '*' && c != '?') c = getchar();
	return c; 
}

inline int getsum(int v, int x) {
	return (ll(sq) * add[v][x] + sum[v][x]) % MOD;
}

inline int geta(int v, int pos, int x) {
	return (a[v][pos] + add[v][x]) % MOD;
}

void modify(int v, int r, int value) {
	if (r < 0) return;

	int x = 0;
	int w = 1 - v;

	while ((x + 1) * sq - 1 <= r) {
		add[v][x] = (ll(add[v][x]) + ll(value)) % MOD;
		cans[x] = (cans[x] + ll(value) * ((ll(sum[w][x]) + ll(sq) * add[w][x]) % MOD)) % MOD; 
		++x;
	}


	for (int i = x * sq; i <= r; ++i) {
		cans[x] = (ll(cans[x]) - ll(geta(v, i, x)) * geta(w, i, x)) % MOD;
		if (cans[x] < 0) cans[x] += MOD;

		a[v][i] = (a[v][i] + value) % MOD;
		sum[v][x] = (sum[v][x] + value) % MOD;

		cans[x] = (cans[x] + ll(geta(v, i, x)) * geta(w, i, x)) % MOD;
	}
}

int findsum(int r) {
	if (r < 0) return 0;

	int x = 0;
	int ans = 0;
	while ((x + 1) * sq - 1 <= r) {
		ans = (ans + cans[x]) % MOD;
		++x;
	}

	for (int i = x * sq; i <= r; ++i) {
		ans = (ans + ll(geta(0, i, x)) * geta(1, i, x)) % MOD;
	}

	return ans;
}
		

int main() {
	//freopen("in", "r", stdin);

	int n, m;
	scanf("%d%d", &n, &m);
	sq = max(int(sqrt(double(n))) + 1, 1);


	while (m--) {
		char c = geto();
		int l, r; scanf("%d%d", &l, &r);
		int value; 
		if (c != '?') scanf("%d", &value);
		--l; --r;

		if (c == '.') {
			modify(0, r, value);
			modify(0, l - 1, MOD - value);
		} else if (c == '*') {
			modify(1, r, value);
			modify(1, l - 1, MOD - value);
		} else {
			printf("%d\n", (findsum(r) + MOD - findsum(l - 1)) % MOD);
		}
	}
	
	return 0;
}
