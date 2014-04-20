#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <memory.h>


typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
using namespace std;

#define N 222222

struct Tp {
	int left, right;
	int prior;
	int size;
	bool rev;
	LL value;
	LL sum;
} T[N];
int tn;

inline int size(int x) {
	return x ? T[x].size : 0;
}

inline LL sum(int x) {
	return x ? T[x].sum : 0;
}

void add(int& root, LL value, int prior) {
	if (root == 0) {
		root = ++tn;
		T[root].value = value;
		T[root].sum = value;
		T[root].prior = prior;
		T[root].left = T[root].right = 0;
		T[root].size = 1;
		return;
	}
	if (prior > T[root].prior) {
		int nroot = ++tn;
		T[nroot].value = value;
		T[nroot].prior = prior;
		T[nroot].left = root;
		T[nroot].right = 0;

		T[nroot].size = 1 + size(root);		
		T[nroot].sum = value + sum(root);

		root = nroot;
		return;
	}
	add(T[root].right, value, prior);
	T[root].size = 1 + size(T[root].left) + size(T[root].right);		
	T[root].sum = T[root].value + sum(T[root].left) + sum(T[root].right);
}

void split(int x, int key, int& y, int& z) {
	if (size(x) == key) {
		y = x;
		z = 0;
		return;
	}
	if (T[x].rev) {
		if (T[x].right) T[T[x].right].rev ^= true;
		if (T[x].left)  T[T[x].left].rev ^= true;
		swap(T[x].left, T[x].right);
		T[x].rev = false;
	}
	if (size(T[x].left) >= key) {
		split(T[x].left, key, y, T[x].left);
		z = x;
	} else {
		split(T[x].right, key - 1 - size(T[x].left), T[x].right, z);
		y = x;
	}
	T[x].size = size(T[x].left) + size(T[x].right) + 1;
	T[x].sum = T[x].value + sum(T[x].right) + sum(T[x].left);
}

void merge(int a, int b, int& x) {
	if (a == 0) return void(x = b);
	if (b == 0) return void(x = a);
	if (T[a].rev) {
		if (T[a].right) T[T[a].right].rev ^= true;
		if (T[a].left)  T[T[a].left].rev ^= true;
		swap(T[a].left, T[a].right);
		T[a].rev = false;
	}
	if (T[b].rev) {
		if (T[b].right) T[T[b].right].rev ^= true;
		if (T[b].left)  T[T[b].left].rev ^= true;
		swap(T[b].left, T[b].right);
		T[b].rev = false;
	}
	
	if (T[a].prior > T[b].prior) {
		merge(T[a].right, b, T[a].right);
		x = a;
	} else {
		merge(a, T[b].left, T[b].left);
		x = b;
	}
	T[x].size = size(T[x].left) + size(T[x].right) + 1;
	T[x].sum = T[x].value + sum(T[x].right) + sum(T[x].left);
}

LL getsum(int& root, int l, int r) {
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	split(root, r + 1, t1, t2);
	split(t1, l, t3, t4);
	LL ans = T[t4].sum;
	t1 = 0;
	root = 0;
	merge(t3, t4, t1);
	merge(t1, t2, root);
	return ans;
}

void reverse(int& root, int l, int r) {
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	split(root, r + 1, t1, t2);
	split(t1, l, t3, t4);
	T[t4].rev ^= true;
	t1 = 0;
	root = 0;
	merge(t3, t4, t1);
	merge(t1, t2, root);
}

void list(int root, bool rev = false) {
	if (!root) return;

	rev ^= T[root].rev;
	if (rev) list(T[root].right, rev);else list(T[root].left, rev);
	cerr << T[root].value << " ";
	if (rev) list(T[root].left, rev);else list(T[root].right, rev);
}

//LL a[222222];

int main() {
	freopen("dft.in", "r", stdin);
	freopen("dft.out", "w", stdout);

	srand(0);

    int n, root = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		add(root, LL(x) * x, (rand() << 15) + rand());

//		a[i] = LL(x) * x;
	}

	int q;
	scanf("%d", &q);

//	list(root);
//	cerr << endl;

	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l; --r;

//		cerr << "req: " << l << " " << r << endl;

		LL ans = getsum(root, l, r);

//		LL ans2 = 0;
//		for (int i = l; i <= r; ++i) ans2 += a[i];

//		list(root);
//		cerr << endl;

		if (l < r) {
			reverse(root, l + 1, r);

//			for (int i = 0; i < (r - l) / 2; ++i) {
//				swap(a[i + l + 1], a[r - i]);
//			}
		}
//		list(root);
//		cerr << endl;

		printf("%lld\n", ans);
//		if (ans != ans2) {
//			cerr << "FAILED!!!" << endl;
//			throw 1;
//		}
	}
	
	return 0;
}
