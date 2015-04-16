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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 100111;
const int THRES = 88;

int n;
int a[N];
pair<int, int> b[N];

ULL sa[N], sb[N];

inline void update() {
	for (int i = 1; i <= n; ++i) sa[i] = sa[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) sb[i] = sb[i - 1] + sa[b[i].second] - sa[b[i].first - 1];
}

const int NN = N * 66;

struct Tree {
	int left, right, sum;
} T[NN];
int Root[N], Tn = 0;

inline int clone(int x) {
	//assert(Tn + 3 < NN);
	++Tn;
	if (x != 0) T[Tn] = T[x];
	return Tn;
}

int tree_count(int x, int l, int r, int pos) {
	int sum = 0;
	while (x) {              
		sum += T[x].sum;		
		int c = (l + r) >> 1;
		if (pos <= c) {
			x = T[x].left;
			r = c;
		} else {
			x = T[x].right;
			l = c + 1;
		}
	}
	return sum;
}

int tree_add(int x, int l, int r, int lq, int rq) {
	if (l > rq || r < lq) return x;
	if (l >= lq && r <= rq) {
		int y = clone(x);
		++T[y].sum;
		return y;
	}
	int y = clone(x);
	T[y].left = tree_add(T[y].left, l, (l + r) >> 1, lq, rq);
	T[y].right = tree_add(T[y].right, (l + r + 2) >> 1, r, lq, rq);
	return y;
}

int cover(int pos, int l, int r) {
	return tree_count(Root[r], 1, n, pos) -
		   tree_count(Root[l - 1], 1, n, pos);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

	Root[0] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &b[i].first, &b[i].second);
		int t = Tn;
		Root[i] = tree_add(Root[i - 1], 1, n, b[i].first, b[i].second);
		//cerr << Tn - t << endl;
		//cerr << b[i].first << " " << b[i].second << endl;
		//for (int j = 1; j <= n; ++j) cerr << tree_count(Root[i], 1, n, j) << " ";
		//cerr << endl;
	}
	update();

	int q;
	scanf("%d", &q);
	vector< pair<int, int> > ch;
	while (q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			ch.push_back(make_pair(x, y - a[x]));
			a[x] = y;
		} else {
			if (ch.size() > THRES) {
				update();
				ch.clear();
			}
			ULL ans = sb[y] - sb[x - 1];
			for (int i = 0; i < (int)ch.size(); ++i) {
				ans += LL(ch[i].second) * cover(ch[i].first, x, y);
			}
			printf("%llu\n", ans);
		}
	}

    return 0;
}
