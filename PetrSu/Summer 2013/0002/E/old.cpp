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

const int N = 505;
const int M = N * N / 2;

vector<int> g[N];

struct cell {
	int sum;
	int l, r;
} a[M + M + M + M];

int wh[M]; 
pair<int, int> edges[M];
int A[M], B[M];

void build(int x, int l, int r) {
	a[x].l = l; a[x].r = r; a[x].sum = r - l + 1;
	if (l != r) {
		build(x + x, l, (l + r) >> 1);
		build(x + x + 1, ((l + r) >> 1) + 1, r);
	} else {
		wh[l] = x;
	}
}

inline void modify(int x) {
	x = wh[x];
	int add = 1 - a[x].sum - a[x].sum;
	do {
		a[x].sum += add;
		x >>= 1;
	} while (x);
} 
inline int findk(int k) {
	if (a[1].sum < k) return -1;
	
	int x = 1;
	while (a[x].l != a[x].r) {
		if (a[x + x].sum < k) {
			k -= a[x + x].sum;
			x = x + x + 1;
		} else {
			x <<= 1;
		}
	}
	return a[x].l;
}

int n, m, q;

inline void readi(int& x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();

	do {
		x = x * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');
}

int main() {
	freopen("roads.in", "r", stdin);
	freopen("roads.out", "w", stdout);

	readi(n); readi(m); readi(q);
	for (int i = 0; i < m; ++i) {
		readi(A[i]);
		readi(B[i]);

		readi(edges[i].first);
		edges[i].second = i + 1;
	}
	sort(edges, edges + m);
    for (int i = 0; i < m; ++i) {
    	g[ A[ edges[i].second - 1 ] ].push_back(i);
    	g[ B[ edges[i].second - 1 ] ].push_back(i);
    }
	
	build(1, 0, m - 1);
	while (q--) {
		int x = 0, k = 0; 
		readi(x); readi(k);

		if (x == 1) {
			for (int i = 0; i < g[k].size(); ++i)
				modify(g[k][i]);
		} else {
			int res = findk(k);
			if (res == -1) puts("-1");
			else printf("%d\n", edges[res].second);
		}
	}

	return 0;
}
