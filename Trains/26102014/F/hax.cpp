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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int xa, ya, xb, yb, xc, yc, m1, m2, h1, h2;
    int d, v, w;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	cin >> d >> v;
	scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
	cin >> w;
	   	 
	LD t1 = 60 * (sqrtl( sqr(xa - xc) + sqr(ya - yc) ) + sqrtl( sqr(xb - xc) + sqr(yb - yc) )) / v + d;

	LD t2 = h1 * 60 + m1 - 9 * 60 + h2 * 60 + m2;

	LD t3 = 0;
	if (fabsl(sqrtl( sqr(xa - xc) + sqr(ya - yc) ) + sqrtl( sqr(xb - xc) + sqr(yb - yc) ) - sqrtl(sqr(xa - xb) + sqr(ya - yb))) < 1e-9) {
		t3 = sqrtl(sqr(xa - xb) + sqr(ya - yb)) / w * 60 + d;
	} else {
		t3 = sqrtl(sqr(xa - xb) + sqr(ya - yb)) / w * 60;
	}

	if (t1 < t2 && t1 < t3) {
		cout << "Alex\n";
	} else
	if (t2 < t3 && t2 < t3) {
		cout << "Dmitry\n";
	} else
	if (t3 < t2 && t3 < t1) {
		cout << "Petr\n";
	}
    
    return 0;
}
