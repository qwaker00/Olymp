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

#define N 222222

struct Tp {
	int left, right;

	int cnt;

	int leftv, rightv;
	int setv;

	Tp() : cnt(0), leftv(0), rightv(0), setv(0) {}
	Tp(int cnt, int leftv, int rightv) : cnt(cnt), leftv(leftv), rightv(rightv) {}
} T[N * 5];
int tn, troot[N], tindex[N], thead[N];

int n, q;
vector<int> g[N];
int p[N][22], w[N], b[N], d[N];
int v[N], vn;
int counter;

inline void tree_setv(Tp* T, int x, int v) {
	T[x].setv = T[x].leftv = T[x].rightv = v;
	T[x].cnt = T[x].right - T[x].left;
}

void tree_init(Tp* T, int x, int l, int r) {
	T[x].left = l;
	T[x].right = r;
	T[x].setv = 0;
	if (l < r) {
		tree_init(T, x + x, l, (l + r) >> 1);
		tree_init(T, x + x + 1, (l + r + 2) >> 1, r);
		T[x].leftv = T[x + x].leftv;
		T[x].rightv = T[x + x + 1].rightv;
		T[x].cnt = 0;
	} else {
		tree_setv(T, x, ++counter);
		T[x].cnt = 0;
	}
}

void tree_set(Tp* T, int x, int l, int r, int v) {
	if (T[x].left > r || T[x].right < l) return;
	if (T[x].left >= l && T[x].right <= r) return tree_setv(T, x, v);
	if (T[x].setv) {
		tree_setv(T, x + x, T[x].setv);
		tree_setv(T, x + x + 1, T[x].setv);
		T[x].setv = 0;
	}
	tree_set(T, x + x, l, r, v);
	tree_set(T, x + x + 1, l, r, v);
	T[x].leftv = T[x + x].leftv;
	T[x].rightv = T[x + x + 1].rightv;
	T[x].cnt = T[x + x].cnt + T[x + x + 1].cnt + (T[x + x].rightv != 0 && T[x + x].rightv == T[x + x + 1].leftv);
}

Tp tree_get(Tp* T, int x, int l, int r) {
	if (T[x].left > r || T[x].right < l) return Tp();
	if (T[x].left >= l && T[x].right <= r) return T[x];
	if (T[x].setv) {
		tree_setv(T, x + x, T[x].setv);
		tree_setv(T, x + x + 1, T[x].setv);
		T[x].setv = 0;
	}
	Tp t1 = tree_get(T, x + x, l, r);
	Tp t2 = tree_get(T, x + x + 1, l, r);
	return Tp(t1.cnt + t2.cnt + (t1.rightv != 0 && t1.rightv == t2.leftv), t1.leftv, t2.rightv);
}

int tree_get_value(Tp* T, int x, int l) {
	while (!T[x].setv) {
		x = x + x + (l >= T[x + x + 1].left);
	}
	return T[x].setv;
}

void build(int x) {
//	cerr << "Build:";

	int it = 0, head = x;
	while (x) {
//		cerr << " " << x;

		troot[x] = tn;
		tindex[x] = it++;
		thead[x] = head;
		x = b[x];
	}
//	cerr << endl;

	tree_init(T + tn, 1, 0, it - 1);
	tn += it * 4 + 1;
}

int lca(int x, int y) {
	for (int i = 18; i >= 0; --i)
		if (d[p[x][i]] >= d[y])
			x = p[x][i];
	for (int i = 18; i >= 0; --i)
		if (d[p[y][i]] >= d[x])
			y = p[y][i];

	if (x == y) return x;

	for (int i = 18; i >= 0; --i)
		if (p[x][i] != p[y][i]) {
			y = p[y][i];
			x = p[x][i];
		}

	return p[x][0];
}

void update(int x, int y) {
	++counter;
	int z = lca(x, y);
	while (troot[x] != troot[z]) {
		tree_set(T + troot[x], 1, 0, tindex[x], counter);
		x = p[thead[x]][0];
	}
	tree_set(T + troot[x], 1, tindex[z], tindex[x], counter);
	while (troot[y] != troot[z]) {
		tree_set(T + troot[y], 1, 0, tindex[y], counter);
		y = p[thead[y]][0];
	}
	tree_set(T + troot[y], 1, tindex[z], tindex[y], counter);
}

int request(int x, int y) {
	int z = lca(x, y);
	int ans = (d[x] - d[z]) + (d[y] - d[z]);
	while (troot[x] != troot[z]) {
		ans -= tree_get(T + troot[x], 1, 0, tindex[x]).cnt;
		ans -= tree_get_value(T + troot[x], 1, 0) == tree_get_value(T + troot[p[thead[x]][0]], 1, tindex[p[thead[x]][0]]);
		x = p[thead[x]][0];
	}
	ans -= tree_get(T + troot[x], 1, tindex[z], tindex[x]).cnt;
	while (troot[y] != troot[z]) {
		ans -= tree_get(T + troot[y], 1, 0, tindex[y]).cnt;
		ans -= tree_get_value(T + troot[y], 1, 0) == tree_get_value(T + troot[p[thead[y]][0]], 1, tindex[p[thead[y]][0]]);
		y = p[thead[y]][0];
	}
	ans -= tree_get(T + troot[y], 1, tindex[z], tindex[y]).cnt;
	return  ans;
}


void dfs(int x) {	
	w[x] = 1;
	b[x] = 0;

	for (int i = 1; p[x][i - 1]; ++i) {
		p[x][i] = p[p[x][i - 1]][i - 1];
	}

	for (int i = 0, y; i < (int)g[x].size(); ++i) {
		if (p[x][0] == (y = g[x][i])) continue;
		p[y][0] = x;
		d[y] = d[x] + 1;

		dfs(y);

		if (b[x] == 0) {
			b[x] = y;
		} else
		if (w[y] > w[b[x]]) {
			build(b[x]);
			b[x] = y;
		} else {
			build(y);
		}
		w[x] += w[y];
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    d[1] = 1;
    dfs(1);
    build(1);

    scanf("%d", &q);
    while (q--) {
    	int t, x, y;
    	scanf("%d%d%d", &t, &x, &y);
    	if (t == 0)
    		printf("%d\n", request(x, y));
    	else
    		update(x, y);
    }

    return 0;
}
