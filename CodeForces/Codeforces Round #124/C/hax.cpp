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

#define N 1555

LL xx[N], yy[N];
vector<int> g[N];
int n, x, y;
int was[N], w[N], p[N], ans[N];

struct Tp{
	int x, y, i;

	bool operator<(const Tp &B)const{
		return x < B.x || x == B.x && y < B.y;
	}
} a[N];

class AngleCompare {
	int cx, cy;

public:
	AngleCompare(int x, int y) : cx(x), cy(y) { };

	bool operator()(const Tp& A, const Tp& B) {
//		cerr << A.x << " " << A.y << " vs " << B.x << " " << B.y << "\t\t" << (LL(A.x - cx) * (B.y - cy) <= LL(B.x - cx) * (A.y - cy)) << endl;
		return LL(A.x - cx) * (B.y - cy) <= LL(B.x - cx) * (A.y - cy);
	}
};

/*
bool intersect(int p1, int p2, int p3, int p4) {
	if (p1 == p3 && p2 == p4 || p1 == p4 && p2 == p3) return true;
	if (p1 == p3 || p1 == p4 || p2 == p4 || p2 == p3) return false;

	LL a = yy[p2] - yy[p1];
	LL b = xx[p1] - xx[p2];
	LL c = -a * xx[p1] - b * yy[p1];
	LL t1 = a * xx[p3] + b * yy[p3] + c;
	LL t2 = a * xx[p4] + b * yy[p4] + c;
	if (t1 < 0 && t2 < 0 || t1 > 0 && t2 > 0) return false;

	a = yy[p4] - yy[p3];
	b = xx[p3] - xx[p4];
	c = -a * xx[p3] - b * yy[p3];
	t1 = a * xx[p1] + b * yy[p1] + c;
	t2 = a * xx[p2] + b * yy[p2] + c;
	if (t1 < 0 && t2 < 0 || t1 > 0 && t2 > 0) return false;
	return true;
}
*/

void dfs(int x) {
	was[x] = true;
	w[x] = 1;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (!was[y]) {
			dfs(y);
			p[y] = x;
			w[x] += w[y];
		}
	}
}

void dfs2(int x, int l, int r) {
	sort(a + l + 1, a + r, AngleCompare(a[l].x, a[l].y));
//	return;

	ans[a[l].i] = x + 1;

	int off = 1;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (p[y] == x) {
			dfs2(y, l + off, l + off + w[y]);
			off += w[y];
		}
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].i = i;
	}
	sort(a, a + n);

	dfs(0);
	dfs2(0, 0, n);

	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;

	return 0;
}
