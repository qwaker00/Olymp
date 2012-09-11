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

int a[N], b[N], n, q, x, p;
char s[33];

int S1[N];

void Add(int p, int x) {
	while (p <= n) {
		S1[p] += x;
		p = (p | (p - 1)) + 1;
	}
}

int Sum(int l, int r) {
	int sum = 0;
	if (r > n) r = n;
	while (r > 0) {
		sum += S1[r];
		r &= r - 1;
	}
	--l;
	while (l > 0) {
		sum -= S1[l];
		l &= l - 1;
	}
	return sum;
}

bool Carry(int p) {
	int step = 16, off = 0;
	while (step >= 0) {
		if (Sum(p + 1, p + off + (1 << step)) == off + (1 << step))
			off += (1 << step);
		--step;				
	}
	return (a[p + off + 1] + b[p + off + 1] == 2);
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d%d\n", &n, &q);
	for (int i = 1; i <= n; ++i) {
		a[i] = getchar() - 48;
	}
	scanf("\n");
	for (int i = 1; i <= n; ++i) {
		b[i] = getchar() - 48;
		if (a[i] + b[i] == 1) Add(i, 1);
	}
	for (int i = 0; i < q; ++i) {
		scanf("%s", s);
		if (s[0] == 's') {
			scanf("%d%d", &p, &x);
			p = n - p;

			if (a[p] + b[p] == 1) Add(p, -1);
			if (s[4] == 'a') {
				a[p] = x;
			} else
			if (s[4] == 'b') {
				b[p] = x;
			}
			if (a[p] + b[p] == 1) Add(p, 1);
		} else {
			scanf("%d", &p);
			p = n - p;
			printf("%d", a[p] ^ b[p] ^ Carry(p));
		}
	}
	puts("");

	return 0;
}
