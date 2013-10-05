//#define DEBUG
#include <stdio.h>
#include <assert.h>
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
#include <time.h>


typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const LD PI = acos(-1.);
using namespace std;

#define N 333333

int l, n;
struct Tp {
	int l, r;
	int ll, rr;
} a[N], b[N];

bool ByR(const Tp& a, const Tp& b) {
	return a.r > b.r || a.r == b.r && a.l > b.l;
}

struct Tree {
	int val;
	int sval;

	int gen;
	int sgen;

	int l;
	int r;
	int w;
} T[N * 6];
int h[N*2], hn = 0, removed[N], an = 0, posb[N], prev[N], next[N];
vector<int> ans[N];

void Init(int x, int l, int r) {
	T[x].sval = -1;
	T[x].sgen = -1;
	T[x].l = l;
	T[x].r = r;
	T[x].w = h[r + 1] - h[l];
	if (l < r) {
		Init(x + x, l, (l + r) >> 1);
		Init(x + x + 1, (l + r + 2) >> 1, r);
	} 
//		else cerr << l << " " << T[x].w << endl;
}

void SetV(int x, int l, int r, int v) {
	if (r < T[x].l || l > T[x].r) return;
	if (l <= T[x].l && r >= T[x].r) {
		T[x].sval = v;
		T[x].val = v * T[x].w;
		return;
	}
	if (T[x].sval != -1) {
		T[x + x].sval = T[x].sval; T[x + x].val = T[x].sval * T[x + x].w;
		T[x + x + 1].sval = T[x].sval; T[x + x + 1].val = T[x].sval * T[x + x + 1].w;
	}
	SetV(x + x, l, r, v);
	SetV(x + x + 1, l, r, v);
	T[x].sval = -1;
	T[x].val = T[x + x].val + T[x + x + 1].val;
}

void SetGen(int x, int l, int r, int v) {
	if (r < T[x].l || l > T[x].r) return;
	if (l <= T[x].l && r >= T[x].r) {
		T[x].sgen = v;
		T[x].gen = v;
		return;
	}
	if (T[x].sgen != -1) {
		T[x + x].sgen = T[x + x].gen = T[x].sgen;
		T[x + x + 1].sgen = T[x + x + 1].gen = T[x].sgen;
	}
	SetGen(x + x, l, r, v);
	SetGen(x + x + 1, l, r, v);
	T[x].sgen = -1;
	T[x].gen = max(T[x + x].gen, T[x + x + 1].gen);
}

int GetV(int x, int l, int r) {
	if (r < T[x].l || l > T[x].r) return 0;
	if (l <= T[x].l && r >= T[x].r) return T[x].val;
	if (T[x].sval != -1) {
		T[x + x].sval = T[x].sval; T[x + x].val = T[x].sval * T[x + x].w;
		T[x + x + 1].sval = T[x].sval; T[x + x + 1].val = T[x].sval * T[x + x + 1].w;
	}
	return GetV(x + x, l, r) + GetV(x + x + 1, l, r);
}

int GetGen(int x, int l, int r) {
	if (r < T[x].l || l > T[x].r) return -1;
	if (l <= T[x].l && r >= T[x].r) return T[x].gen;
	if (T[x].sgen != -1) {
		T[x + x].sgen = T[x + x].gen = T[x].sgen;
		T[x + x + 1].sgen = T[x + x + 1].gen = T[x].sgen;
		T[x].sgen = -1;
	}
	return max(GetGen(x + x, l, r), GetGen(x + x + 1, l, r));
}


int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d%d", &l, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].l, &a[i].r);
//		--a[i].r;

		b[i] = a[i];
		b[i].ll = i;

		h[hn++] = a[i].l;
		h[hn++] = a[i].r;	
	}
	sort(h, h + hn);
	hn = unique(h, h + hn) - h;
	h[hn] = l;

	sort(b, b + n, ByR);
	for (int i = 0; i < n; ++i) posb[b[i].ll] = i;

	for (int i = 0; i < n; ++i) {
		prev[i] = i - 1;

		if (posb[i] > 0)
			next[i] = b[posb[i] - 1].ll;else
			next[i] = -1;
	}

	for (int i = 0; i < n; ++i) {
		a[i].ll = lower_bound(h, h + hn, a[i].l) - h;
		a[i].rr = lower_bound(h, h + hn, a[i].r) - h;
	}

	Init(1, 0, hn - 1);
	SetV(1, 0, hn - 1, 1);

	priority_queue< pair<int, int> > q;
	for (int i = 0; i < n; ++i) {
		q.push(make_pair(-(a[i].r - a[i].l), -i));
	}
	while (!q.empty()) {
		pair<int, int> t = q.top(); q.pop();
		int d = -t.first;
		int i = -t.second;

		if (removed[i]) continue;
		if (GetV(1, a[i].ll, a[i].rr - 1) != d) continue;

		if (d == 0) {
			ans[GetGen(1, a[i].ll, a[i].rr - 1)].push_back(i);
		} else {
			SetV(1, a[i].ll, a[i].rr - 1, 0);
			SetGen(1, a[i].ll, a[i].rr - 1, an);
			ans[an++].push_back(i);
		}
		removed[i] = true;
		if (prev[i] != -1 && !removed[prev[i]]) {
			int w = GetV(1, a[prev[i]].ll, a[prev[i]].rr - 1);
			q.push(make_pair(-w, -prev[i]));
		}
		if (next[i] != -1 && !removed[next[i]]) {
			int w = GetV(1, a[next[i]].ll, a[next[i]].rr - 1);
			q.push(make_pair(-w, -next[i]));
		}
	}
	for (int i = 0; i < an; ++i) {
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); ++j)
			printf("%d\n", ans[i][j] + 1);
	}

//	cerr << clock() << endl;

	return 0;
}

