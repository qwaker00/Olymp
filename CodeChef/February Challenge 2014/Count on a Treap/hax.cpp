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
#define yn YN

using namespace std;

const int N = 422222;

struct Tp {
	int t, x, y;
} a[N];
int xx[N], xn = 0;
int l[N], r[N], ls[N], rs[N], kw[N];
set<int> S[N], S2[N];

void add_point(int y, int x) {
	int yy = y;
	while (y) {
		S[y].insert(x);
		y &= y - 1;
	}
	y = yy;
	while (y <= xn) {
		S2[y].insert(x);
		y = (y | (y - 1)) + 1;
	}
}

int find_min_greater_up(int y, int x) {
	int ans = 2e9;
	while (y <= xn) {
		set<int>::const_iterator i = S[y].upper_bound(x);
		if (i != S[y].end() && ans > *i) ans = *i;
		y = (y | (y - 1)) + 1;
	}
	if (ans == 2e9) return 0;
	return ans;
}

int find_max_less_up(int y, int x) {
	int ans = -2e9;
	while (y <= xn) {
		set<int>::const_iterator i = S[y].lower_bound(x);
		if (i != S[y].begin()) {
			--i;
			if (ans < *i) ans = *i;
		}
		y = (y | (y - 1)) + 1;
	}
	if (ans == -2e9) return 0;
	return ans;
}

int find_min_greater_down(int y, int x) {
	int ans = 2e9;
	while (y) {
		set<int>::const_iterator i = S2[y].upper_bound(x);
		if (i != S2[y].end() && ans > *i) ans = *i;
		y &= y - 1;
	}
	if (ans == 2e9) return 0;
	return ans;
}

int find_max_less_down(int y, int x) {
	int ans = -2e9;
	while (y) {
		set<int>::const_iterator i = S2[y].lower_bound(x);
		if (i != S2[y].begin()) {
			--i;
			if (ans < *i) ans = *i;
		}
		y &= y - 1;
	}
	if (ans == -2e9) return 0;
	return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

	int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
    	scanf("%d%d", &a[i].t, &a[i].x);
    	xx[xn++] = a[i].x;
    	if (a[i].t != 1) {
    		scanf("%d", &a[i].y);
    		xx[xn++]= a[i].y;
    	}
    }
    sort(xx, xx + xn); xn = unique(xx, xx + xn) - xx;

    for (int i = 0; i < n; ++i) {
    	if (a[i].t == 0) { // add
    		int k = lower_bound(xx, xx + xn, a[i].x) - xx + 1;
    		int w = lower_bound(xx, xx + xn, a[i].y) - xx + 1;
    		kw[k] = w;

    		int father = find_min_greater_up(w, k);
    		if (father > 1e9 || l[father] > k || r[father] < k) {
    			father = find_max_less_up(w, k);
    		}
    		if (father < -1e9 || l[father] > k || r[father] < k) {
    			l[k] = 1, r[k] = xn;
    		} else {
    			if (k < father) 
    				l[k] = l[father], r[k] = father - 1;
    			else
    				l[k] = father + 1, r[k] = r[father];
    		}

    		add_point(k, w);
    	}
    }

    return 0;
}
