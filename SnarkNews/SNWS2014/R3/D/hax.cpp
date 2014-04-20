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

#define N 1111111

int n, m, s, d;
LL c[N];
vector< pair<int, int> > g[N];
char st[N];
LL D[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	int left = -1;
	int right = 0;
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
		if (z > right) right = z;
	}

	while (left < right) {
		int center = (left + right + 1) >> 1;

		memset(st, 0, sizeof(st));
		memset(D, 127, sizeof(D));
		D[s] = center + c[s];
		deque<int> q;
		q.push_back(s);
		while (!q.empty()) {
			int x = q.front(); q.pop_front();
			st[x] = 2;
			for (int i = 0; i < g[x].size(); ++i) {
				if (g[x][i].second < D[x]) continue;
				int y = g[x][i].first;
				if (D[y] > D[x] + c[y]) {
					D[y] = D[x] + c[y];
					if (st[y] == 0) {
						q.push_back(y);
					} else
					if (st[y] == 2) {
						q.push_front(y);
					}
					st[y] = 1;
				}
			}
		}

		if (D[d] > 1e18) right = center - 1;else left = center;
	}
	cout << left << endl;
	
    return 0;
}
