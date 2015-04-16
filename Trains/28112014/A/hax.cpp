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

const int N = 1024;


vector<int> g[N], sons[N];
int was[N], pr[N], IT;
vector<int> req[N];
vector<pair<int, int> > forroot[N];
int n;

int fs(int x) {
	if (pr[x] != x) pr[x] = fs(pr[x]);
	return pr[x];
}

void dfs(int x) {
	was[x] = 1;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (was[y]) continue;
		dfs(y);
		pr[fs(y)] = x;
	}
	for (int i = 0; i < req[x].size(); ++i) {
		int y = req[x][i];
		if (was[y] != 2) continue;
		forroot[fs(y)].push_back(make_pair(x, y));
	}
	was[x] = 2;
}

int used[N];
int f[N], G[N];
int F[N][N];
vector<int> csons[N];
int fath[N];

int num[N];

inline void update(int& holder, int value) {
	if (holder < value) holder = value;
}

void rec(int x) {
	used[x] = IT;
	G[x] = 0;
	csons[x].clear();
	
	int sons = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
        if (used[y] == IT) continue;
        rec(y);
        update(f[1 << sons], G[y]);
        num[y] = sons++;
        csons[x].push_back(y);
        fath[y] = x;
	}
	int lim = (1 << sons);

	
    for (int i = 0; i < forroot[x].size(); ++i) {
    	int cx = forroot[x][i].first;
    	int cy = forroot[x][i].second;
		//cerr << x << " " << cx << " " << cy << endl;

    	int fx = fs(cx);
    	int fy = fs(cy);
    	int nx = num[fx];
    	int ny = num[fy];

    	if (cx == x) update(f[1 << ny], F[fy][cy] + 1);
    	if (cy == x) update(f[1 << nx], F[fx][cx] + 1);
        update(f[(1 << nx) + (1 << ny)], F[fx][cx] + F[fy][cy] + 1);    	        	
	}

	for (int msk = 0; msk < lim; ++msk) {
		for (int i = 0; i < sons; ++i) {
			if (msk & (1 << i)) {
				update(f[msk], f[msk ^ (1 << i)] + f[1 << i]);
				for (int j = i + 1; j < sons; ++j)
					if (msk & (1 << j))
						update(f[msk], f[msk ^ (1 << i) ^ (1 << j)] + f[(1 << i) + (1 << j)]);
			}
		}
		update(G[x], f[msk]);
	}

	for (int i = 0; i < n; ++i) {
		if (fath[fs(i)] == x) {
			F[x][i] = F[fs(i)][i] + f[(lim - 1) ^ (1 << num[fs(i)])];
		}
		if (fath[i] == x) {
			F[x][i] = G[i];
		}
	}

	for (int i = 0; i < csons[x].size(); ++i) {
		pr[fs(csons[x][i])] = x;
	}

	memset(f, 0, sizeof(f));
}

int main() {
    freopen("in", "r", stdin);
    //freopen(".out", "w", stdout);

	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; ++i) { 
			used[i] = false;
			forroot[i].clear();
			g[i].clear();
			sons[i].clear();
			req[i].clear();
			was[i] = 0;
			G[i] = 0;
			for (int j = 0; j < n; ++j) F[i][j] = 0;
		}
        
		for (int i = 1; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		int m; scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y); --x; --y;

			req[x].push_back(y);
			req[y].push_back(x);
		}	
		
		++IT;
		for (int i = 0; i < n; ++i) pr[i] = i;
        dfs(0);

        for (int i = 0; i < n; ++i) pr[i] = i;
        rec(0);		
        printf("%d\n", G[0]);	
	}

    return 0;
}
