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

typedef long long LL;
using namespace std;

const LL N = 4096;

LL   n;
LL   a[N*10];
LL    s[N*10];
short p[N][N];
LL    f[3][N*10];
pair<LL, LL> h[N*10];
LL pos[N*10];
LL hn;

struct Tree {
	LL l, r;
	LL left, right;

	LL minv;
} T[N * 20];
LL tn = 0;

LL Init(LL l, LL r) {
	Tree& t = T[tn++];
	LL ret = tn - 1;
	t.l = l;
	t.r = r;
	t.minv = LL(1e18);
	if (l < r) {
		t.left = Init(l, (l + r) >> 1);
		t.right = Init((l + r + 2) >> 1, r);
	} else {		
		t.left = t.right = -1;
	}
	return ret;
}

void Update(LL x, LL i, LL v) {
	if (i < T[x].l || i > T[x].r) return;
	if (i == T[x].l && i == T[x].r) {
		T[x].minv = v;
		return;
	}
	Update(T[x].left, i, v);
	Update(T[x].right, i, v);
	T[x].minv = min(T[T[x].left].minv, T[T[x].right].minv);
}

LL Get(LL x, LL v) {
	if (T[x].minv >= v) return -1;
	if (T[x].l == T[x].r) return T[x].l;
	LL t = Get(T[x].right, v);
	if (t == -1)
		return Get(T[x].left, v);else
		return t;
}
int main() {
//	freopen(".in", "r", stdin);

	scanf("%I64d", &n);
	for (LL i = 1; i <= n; ++i) {
		scanf("%I64d", a + i);
		s[i] = s[i - 1] + a[i];
	}
	for (LL i = 1; i <= n; ++i) {
		h[i].first = s[i];
		h[i].second = i;
	}
	sort(h + 1, h + n + 1);
//	hn = unique(h + 1, h + n + 1) - h - 1;
	hn = n;
	for (LL i = 1; i <= n; ++i) pos[i] = lower_bound(h + 1, h + hn + 1, make_pair(s[i], i)) - h;

	for (LL i = 1; i <= n; ++i) f[1][i] = s[i];

	LL ans = 1;

	LL w, r;
	for (LL j = 2; j <= n; ++j) {
		w = j & 1;
		r = 1 - w;
		LL* fr = f[r];
		LL* fw = f[w];
		tn = 0;
		Init(1, hn);
		for (LL i = 1; i <= n; ++i) {
			LL x = Get(0, s[i]);

			if (x == -1) {
				fw[i] = LL(1e18);
			} else {
				fw[i] = s[i] - h[x].first;
				p[j][i] = h[x].second;
			}
			if (fr[i] < 1e18)
				Update(0, pos[i], fr[i] + s[i]);
		}
		if (fw[n] < 1e17) ans = j;
	}
	printf("%I64d\n", ans);
	LL x = n;
	vector<LL> q;
	for (LL i = 1; i < ans; ++i) {
		q.push_back(p[ans - i + 1][x]);
		x = p[ans - i + 1][x];
	}
	for (LL i = 0; i < q.size(); ++i) printf("%I64d ", q[(LL)q.size() - i - 1]);
	if (q.size() != 0)
	puts("");
	
	return 0;
}
