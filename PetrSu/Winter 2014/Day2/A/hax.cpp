#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

#define N 2111111

int n, m, rn;
int a[N];
int last[N];
int ans[N];
struct Tp {
	int l, r, c;
	Tp(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}

	bool operator<(const Tp & t) const {
		return l < t.l || (l == t.l && r < t.r) || (l == t.l && r == t.r && c < t.c);
	}
} rr[N];
vector<Tp> r[N];

int A[N], L[N], R[N];

inline void minimize(int &x, int y) {
	if (y < x) x = y;
}

void init() {
	memset(A, 63, sizeof(A));
	memset(L, 63, sizeof(L));
	memset(R, 63, sizeof(R));
}
void update(int x, int y) {
//	cerr << "update " << x << " " << y << endl;

	minimize(A[x], y);

	int l = x;
	while (l) {
		minimize(L[l], y);
		l &= l - 1;
	}
	int r = x;
	while (r < N) {
		minimize(R[r], y);
		r = (r | (r - 1)) + 1;
	}
}
int getmin(int l, int r) {
//	cerr << "getmin " << l << " " << r << " = ";

	int ans = 2e9;
	while ((l | (l - 1)) + 1 <= r) {
		minimize(ans, L[l]);
		l = (l | (l - 1)) + 1;
	}
	minimize(ans, A[l]);
	while ( (r & (r - 1)) >= l ) {
		minimize(ans, R[r]);
		r &= r - 1;
	}

//	cerr << ans << endl;

	return ans;
}

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (last[ a[i] ] + 1 <= i - 1)
			r[ last[ a[i] ] + 1 ].push_back( Tp(last[ a[i] ] + 1, i - 1, a[i]) );
		last[ a[i] ] = i;
	}
	for (int i = 0; i <= 1000000; ++i)
		if (last[i] + 1 <= n)
			r[last[i] + 1].push_back( Tp(last[i] + 1, n, i) );

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &rr[i].l, &rr[i].r);
		rr[i].c = i;
	}
	sort(rr, rr + m);

	init();

	for (int i = 0, j = 0; i < m; ++i) {
		while (j <= rr[i].l) {
			for (int k = 0; k < r[j].size(); ++k) {
				update(r[j][k].r, r[j][k].c);
			}
			++j;
		}
//		cerr << "query " << rr[i].l << " " << rr[i].r << endl;
		ans[rr[i].c] = getmin(rr[i].r, n);
	}

	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}


	return 0;
}