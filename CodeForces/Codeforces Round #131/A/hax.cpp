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

#define N 222

int c[N], dep[N][N], was[N], k[N], order[N], on = 0, n, dc[N];


int Solve(int x) {
	queue<int> nodep[4];

	for (int i = 1; i <= n; i++) {
		dc[i] = k[i];
		if (k[i] == 0) {
			nodep[c[i]].push(i);
		}
	}

	int pro = 0, ans = 0;
	while (pro < n) {
		while (!nodep[x].empty()) {
			int y = nodep[x].front(); nodep[x].pop();
			++pro;
			++ans;
			for (int i = 1; i <= n; i++) if (dep[i][y]) {
				--dc[i];
				if (dc[i] == 0) {
					nodep[c[i]].push(i);
				}
			}
		}
		if (pro == n) return ans;

		x = x % 3 + 1;
		++ans;
	}
	return ans;
}

int main() {
  //  freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 0; j < k[i]; ++j) {
			int x;
			cin >> x;
			dep[i][x] = 1;
		}
	}

	cout << std::min(std::min(Solve(1), Solve(2)), Solve(3));

    return 0;
}
