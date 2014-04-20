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

#define N 111111

int a[N], h[N], hn = 0, n, m, ans[N], b[N], c[N];

struct Tp {
	int l, r, i;
	int ll;
	bool operator<(const Tp& t) const {
		return ll < t.ll || (ll == t.ll && r < t.r);
	}
} r[N];


struct Tt {
	int l, r;
	int add, min;
} T[N * 4];

void Init(int x, int l, int r) {
	T[x].l = l;
	T[x].r = r;
	if (l < r) {
		Init(x + x, l, (l + r) >> 1);
		Init(x + x + 1, (l + r + 2) >> 1, r);
		T[x].min = min(T[x + x].min, T[x + x + 1].min);
	} else {
		T[x].min = -h[l];
	}
}

void Inc(int x, int l, int r, int y) {
	if (T[x].l > r || T[x].r < l) return;
	if (l <= T[x].l && r >= T[x].r) {
		T[x].add += y;
		T[x].min += y;
		return;
	}
	Inc(x + x, l, r, y);
	Inc(x + x + 1, l, r, y);
	T[x].min = min(T[x + x].min, T[x + x + 1].min) + T[x].add;
}

void Add(int i) {
	int id = b[i];
	s += 
	if (++c[i] > 1) {
		if (id + 1 <= hn - 1)
			Inc(1, id + 1, hn - 1, h[id]);
	} else {
		if (id <= hn - 1)
			Inc(1, id, hn - 1, h[id]);
	}
}

void Del(int i) {
	int id = b[i];
	if (--c[i] > 0) {
		if (id + 1 <= hn - 1)
			Inc(1, id + 1, hn - 1, -h[id]);
	} else {
		if (id <= hn - 1)
			Inc(1, id, hn - 1, -h[id]);
	}
}

int Calc(int x, int l, int r) {
	
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		h[hn++] = a[i];
	}
	sort(h, h + hn);
	hn = unique(h, h + hn) - h;
	for (int i = 0; i < n; ++i) b[i] = lower_bound(h, h + hn, a[i]) - h;

	scanf("%d", &m);
	int S = sqrt(m) + 1;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &r[i].l, &r[i].r);
		r[i].i = i;
		r[i].ll = r[i].l / S;
	}
	sort(r, r + m);

	Init(1, 0, hn - 1);
	int L = r[0].l, R = r[0].r - 1;
	for (int i = 0; i < m; ++i) {
		while (r[i].r > R) Add(++R);
		while (r[i].r < R) Del(R--);

		while (r[i].l > L) Add(++L);
		while (r[i].l < L) Del(L--);

		ans[r[i].i] = Calc(1, 0, hn - 1);
	}
	for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);

    
    return 0;
}
