#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
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

#define eps 1e-9

long double x1, x2, Y1, y2, r1, r2;
long double vx, vy, xx, yy, v;

int main() {
    freopen("dome.in", "r", stdin);
    freopen("dome.out", "w", stdout);

	cin >> x1 >> Y1 >> r1;
	cin >> x2 >> y2 >> r2;

	long double d = sqrtl((x1 - x2)*(x1 - x2) + (Y1 - y2)*(Y1 - y2));
	if (d + r1 <= r2 + eps) {
		cout << r2 << " " << x2 << " " << y2 << endl;
		return 0;
	}
	if (d + r2 <= r1 + eps) {
		cout << r1 << " " << x1 << " " << Y1 << endl;
		return 0;
	}
	long double l = d + r1 + r2;
	cout.precision(10);
	cout << fixed;
	vx = x2 - x1;
	vy = y2 - Y1;
	v = sqrtl(vx*vx + vy*vy);
	xx = vx / v * (r2 - l / 2) + x2;
	yy = vy / v * (r2 - l / 2) + y2;
	cout << l / 2 << " " << xx << " " << yy << endl;

    return 0;
}
