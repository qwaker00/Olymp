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

int n, T, q, a[333333];
struct Tp {
	int l, r;
	int bstart;
} Q[333333];
int B[15111111][2], bn = 0, BC[15111111];

void Init(int x, int l, int r) {
	Q[x].l = l, Q[x].r = r;

	Q[x].bstart = ++bn;
	B[bn][0] = B[bn][1] = BC[bn] = 0;

	for (int i = l; i <= r; ++i) {
		int cur = Q[x].bstart;
		for (int j = 14; j >= 0; --j) {
			int c = ((a[i] & (1 << j)) > 0);
			if (!B[cur][c]) {
				B[cur][c] = ++bn;
				B[bn][0] = B[bn][1] = BC[bn] = 0;
			}
			cur = B[cur][c];
		}
		++BC[cur];
	}

	if (l < r) {
		Init(x + x, l, (r + l) >> 1);
		Init(x + x + 1, (r + l + 2) >> 1, r);
	}
}

int MaxXor(int x, int l, int r, int a) {
	if (l <= Q[x].l && r >= Q[x].r) {
		int ans = 0, cur = Q[x].bstart;
		for (int j = 14; j >= 0; j--) {
			int c = ((a & (1 << j)) > 0);
			if (B[cur][1 - c]) {
				cur = B[cur][1 - c];
				ans ^= 1 << j;
			} else {
				cur = B[cur][c];
			}
		}
		return ans;
	}
	if (l > Q[x].r || r < Q[x].l) return 0;
	return max(MaxXor(x + x, l, r, a), MaxXor(x + x + 1, l, r, a));
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
//	cerr << sizeof(BC) + sizeof(B) + sizeof(Q) + sizeof(a) << endl;

	scanf("%d", &T);
	while (T--) {
		bn = 0;

		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}

		Init(1, 1, n);
		int a, l, r;
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &a, &l, &r);
			printf("%d\n", MaxXor(1, l, r, a));
		}
	}

	cerr << clock() << endl;

	return 0;
}
