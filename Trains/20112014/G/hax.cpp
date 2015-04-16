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

const int N = 555, M = 11111;
vector<int> g[N];
int xx[M], yy[M], zz[M];

int main() {
    freopen("gas.in", "r", stdin);
    freopen("gas.out", "w", stdout);

    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		xx[i+i] = x;
		yy[i+i] = y;
		zz[i+i] = z;

		xx[i+i+1] = y;
		yy[i+i+1] = x;
		zz[i+i+1] = z;
		g[x].push_back(i+i);
		g[y].push_back(i+i+1);
	}

	vector<LL> D(n + 1, 1e18);
	vector<int> P(n + 1, -1);
	priority_queue< pair<LL, int> > q;
	q.push(make_pair(0, 1));
	D[1] = 0;
	while (!q.empty()) {
		pair<LL, int> t = q.top(); q.pop();
		int x = t.second;
		LL d = -t.first;
		if (D[x] != d) continue;
		for (int i = 0; i < g[x].size(); ++i) {
			int y = yy[g[x][i]];
			if (D[y] > d + zz[g[x][i]]) {
				D[y] = d + zz[g[x][i]];
				P[y] = g[x][i];
				q.push(make_pair(-D[y], y));
			}
		}
	}
	if (D[n] < c) {
		puts("Unfair");
		int x = n;
		vector<int> ans;
		while (x != 1) {
			ans.push_back( (P[x] / 2) + 1);
			x = xx[P[x]];
		}
		reverse(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
	} else {
		puts("Fair");		
	}

    return 0;
}
