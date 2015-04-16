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

const int N = 100111;
const int T = 77;

vector< pair<int, int> > g[N];
int p[N][18], d[N], pp[N][T][18], w[N], wei[N], wson[N];
int buf[N*2], pos[N], head[N], bpos = 0;

void build(int x) {	
	int hd = x;
	while (x) {
		buf[bpos] = x;
		pos[x] = bpos;
		head[x] = hd;
		bpos += d[wson[x]] - d[x];
		x = wson[x];
	}
	++bpos;
}

void dfs(int x) {
	for (int j = 1; p[x][j - 1]; ++j) {
		p[x][j] = p[p[x][j - 1]][j - 1];
	}
	pp[x][1][0] = x;
	for (int P = 2; P < T; ++P) {
		int pc = pp[x][P - 1][0];
		if (pc && d[x] - d[p[pc][0]] <= P) pc = p[pc][0];
		if (pc && d[x] - d[p[pc][0]] <= P) pc = p[pc][0];
		if (!pc || pc == x) break;
		pp[x][P][0] = pc;
		for (int j = 1; pp[x][P][j - 1]; ++j) {
			pp[x][P][j] = pp[pp[x][P][j - 1]][P][j - 1];
		}
	}
	wei[x] = 1;
	for (int i = 0; i < (int)g[x].size(); ++i) {
		int y = g[x][i].first;
		if (p[x][0] == y) continue;		
		d[y] = d[x] + g[x][i].second;
		w[y] = w[x] + 1;
		p[y][0] = x;
		dfs(y);
		wei[x] += wei[y];
		if (wson[x] == 0 || wei[y] > wei[wson[x]]) {
			if (wson[x]) build(wson[x]);
			wson[x] = y;
		}
	}
}

int lca(int x, int y) {	
	for (int i = 17; i >= 0; --i)
		if (w[p[x][i]] >= w[y])
			x = p[x][i];
	for (int i = 17; i >= 0; --i)
		if (w[p[y][i]] >= w[x])
			y = p[y][i];

	if (x == y) return x;

	for (int i = 17; i >= 0; --i)
		if (p[x][i] != p[y][i]) {
			x = p[x][i];
			y = p[y][i];
		}
	return p[x][0];			
}

int next(int x, int P) {
	do {
		if (x == head[x]) {
			int up = d[x] - d[p[x][0]];
			if (up >= P) {
				if (up == P) return p[x][0];
				return x;
			}
			P -= up;
			x = p[x][0];
		} else {
			if (pos[x] - pos[head[x]] >= P) {
				if (buf[x - P]) return buf[x - P];
				return buf[x - P + 1];
			}
			P -= pos[x] - pos[head[x]];
			x = head[x];
		}
	} while(x);
	return 0;
}

void calc(int x, int P, int y, int& ad, int& ar) {
	if (P < T) {
		ad = 0;
		for (int i = 17; x != y && i >= 0; --i)
			if (d[ pp[x][P][i] ] >= d[y]) {
				x = pp[x][P][i];
				ad += (1 << i);
			}
		ar = d[x] - d[y];
	} else {
		ad = 0;
		do {
			int nx = next(x, P);
			if (d[nx] < d[y]) break;
			x = nx;
			++ad;
		} while(true);
		ar = d[x] - d[y];
	}
}


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //cerr << sizeof(pp) << endl;
    
    int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		g[x].push_back(make_pair(y, d));
		g[y].push_back(make_pair(x, d));
	}

	d[0] = w[0] = -1;
	dfs(1);
	build(1);

	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y, p;
		scanf("%d%d%d", &x, &y, &p);
		int z = lca(x, y);
		int d1, d2, r1, r2;
		calc(x, p, z, d1, r1);
		calc(y, p, z, d2, r2);
		printf("%d\n", d1 + d2 + ((r1 + r2) > 0) + ((r1 + r2) > p));
	}
    
    return 0;
}
