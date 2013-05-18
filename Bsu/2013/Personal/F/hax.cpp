#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 5555

int D[N][2];
int n, m, q, x, y, deg[N];
int d[N][N];
queue<pair<int, int> > Q;

int main() {
    freopen("paths.in", "r", stdin);
    freopen("paths.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		d[x][y] = d[y][x] = 1;
		deg[x]++;
		deg[y]++;
	}

	memset(D, 63, sizeof(D));
	D[1][0] = 0;
	Q.push(make_pair(1, 0));
	while (!Q.empty()) {
		pair<int, int>& p = Q.front();
		int x = p.first;
		int y = p.second;
		int dd = D[x][y];

		y ^= 1;
		for (int i = 1; i <= n; ++i) if (d[x][i]) {
			if (D[i][y] > dd + 1) {
				D[i][y] = dd + 1;
				Q.push(make_pair(i, y));
			}
		}

		Q.pop();
	}

	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &x, &y);
		if ( (deg[x] > 0 && D[x][y & 1] <= y) || (deg[x] == 0 && D[x][y & 1] == y) ) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
    
    return 0;
}
