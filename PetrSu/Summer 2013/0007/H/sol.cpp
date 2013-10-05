#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
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

const int N = 211222;
int x[N], y[N];
int prv[N], nxt[N];

int d[N];

inline int myabs(int x) {
	if (x < 0) return -x;
	return x;
}

inline int dist(int i, int j) {
	return myabs(x[i] - x[j]) + myabs(y[i] - y[j]);
}

inline void del(int x) {
	int p = prv[x], n = nxt[x];
	nxt[p] = n;
	prv[n] = p;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", x + i, y + i);
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}	
	nxt[0] = 1;
	prv[n + 1] = n;

	memset(d, 63, sizeof(d));
	d[1] = 0;
	for (int i = 2; i <= n; ++i) {
		d[i] = dist(1, i);
	}
	del(1);

    for (int j = 1; j < n; ++j) {
    	int x = nxt[0], best = 0;
    	while (x <= n) {
			if (d[x] < d[best]) {
				best = x;
			}	
			x = nxt[x];
    	}

    	del(best);
    	x = nxt[0];
    	while (x <= n) {
    		d[x] = min(d[x], dist(best, x));
    		x = nxt[x];
    	}
    }
    int best = 1;
    for (int i = 2; i <= n; ++i)
    	if (d[i] > d[best]) best = i;

	printf("%d\n", d[best]);

	return 0;
}
