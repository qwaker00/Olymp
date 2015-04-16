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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;
struct cell {
	int l, r, mx, cnt;
} a[4*N];

int b[N], pos[N];

void relax(int x) {
	a[x].mx = max(a[x + x].mx, a[x + x + 1].mx);
	a[x].cnt = 0;
	if (a[x].mx == a[x + x].mx) a[x].cnt += a[x + x].cnt;
	if (a[x].mx == a[x + x + 1].mx) a[x].cnt += a[x + x + 1].cnt;
}

void build(int x, int l, int r) {
	a[x].l = l; a[x].r = r;
	if (l < r) {
		build(x + x, l, (l + r) / 2);
		build(x + x + 1, ((l + r) / 2) + 1, r);
		relax(x);
	} else {
		a[x].mx = b[l];
		a[x].cnt = 1;
		pos[l] = x;
	}
}

void modify(int x, int val) {
	x = pos[x];
	a[x].mx += val;
	x /= 2;
	while (x) {
		relax(x);
		x /= 2;
	}
}

inline ll calc() {
	return ll(a[1].mx) * a[1].cnt;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", b + i);
	build(1, 0, n - 1);

	ll ans = calc();
	for (int i = 0; i < n; ++i) {
		if (!b[i]) continue;
		
		modify(i, -1);
		if (i) {
			modify(i - 1, 1);
			ans = min(ans, calc());
			modify(i - 1, -1);	
		}
		if (i + 1 < n) {
			modify(i + 1, 1);
			ans = min(ans, calc());
			modify(i + 1, -1);
		}
		modify(i, 1);
	}

	cout << ans << endl;
    
    return 0;
}
