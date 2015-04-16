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

const int N = 111111;

struct tp {
	int rx, ry, rd;
	int x, y, d;
	int i;

	bool operator<(const tp& b) const  {
		return x < b.x || x== b.x && y < b.y;
	}
} a[N], b[N];

struct byy {
	bool operator()(const tp& a, const tp& b) const {
		return a.y < b.y || a.y == b.y && a.x < b.x;
	}
};

const double sq2 = sqrt(2);

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

double ansd, anst;
int ansi, ansj;

double dist(double x, double y, double xx, double yy) {
	return sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy));
}

void update(const tp& a, const tp& b, double t) {
	double d = dist(a.rx + t * dx[a.rd], a.ry + t * dy[a.rd], 
   		            b.rx + t * dx[b.rd], b.ry + t * dy[b.rd]);
	if (d < ansd) {
		ansd = d;
		anst = t;
		ansi = a.i;
		ansj = b.i;
	}
}

void find_closest() {
}

int main() {
    freopen("collision.in", "r", stdin);
    freopen("collision.out", "w", stdout);


    cout.precision(12);
    cout << fixed;
    while (1) {
	    int n;
		scanf("%d", &n);
		if (n == 0) break;

		ansd = 1e100;
		for (int i = 0; i < n; ++i) {
			char ch;
			scanf("%d%d %c", &a[i].rx, &a[i].ry, &ch);

			if (ch == 'N')
				a[i].rd = 0;
			else
			if (ch == 'E')
				a[i].rd = 1;
			else
			if (ch == 'S')
				a[i].rd = 2;
			else
			if (ch == 'W')
				a[i].rd = 3;

			a[i].x = a[i].rx;
			a[i].y = a[i].ry;
			a[i].d = a[i].rd;

			a[i].i = i + 1;
		}

		find_closest();

		for (int __it = 0; __it < 4; ++__it) {
			for (int i = 0; i < n; ++i) {
				int x = a[i].y;
				int y = -a[i].x;
				int d = (a[i].d + 1) & 3;
				a[i].x = x;
				a[i].y = y;
				a[i].d = d;
			}
			sort(a, a + n);

			set<tp, byy> all;
			for (int i = 0; i < n; ++i) if (a[i].d == 3) all.insert(a[i]);
			for (int i = 0; i < n; ++i)
				if (a[i].d == 3) {
					all.erase(a[i]);
				} else
				if (a[i].d == 1) {
					set<tp, byy>::iterator it = all.upper_bound(a[i]);
					if (it != all.end()) {
						update(a[i], *it, abs(it->x - a[i].x) / 2.0);
					}
					if (it != all.begin()) {
						--it;
						update(a[i], *it, abs(it->x - a[i].x) / 2.0);
					}
				}
		}

		for (int i = 0; i < n; ++i) {
			a[i].x = a[i].rx - a[i].ry;
			a[i].y = a[i].rx + a[i].ry;
		}
		for (int __it = 0; __it < 4; ++__it) {
			for (int i = 0; i < n; ++i) {
				int x = a[i].y;
				int y = -a[i].x;
				int d = (a[i].d + 1) & 3;
				a[i].x = x;
				a[i].y = y;
				a[i].d = d;
			}
			sort(a, a + n);

			set<tp, byy> all;
			for (int i = 0; i < n; ++i) if (a[i].d == 0) all.insert(a[i]);
			for (int i = 0; i < n; ++i)
				if (a[i].d == 0) {
					all.erase(a[i]);
				} else
				if (a[i].d == 1) {
					set<tp, byy>::iterator it = all.upper_bound(a[i]);
					if (it != all.end()) {
						update(a[i], *it, abs(it->x - a[i].x) / 2.0);
					}
					if (it != all.begin()) {
						--it;
						update(a[i], *it, abs(it->x - a[i].x) / 2.0);
					}
				}
		}
		for (int i = 0; i < n; ++i) {
			a[i].x = a[i].rx + a[i].ry;
			a[i].y = a[i].rx - a[i].ry;
		}
		for (int __it = 0; __it < 4; ++__it) {
			for (int i = 0; i < n; ++i) {
				int x = a[i].y;
				int y = -a[i].x;
				int d = (a[i].d + 1) & 3;
				a[i].x = x;
				a[i].y = y;
				a[i].d = d;
			}
			sort(a, a + n);

			set<tp, byy> all;
			for (int i = 0; i < n; ++i) if (a[i].d == 2) all.insert(a[i]);
			for (int i = 0; i < n; ++i)
				if (a[i].d == 2) {
					all.erase(a[i]);
				} else
				if (a[i].d == 1) {
					set<tp, byy>::iterator it = all.upper_bound(a[i]);
					if (it != all.end()) {
						update(a[i], *it, abs(it->x - a[i].x) / 2.0);
					}
					if (it != all.begin()) {
						--it;
						update(a[i], *it, abs(it->x - a[i].x) / 2.0);
					}
				}
		}

		cout << ansd << "\n" << ansi << " " << ansj << "\n" << anst << "\n\n";
	}
	

    return 0;
}
