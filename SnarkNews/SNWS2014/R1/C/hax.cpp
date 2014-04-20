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

#define N 111111

LL D[N], DD[N];
vector< pair<int, int> > g[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int i= 0; i < m; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
	}

	priority_queue< pair<LL, int> > q;
	memset(D, 63, sizeof(D));

	for (int i = 0; i < s; ++i) {
		int x;
		scanf("%d", &x);
		D[x] = 0;
		q.push(make_pair(0, x));
	}

	while (!q.empty()) {
		pair<LL, int> t = q.top(); q.pop();
		LL d = -t.first;
		int x = t.second;
		if (D[x] != d) continue;

		for (size_t i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].first;
			LL dd = g[x][i].second + d;
			if (D[y] > dd) {
				D[y] = dd;
				q.push(make_pair(-D[y], y));
			}
		}
	}

	int start;
	scanf("%d", &start);

	if (D[start] == 0) {
		puts("-1");
		return 0;
	}

	memset(DD, 63, sizeof(DD));
	DD[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		pair<LL, int> t = q.top(); q.pop();
		LL d = -t.first;
		int x = t.second;
		if (DD[x] != d) continue;

		for (size_t i = 0; i < g[x].size(); ++i) {
			int y = g[x][i].first;
			LL dd = g[x][i].second + d;

			if (D[y] <= dd) continue;			
			if (DD[y] > dd) {
				DD[y] = dd;
				q.push(make_pair(-DD[y], y));
			}
		}
	}
	if (DD[1] > 1e18)
		puts("-1");else
		cout << DD[1] << endl;

    return 0;
}
