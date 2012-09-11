#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
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

#define N 222222
int n, m, p[N], cyc[N], x, y;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i =0 ; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}

	int it = 0;
	for (int i = 0; i < n; i++) if (cyc[i] == 0) {
		++it;
		int x = i;
		do {
			cyc[x] = it;
			x = p[x];
		} while (i != x);
	}

	for (int i = 0; i < m ; i++) {
		scanf("%d%d", &x, &y);
		x--; y--;
		if (cyc[x] == cyc[y] || cyc[x] == cyc[0] && cyc[y] == cyc[1] || cyc[x] == cyc[1] && cyc[y] == cyc[0]) {
			puts("Yes");
		} else
			puts("No");
	}

	return 0;
}
