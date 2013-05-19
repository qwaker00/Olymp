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

int n, m;
int d[2222][2222], was[2222];
LL D1[2222], D2[2222], D3[2222];

void Dij(LL* D, int x) {
	memset(D, 63, sizeof(LL) * n);
	memset(was, 0, sizeof(was));

	D[x] = 0;
	for (int i = 0; i < n; ++i) {
		LL mind = (LL)2e9;
		int mini = 0;
		for (int j = 0; j < n; ++j) if (!was[j] && D[j] < mind) {
			mind = D[j];
			mini = j;
		}
		was[mini] = true;
		for (int j = 0; j < n; ++j) {
			if (mind + d[mini][j] < D[j]) {
				D[j] = mind + d[mini][j];
			}
		}
	}
}


int main() {
    freopen("islands.in", "r", stdin);
    freopen("islands.out", "w", stdout);
    
	scanf("%d%d", &n, &m);
	memset(d, 63, sizeof(d));
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = d[y][x] = min(d[x][y], z);
	}    
	int s1, s2, s3;
	scanf("%d%d%d", &s1, &s2, &s3);

	Dij(D1, s1);
	Dij(D2, s2);
	Dij(D3, s3);

	LL ans = (LL)2e9;
	for (int i = 0; i < n; ++i) {
		if (D1[i] + D2[i] + D3[i] < ans) {
			ans = D1[i] + D2[i] + D3[i];
		}
	}
	cout << ans << endl;
    
    return 0;
}
