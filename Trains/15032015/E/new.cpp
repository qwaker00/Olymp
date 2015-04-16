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


using namespace std;

const int IT = 2500;
const LD PI = 3.1415926535897932384626433832795;
const LD eps = 1e-10;

struct Tp {
	LD x, y;
} a[88888];
int n;

inline LD bbox(LD ang) {
	LD x, y;
	LD co = cos(ang), si = sin(ang);
	LD maxx = -1e100, maxy = -1e100, minx = 1e100, miny = 1e100;
	for (int i = 0; i < n; ++i) {
		x = co * a[i].x - si * a[i].y;
		y = si * a[i].x + co * a[i].y;		
		if (x > maxx) maxx = x;
		if (x < minx) minx = x;
		if (y > maxy) maxy = y;
		if (y < miny) miny = y;
	}
	return (maxx - minx) * (maxy - miny);
}

inline void rot_out(LD x, LD y, LD ang) {
	LD co = cos(ang), si = sin(ang);
	LD xo = co * x - si * y;
	LD yo = si * x + co * y;		
	cout << double(xo) << " " << double(yo) << endl;
}

inline void bbox_out(LD ang) {
	LD x, y;
	LD co = cos(ang), si = sin(ang);
	LD maxx = -1e100, maxy = -1e100, minx = 1e100, miny = 1e100;
	for (int i = 0; i < n; ++i) {
		x = co * a[i].x - si * a[i].y;
		y = si * a[i].x + co * a[i].y;		
		if (x > maxx) maxx = x;
		if (x < minx) minx = x;
		if (y > maxy) maxy = y;
		if (y < miny) miny = y;
	}

	rot_out(minx, miny, -ang);
	rot_out(maxx, miny, -ang);
	rot_out(maxx, maxy, -ang);
	rot_out(minx, maxy, -ang);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		a[i].x = x;
		a[i].y = y;
	}

	LD ans = 1e100, ansa = 0;
	for (int it = 0; it < IT; ++it) {
		LD c1 = PI / 2 / IT * it;
		LD b1 = bbox(c1);
		if (b1 < ans) {
			ans = b1;
			ansa = c1;
		}
	}

	cout.precision(12);
	cout << fixed;
	bbox_out(ansa);

	cerr << clock() << endl;
    
    return 0;
}
