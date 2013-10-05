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

const int N = 111;
int a[N][N];
int x, y;
int n;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(a, -1, sizeof(a));

		int m; scanf("%d", &m);
		int lim = n * n;
		for (int i = 0; i < lim; ++i) {
			int z; scanf("%d", &z);
			a[(i / n) + 1][(i % n) + 1] = z;
			if (z == 0) {
				x = (i / n) + 1;
				y = (i % n) + 1;
			}
		}

		while (m--) {
			int z; scanf("%d", &z);
			for (int i = 0; i < 4; ++i) {
				if (a[x + dx[i]][y + dy[i]] == z) {
					a[x][y] = z;
					x += dx[i];
					y += dy[i];
					a[x][y] = 0;
					break;
				}
			}
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) printf("%d ", a[i][j]);
		puts("");
	}
	
	return 0;
}
