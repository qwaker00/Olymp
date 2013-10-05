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

const int N = 300111;

vector<int> cl[N + N + N + N];
vector<int> g[N];
int n, m;
bool used[N];
int color[N];
int mincolor = 1;

const int inf = -1e9;

bool had[N];
bool inA[N], inB[N];
int half[N];
 
inline int myabs(int x) {
	if (x < 0) return -x;
	return x;
}

bool doit(int x) {
	used[x] = true;

	vector<int> st;
	queue<int> q;
	q.push(x);
	color[x] = 1;

	while (!q.empty()) {
		int x = q.front(); q.pop();
		st.push_back(x);

		for (int i = 0; i < g[x].size(); ++i)
			if (!used[ g[x][i] ]) {
				used[ g[x][i] ] = true;
				color[ g[x][i] ] = 1 - color[x];
				q.push(g[x][i]);
			}
	}

	for (int i = 0; i < st.size(); ++i)
		for (int j = 0; j < g[ st[i] ].size(); ++j)
			if (color[ st[i] ] == color[ g[ st[i] ][j] ]) return false;

	if (st.size() == 1) {
		color[ st[0] ] = mincolor;
		mincolor += 2;
		return true;
	}

	x = st[0];
	for (int i = 1; i < st.size(); ++i)
		if (g[ st[i] ].size() > g[x].size()) x = st[i];

	for (int i = 0; i < st.size(); ++i)
		color[ st[i] ] = inf;

	had[x] = true;
	inB[x] = true;
	color[x] = 1;
	vector<int> A;
	for (int i = 0; i < g[x].size(); ++i) {
		A.push_back(g[x][i]);
		inA[ A.back() ] = true;
	}

	vector<int> B;
	for (int i = 0; i < A.size(); ++i) {
		int y = A[i];
		for (int j = 0; j < g[y].size(); ++j)
			if (!inB[ g[y][j] ]) {
				B.push_back(g[y][j]);
				inB[ g[y][j] ] = true;
			}
	}

	if (B.size() == 0) {
		color[x] = mincolor;
		for (int i = 0; i < A.size(); ++i) {
			color[ A[i] ] = mincolor + 1;
		}
		mincolor += 3;
		return true;
	}

	bool wasHalf = false;
	int half1 = 0, half2 = 0;
	for (int i = 0; i < B.size(); ++i) {
		int y = B[i];

		int cnt = 0;
		for (int j = 0; j < g[y].size(); ++j)
			if (inA[ g[y][j] ]) {
				++cnt;
			}

		if (cnt == A.size()) {
			color[y] = 1;
			continue;
		}

		if (wasHalf) {
			bool have1 = false, have2 = false;
			for (int j = 0; j < g[y].size(); ++j)
				if (inA[ g[y][j] ]) {
					if (color[ g[y][j] ] == 0) have1 = true;
					else have2 = true;
				}

			if (have1 && have2) return false;
			if (have1 && cnt != half1) return false;
			if (have2 && cnt != half2) return false;

			if (have1) {
				color[y] = -1;
			} else {
				color[y] = 3;
			}
		} else {
			wasHalf = true;
			color[y] = -1;
			for (int j = 0; j < g[y].size(); ++j)
				if (inA[ g[y][j] ]) {
					half[ g[y][j] ] = 1;
					color[ g[y][j] ] = 0;
				}
			for (int j = 0; j < A.size(); ++j)
				if (!half[ A[j] ]) {
					color[ A[j] ] = 2;
				}
			half1 = cnt;
			half2 = A.size() - cnt;
		}

		q.push(y);
	}

	if (q.empty()) {
		for (int i = 0; i < A.size(); ++i) color[ A[i] ] = 0; 
	}

	int curmincolor = -1;
	while (!q.empty()) {
		x = q.front(); q.pop();
		curmincolor = min(curmincolor, color[x]);

		int d = inf;

		if (color[x] > 0) d = color[x] + 1;
		else d = color[x] - 1;

		for (int i = 0; i < g[x].size(); ++i)
			if (color[ g[x][i] ] == inf) {
				color[ g[x][i] ] = d;
				q.push(g[x][i]);
			}
	}

	for (int i = 0; i < st.size(); ++i)
		color[ st[i] ] += mincolor - curmincolor;
	mincolor += st.size() + 3;

	for (int i = 0; i < st.size(); ++i)
		for (int j = 0; j < g[ st[i] ].size(); ++j)
			if (myabs(color[ st[i] ] - color[ g[st[i]][j] ]) != 1) return false;

	return true;
}

int main() {
	//freopen("in", "r", stdin);

	int n, m;
	scanf("%d%d", &n, &m);
	
	while (m--) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)
		if (!used[i]) {
			if (!doit(i)) {
				puts("NET");
				return 0;
			}
		}

	int maxcolor = 0;
	for (int i = 1; i <= n; ++i) {
		maxcolor = max(maxcolor, color[i]);
		cl[ color[i] ].push_back(i);
	}

	for (int i = 1; i < maxcolor; ++i) {
		for (int j = 0; j < cl[i].size(); ++j) {
			int x = cl[i][j];
			int cnt = 0;

			for (int k = 0; k < g[x].size(); ++k)
				if (color[ g[x][k] ] == i + 1) {
					++cnt;
				} 
			
			if (cnt != cl[i + 1].size()) {
				puts("NET");
				return 0;
			}
		}
	}
	for (int i = 2; i <= maxcolor; ++i) {
		for (int j = 0; j < cl[i].size(); ++j) {
			int x = cl[i][j];
			int cnt = 0;

			for (int k = 0; k < g[x].size(); ++k)
				if (color[ g[x][k] ] == i - 1) {
					++cnt;
				} 
			
			if (cnt != cl[i - 1].size()) {
				puts("NET");
				return 0;
			}
		}
	}

	puts("DA");
	for (int i = 1; i <= n; ++i) printf("%d ", color[i]);
	puts("");
	
	return 0;
}
