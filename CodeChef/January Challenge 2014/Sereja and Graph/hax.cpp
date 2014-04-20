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

const double EPS = 1E-9;

int Det(double a[111][111], int n) {
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) cerr << a[i][j] << " ";
//		cerr << endl;
//	}

	double det = 1;
	for (int i = 0; i < n; ++i) {
		int k = i;
		for (int j = i + 1; j < n; ++j)
			if (fabsl(a[j][i]) > fabsl(a[k][i]))
				k = j;
		if (fabsl(a[k][i]) < EPS) {
			return 0;
		}
		for (int j = i; j < n; ++j)	swap(a[i][j], a[k][j]);
		if (i != k)	det = -det;
		det *= a[i][i];
		for (int j = i + 1; j < n; ++j)
			a[i][j] /= a[i][i];
		for (int j = 0; j < n; ++j)
			if (j != i && fabsl(a[j][i]) > EPS)
				for (int k = i + 1; k < n; ++k)
					a[j][k] -= a[i][k] * a[j][i];
	}
//	cerr << det << endl;

	return det;
}

double a[111][111];
int e[111][111];    	
int match[111];
bool used[111], blossom[111];
int p[111], base[111], q[111];;
vector<int> g[111];
int n, m;

int lca (int a, int b) {
	bool used[111] = { 0 };
	for (;;) {
		a = base[a];
		used[a] = true;
		if (match[a] == -1)  break;
		a = p[match[a]];
	}
	for (;;) {
		b = base[b];
		if (used[b])  return b;
		b = p[match[b]];
	}
}

void mark_path (int v, int b, int children) {
	while (base[v] != b) {
		blossom[base[v]] = blossom[base[match[v]]] = true;
		p[v] = children;
		children = match[v];
		v = p[match[v]];
	}
}

int find_path (int root) {
	memset (used, 0, sizeof used);
	memset (p, -1, sizeof p);
	for (int i=0; i<n; ++i)
		base[i] = i;
 
	used[root] = true;
	int qh=0, qt=0;
	q[qt++] = root;
	while (qh < qt) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (base[v] == base[to] || match[v] == to)  continue;
			if (to == root || (match[to] != -1 && p[match[to]] != -1)) {
				int curbase = lca (v, to);
				memset (blossom, 0, sizeof blossom);
				mark_path (v, curbase, to);
				mark_path (to, curbase, v);
				for (int i=0; i<n; ++i)
					if (blossom[base[i]]) {
						base[i] = curbase;
						if (!used[i]) {
							used[i] = true;
							q[qt++] = i;
						}
					}
			}
			else if (p[to] == -1) {
				p[to] = v;
				if (match[to] == -1)
					return to;
				to = match[to];
				used[to] = true;
				q[qt++] = to;
			}
		}
	}
	return -1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	srand(time(0));

    int T;
    cin >> T;
    while (T--) {
    	cin >> n >> m;
    	for (int i= 0; i < n; ++i) g[i].clear();
    	for (int i = 0; i < m; ++i) {
    		int x, y;
    		cin >> x >> y;
    		--x; --y;
    		g[x].push_back(y);
    		g[y].push_back(x);
    	}
    	memset (match, -1, sizeof match);
		for (int i=0; i<n; ++i)
			if (match[i] == -1) {
				int v = find_path(i);
				while (v != -1) {
					int pv = p[v],  ppv = match[pv];
					match[v] = pv,  match[pv] = v;
					v = ppv;
				}
			}
		bool found = false;
		for(int i = 0; i < n; ++i) if (match[i] == -1) {
			found = true;
			break;
		}

	    if (found)
	    	puts("NO");
	    else
	    	puts("YES");
    }
    
    return 0;
}
