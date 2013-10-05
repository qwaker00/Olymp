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

const int N = 4096;

int n;
int a[N];
LL s[N];
short p[N][N];
LL f[2][N];
LL h[N];
int pos[N];
int tree[N];
int hn;

struct Tree {
	int l, r;
	int left, right;
	int minv;

} T[N * 20];
int tn = 0;

int Init(int l, int r) {
	Tree& t = T[tn++];
	t.l = l;
	t.r = r;
	t.minv = 0;
	if (l < r) {
		t.left = Init(l, (l + r) >> 1);
		t.right = Init((l + r + 2) >> 1, r);
	} else {		
		t.left = t.right = -1;
	}
	return tn;
}

int Update(int x, int i, int v) {
	if (i < T[x].l || i > T[x].r) return x;
	if (i == T[x].l && i == T[x].r) {
		Tree& t = T[tn++] = T[x];
		t.minv = v;
		return tn - 1;
	}
	Tree& t = T[tn++] = T[x];
	t.left  = Update(x + x, i, v);
	t.right = Update(x + x + 1, i, v);
	return tn - 1;
}

int Get(int x, int v) {
	if (T[x].minv >= v) return -1;
	if (T[x].l == T[x].r) return T[x].l;
	int t = Get(x + x + 1, v);
	if (t == -1)
		return Get(x + x, v);else
		return t;
}

int main() {
	freopen(".in", "r", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) h[i] = s[i];
	sort(h + 1, h + n + 1);
	hn = unique(h + 1, h + n + 1) - h - 1;
	for (int i = 1; i <= n; ++i) pos[i] = lower_bound(h + 1, h + hn + 1, s[i]) - h;

	for (int i = 1; i <= n; ++i) f[1][i] = s[i];
	for (int j = 2; j <= n; ++j) {
		int w = j & 1;
		int r = 1 - w;
		LL* fr = f[r];
		LL* fw = f[w];

		tn = 0;
		tree[0] = Init(1, hn);
		for (int i = 1; i <= n; ++i) {
			tree[i] = Update(tree[i - 1], pos[i], fr[i] + s[i]);
		}
	}
	
	return 0;
}
