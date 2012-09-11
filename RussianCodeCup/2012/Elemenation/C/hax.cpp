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

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


struct Node {
	int l, r;
	int add, ma, mi;
	int minind;
} T[222222];
set<int> q[222222];
int n, m, k, id, cnt = 0, kupe[222222];
char line[222];

void Init(int x, int l, int r) {
	T[x].l = l, T[x].r = r;
	T[x].minind = l;
	if (l != r) {
		int c = (l + r) >> 1;
		Init(x + x, l, c);
		Init(x + x + 1, c + 1, r);
	}
}

void Add(int x, int p, int dy) {
	if (T[x].l == T[x].r) {
		T[x].add += dy;
		T[x].ma += dy;
		T[x].mi += dy;
		return;
	}
	int c = (T[x].l + T[x].r) >> 1;
	if (p <= c) Add(x + x, p, dy); else
				Add(x + x + 1, p, dy);

	T[x].ma = max(T[x + x].ma, T[x + x + 1].ma) + T[x].add;
	if (T[x].ma == T[x + x].ma + T[x].add)
		T[x].minind = T[x + x].minind;else
		T[x].minind = T[x + x + 1].minind;

	T[x].mi = min(T[x + x].mi, T[x + x + 1].mi) + T[x].add;
}

int Free(int x) {
	if (T[x].l == T[x].r) return T[x].r;

	if (T[x].mi == T[x + x].mi + T[x].add) {
		return Free(x + x);
	} else
		return Free(x + x + 1);
}

inline bool Bad() {
	return T[1].ma - T[1].mi >= 2;
}

int GetMax(int x, int l, int r) {
	if (l <= T[x].l && r>= T[x].r) {
		return T[x].ma;
	}
	if (l > T[x].r || r < T[x].l) return -(int)1e9;
	return max(GetMax(x + x, l, r), GetMax(x + x + 1, l, r)) + T[x].add;
}

int MinIndMax(int x, int l, int r, int& minind) {
	if (l <= T[x].l && r >= T[x].r) {
		minind = T[x].minind;
		return T[x].ma;
	}
	int c = (T[x].l + T[x].r) >> 1;
	if (l > c) return MinIndMax(x + x + 1, l , r, minind);else
	if (r <= c) return MinIndMax(x + x, l , r, minind);
	int m1, m2;
	int t1 = MinIndMax(x + x, l, r, m1);
	int t2 = MinIndMax(x + x + 1, l, r, m2);
	if (t1 >= t2) minind = m1; else minind = m2;
	return max(t1, t2) + T[x].add;
}

int MaxKupe(int x, int nei) {
	int step = 20, offset = 0;
	while (step >= 0) {
		if (GetMax(x, nei - offset - (1 << step), nei + offset + (1 <<step)) != T[1].ma) {
			offset += (1 << step);
		}
		step--;
	}
	int m1;
	MinIndMax(x, nei - offset - 1, nei + offset + 1, m1);
	return m1;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d%d%d\n", &m, &n, &k);

	Init(1, 1, n);
	while (m--) {	
		gets(line);
		if (line[0] == '+') {
			++cnt;
			int kid = Free(1);
//			cerr << kid << endl;
			kupe[cnt] = kid;
			Add(1, kid, 1);
			q[kid].insert(cnt);
		} else {
			sscanf(line + 2, "%d", &id);

			int kid = kupe[id];
			q[kid].erase(id);
			kupe[id] = -1;
			Add(1, kid, -1);
			if (Bad()) {
				int kidi = MaxKupe(1, kid);
				int it = *q[kidi].begin(); q[kidi].erase(q[kidi].begin());
				kupe[it] = kid;
				q[kid].insert(it);
				Add(1, kid, 1);
				Add(1, kidi, -1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d", q[i].size());
		for (set<int>::iterator j = q[i].begin(); j != q[i].end(); j++)
			printf(" %d", *j);
		puts("");
	}

	return 0;
}
