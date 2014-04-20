#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, q, l, w;
struct Tp {
	int type, x, y1, y2, i;

	Tp() {}
	Tp(int type, int x, int y1, int y2, int i) : type(type), x(x), y1(y1), y2(y2), i(i) {}

	bool operator<(const Tp& t) const {
		return type > t.type || (type == t.type && x < t.x);
	}
} Q[444444];
int qn;
LL ans[222222];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    scanf("%d%d%d%d", &n, &q, &l, &w);
    for (int i = 0; i < n; ++i) {
    	int x1, y1, x2, y2;
    	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    	Q[qn++] = Tp(+2, x1, y1, y2, i);
    	Q[qn++] = Tp(-2, x2, y1, y2, i);
    }
    for (int i = 0; i < q; ++i) {
    	int x1, y1;
    	scanf("%d%d", &x1, &y1);
    	Q[qn++] = Tp(-1, x1, y1, y1 + w - 1, i);
    	Q[qn++] = Tp(+1, x1 + l - 1, y1, y1 + w - 1, i);
    }

    tree_init(1, 0, 1000000);

    sort(Q, Q + qn);
    for (int i = 0; i < qn; ++i) {
    	if (Q[i].type == +2) {
    		tree_set(1, Q[i].y1, Q[i].y2, Q[i].x1);
    	} else
    	if (Q[i].type == -2) {
    		tree_set(1, Q[i].y1, Q[i].y2, -1);
    	} else
    	if (Q[i].type == -1) {
    		ans[Q[i].i] -= 
    	}
    }

    for (int i = 0; i < q; ++i) printf("%I64d\n", ans[i]);

    return 0;
}
