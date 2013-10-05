#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const ld eps = 1e-12;
const ld eps2 = eps;
const int K = 333;
const int M = 1111;
const int N = K * K;

int xs[K], ys[K], xf[N], yf[N];
int X[M], Y[M];

inline int gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

struct cell {
	ld x;
	ld y;
	int tp;

	cell(ld ax = 0, ld ay = 0, int atp = 0) 
		: x(ax)
	 	, y(ay)
	 	, tp(atp) {};	

	bool operator<(const cell& A) const {
		return (x < A.x) || (x == A.x && y < A.y) || (x == A.x && y == A.y && tp < A.tp);
	}
};

bool into(ld x0, ld x1, ld x2) {
	return min(x1, x2) - eps2 <= x0 && x0 - eps2 <= max(x1, x2);
}

bool sinto(ld x0, ld y0, int i) {
	ld A1 = yf[i] - ys[i];
	ld B1 = xs[i] - xf[i];
	ld C1 = -A1 * xf[i] - B1 * yf[i];

	return fabsl(x0 * A1 + y0 * B1 + C1) < eps && into(x0, xs[i], xf[i]) && into(y0, ys[i], yf[i]);
}

bool intersect(int i, int j, ld& X, ld& Y) {
	ld A1 = yf[i] - ys[i];
	ld B1 = xs[i] - xf[i];
	ld C1 = A1 * xf[i] + B1 * yf[i];

	ld A2 = yf[j] - ys[j];
	ld B2 = xs[j] - xf[j];
	ld C2 = A2 * xf[j] + B2 * yf[j];

	ld D = A1 * B2 - A2 * B1;
	if (fabs(D) < eps) return false;

 	X = (C1 * B2 - C2 * B1) / D;
 	Y = (A1 * C2 - A2 * C1) / D;

 	return into(X, xs[i], xf[i]) && into(Y, ys[i], yf[i]) && into(X, xs[j], xf[j]) && into(Y, ys[j], yf[j]);
}

inline ld sqr(ld x) {
	return x * x;
}
inline ld dist(ld x0, ld y0, ld x1, ld y1) {
	return sqrtl(sqr(x0 - x1) + sqr(y0 - y1));
}

vector< cell > all;
vector<int> g[333000];
vector<int> points[N];

vector<char> used, used2;

void dfs1(int x) {
	used[x] = true;
	if (all[x].tp == 1) return;

	for (int i = 0; i < g[x].size(); ++i) {
		if (!used[ g[x][i] ]) {
			dfs1(g[x][i]);
		}
	}
}

ld ans = 0;

void dfs2(int x) {
   	used2[x] = true;
	if (used[x]) return;
	used[x] = true;

	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (!used2[y]) {
			dfs2(y);
		}
	}
}

inline ld cut(ld x) {
	return ld(ll(x * 100000000000ll)) / 100000000000ll;
}

int main() {
	//freopen("in", "r", stdin);

	int n, m;
	scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
    	scanf("%d%d%d%d", xs+i,ys+i,xf+i,yf+i);
    	ans += dist(xs[i], ys[i], xf[i], yf[i]);
    }
    for (int i = 0; i < m; ++i) {
    	scanf("%d%d", X+i,Y+i);
    	all.push_back(cell(X[i], Y[i], 1));
    }

    for (int i = 0; i < n; ++i) {
    	all.push_back(cell(xs[i], ys[i], 0));
    	all.push_back(cell(xf[i], yf[i], 0));

    	for (int j = i + 1; j < n; ++j) {
			ld cx, cy;
			if (intersect(i, j, cx, cy)) {
				all.push_back(cell(cx, cy, 0));
				//cerr << "1" << endl;
			}
    	}    	
    }


	ld xb, yb, xc, yc;
	cin >> xb >> yb >> xc >> yc;
	all.push_back(cell(xb, yb, 2));
	all.push_back(cell(xc, yc, 3));
	for (int i = 0; i < all.size(); ++i) {
		all[i].x = cut(all[i].x);
		all[i].y = cut(all[i].y);
	}
	sort(all.begin(), all.end());
	int cnt = 1;
	for (int i = 1; i < all.size(); ++i)
		if (all[i].x != all[cnt - 1].x || all[i].y != all[cnt - 1].y) {
			all[cnt++] = all[i];
		} else {
			if (all[cnt - 1].tp < all[i].tp) {
				all[cnt - 1].tp = all[i].tp; 
			}
		}
	all.resize(cnt);

	int source = -1;
	int target = -1;
	for (int i = 0; i < all.size(); ++i) {
		if (all[i].tp == 2) {
			source = i;
		}
		if (all[i].tp == 3) {
			target = i;
		}
	}

    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < all.size(); ++j) {
			if (sinto(all[j].x, all[j].y, i)) {
				points[i].push_back(j);
			}
		}

		for (int j = 0; j + 1 < points[i].size(); ++j) {
			g[ points[i][j] ].push_back(points[i][j + 1]);
			g[ points[i][j + 1] ].push_back(points[i][j]);
		}
    }

	n = all.size();
	used2.resize(n);
	used.resize(n);
	dfs1(target);
	if (used[source]) {
		puts("-1");
		return 0;
	}
	dfs2(source);

	for (int i = 0; i < n; ++i)
		if (used2[i])
			for (int j = 0; j < g[i].size(); ++j)
				if (i < g[i][j] && used2[ g[i][j] ]) {
					ans -= dist(all[i].x, all[i].y, all[ g[i][j] ].x, all[ g[i][j] ].y);
					//cerr << all[ points[i][j] ].x << " " << all[ points[i][j] ].y << " " << all[ points[i][j] ].tp << " --> " << all[ points[i][j + 1] ].x << " " << all[ points[i][j + 1] ].y <<  " " << all[ points[i][j + 1] ].tp  << endl;		
				}

	cout.precision(10); cout << fixed;
	cout << ans << endl;

    
	return 0;
}
