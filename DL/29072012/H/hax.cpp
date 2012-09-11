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
typedef long double LD;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 1111
#define eps 1e-12

int n, m, ans1, ans2;
int bad1[N];
LL x, y;

struct Tp {
	LL x1, y1, x2, y2, d;
} a[N];

LL myabs(LL x) {
	if (x < 0) return -x;else return x;
}

bool In(Tp& a, LL x, LL y) {
	LL A = a.y2 - a.y1;
	LL B = a.x1 - a.x2;
	LL C = - a.x1 * A - a.y1 * B;
	LL dd = myabs(C - (-x * A - y * B));
	return (dd * 2 < a.d * sqrtl(A*A + B*B) + eps);
}

int main() {
    freopen("roads.in", "r", stdin);
    freopen("roads.out", "w", stdout);
                       
    ans1 = ans2 = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].d;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
    	cin >> x >> y;
    	bool bad = false;
    	for (int j = 0; j < n; ++j) if (In(a[j], x, y)) {
    		bad = true;
    		bad1[j] = true;
    	}
    	if (bad) ++ans2;
    }                                   
    for (int i = 0; i < n; i++) ans1 += bad1[i];
    cout << ans1 << " " << ans2 << endl;

    return 0;
}
