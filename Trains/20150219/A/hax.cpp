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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const double PI = 3.1415926535897932384626433832795;
template<typename T>
T sqr(T x) { return x * x; }

using namespace std;

const int N = 111111;
vector<int> g[N];
int an = 0, a[N], d[N];
int p[N][22];


int lca(int x, int y) {
	if (d[x] > d[y])
		for (int j = 19; j >= 0; --j)
			if (d[ p[x][j] ] >= d[y])
				x = p[x][j];
	if (d[y] > d[x])
		for (int j = 19; j >= 0; --j)
			if (d[ p[y][j] ] >= d[x])
				y = p[y][j];
	if (x == y) return x;
	for (int j = 19; j >= 0; --j)
		if (p[y][j] != p[x][j]) {
			x = p[x][j];
			y = p[y][j];
		}
	return p[x][0];
}

int getdist(int x, int y) {
	int z = lca(x, y);
	return d[x] + d[y] - 2 * d[z];
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x  = q.front(); q.pop();

		a[an++] = x;
		sort(g[x].begin(), g[x].end());
		d[x] = d[p[x][0]] + 1;	
		for (int j = 1; j < 20; ++j) 
			p[x][j] = p[p[x][j - 1]][j - 1];

		for (int i = 0; i < g[x].size(); ++i) {
			q.push(g[x][i]);
		}
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &p[i][0]);
		g[p[i][0]].push_back(i);
	}
	bfs(1);
	ll dist = 0;
	for (int i = 1; i < an; ++i) {
		dist += getdist(a[i - 1], a[i]);
	}
	cout << dist << endl;
	
    return 0;
}
