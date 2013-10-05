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

int cnt[1 << 16];
ull w[2002];
int cmask = (1 << 16) - 1;

int whole = 0;
int on[M];
ull pow2[M];

inline void modify(int x) {
	if (on[x]) {
		on[x] = 0;
		--whole;
	} else {
		on[x] = 1;
		++whole;
	}
	w[x >> 6] ^= (pow2[x & 63]);
} 

inline int calc(ull x) {
	return cnt[x & cmask] + cnt[(x >> 16) & cmask] + cnt[(x >> 32) & cmask] + cnt[(x >> 48) & cmask];
}

inline int findk(int k) {
	if (whole < k) return -1;
	
	for (int i = 0; i < M; ++i) {
		int nw = calc(w[i]);
		if (nw < k) {
			k -= nw;
		} else {
			int res = -1;
			for (int j = 0; j < 64; ++j)
				if (w[i] & pow2[j]) {
					--k;
					if (k == 0) {
						res = j;
						break;
					}
				}
			return (i << 6) + res;
		}
	}

	return -1;
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

	int clim = 1 << 16;
	for (int i = 0; i < clim; ++i) {
		cnt[i] = (i & 1) + cnt[i >> 1];
	}
	for (int i = 0; i <= 64; ++i) pow2[i] = ull(1) << i;

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
    	on[i] = 1;
    	w[ i >> 6 ] |= pow2[i & 63];
    }
    whole = m;
	
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
