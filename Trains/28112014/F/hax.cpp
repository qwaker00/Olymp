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

struct Tp {
	int x, y, r;
};

LL gcd(LL x, LL y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

struct Rat {
	LL x, y;

	Rat() : x(0), y(1) {}
	Rat(LL _x, LL _y) : x(_x), y(_y) {
		if (x == 0) y = 1;
		if (y == 0) x = 1;
		if (y < 0) {
			x = -x;
			y = -y;
		}
		LL g = gcd(llabs(x), llabs(y));
		x /= g;
		y /= g;	
	}

	Rat operator*(const int M) const {
		return Rat(x * M, y);
	}
	Rat operator/(const int M) const {
		return Rat(x, y * M);
	}
	Rat operator-() const {
		return Rat(-x, y);
	}

	void out() {
		if (x == 0) {
			cout << "not moving";
			return;
		}
		if (y == 1) {
			cout << llabs(x);
		} else {
			cout << llabs(x) << "/" << y;
		}
		if (x > 0) {
			cout << " clockwise";
		} else {
			cout << " counterclockwise";
		}
	}
};

inline int dist(Tp& a, Tp& b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
	cin >> T;   	
	while (T--) {
		int n;
		cin >> n;
		vector< vector<int> > g(n);
		vector<Tp> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].x >> a[i].y >> a[i].r;
			for (int j = 0; j < i; ++j)
				if (dist(a[i], a[j]) == sqr(a[i].r + a[j].r)) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
		}
		vector<Rat> speed(n);
		queue<int> q;
		vector<bool> was(n);
		speed[0] = Rat(1, 1);
		was[0] = 1;
		q.push(0);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (size_t i = 0; i < g[x].size(); ++i) {
				int y = g[x][i];	
				if (!was[y]) {
					q.push(y);
					was[y] = 1;
					speed[y] = -(speed[x] * a[x].r / a[y].r);
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			speed[i].out();
			cout << "\n";
		}
	}

    return 0;
}
