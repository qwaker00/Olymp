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
#include <time.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 50002;
const int K = 51;
const int C = 51;

int par[N];
int colorcnt[N];

vector<int> g[N];

unsigned short f[N][K][C];
char z[N][C];
int color[N];

void dfs(int x) {
	for (int i = 0; i < g[x].size(); ++i)
		if (!par[ g[x][i] ]) {
			par[ g[x][i] ] = x;
			dfs(g[x][i]);
		}
}

int n, k, c;

inline char min(char a, int b) {
	if (a < b) return a;
	return b;
}

inline void modify(int x, int color) {
	for (int depth = 0; depth <= k; ++depth) {
		f[x][depth][color]++;	

		z[x][color] = min(z[x][color], depth);

		x = par[x];
		if (!x) return;
	}
}

inline void modify2(int x, int color, int color2) {
	colorcnt[color]--;
	colorcnt[color2]++;

	for (int depth = 0; depth <= k; ++depth) {
		f[x][depth][color]--;
		if (z[x][color] == depth && !f[x][depth][color]) {
			z[x][color] = 63;
			for (int i = depth + 1; i <= k; ++i)
				if (f[x][i][color]) {
					z[x][color] = i;
					break;
				}
		}

		f[x][depth][color2]++;	
		z[x][color2] = min(z[x][color2], depth);

		x = par[x];
		if (!x) return;
	}
}

inline void readi(int& x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();

	do {
		x = x * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');
}

int deg[N];

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	readi(n); readi(k); readi(c);
	for (int i = 1; i <= n; ++i) {
		readi(color[i]);
		colorcnt[ color[i] ]++;
	}
	for (int i = 1; i < n; ++i) {
		int a = 0, b = 0;
		readi(a); readi(b);
		g[a].push_back(b);
		g[b].push_back(a);

		++deg[a];
		++deg[b];
	}

	cerr << clock() << endl;

	int root = 1;
	for (int i = 1; i <= n; ++i)
		if (deg[i] > deg[root]) {
			root = i;
		} 

    dfs(root);

    memset(z, 63, sizeof(z));

    for (int i = 1; i <= n; ++i) {
    	modify(i, color[i]);
    }
    
    cerr << clock() << endl;

    int q = 0;
    readi(q);
	while (q--) {
		int d = 0; readi(d);
		if (d == 1) {
			int v = 0, w = 0; 
			readi(v); readi(w);
			if (color[v] != w) {
				modify2(v, color[v], w);
				color[v] = w;
			}
		} else {
			int v = 0, k = 0; 
			readi(v); readi(k);

			int ans = 0;
			for (int cl = 1; cl <= c; ++cl) {
				if (!colorcnt[cl]) continue;

				int x = v;
				bool cool = false;
				for (int depth = 0; depth <= k; ++depth) {
					if (z[x][cl] <= k - depth) {
						cool = true;
						break;
					}

					x = par[x];
					if (!x) break;
				}

				if (cool) ++ans;
			}

			printf("%d\n", ans);
		}
	}	

	cerr << clock() << endl;
	
	return 0;
}
