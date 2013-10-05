#include <stdio.h>
#include <iostream>
#include <queue>
#include <memory.h>
#include <time.h>

using namespace std;

const int N = 1024;

typedef long long ll;

int invb[32][N];
int inva[N][N];
int where[N][N];
int invwhere[N][N];
int who[N][N];
int wherek[N][N];
int cost[N];
int D[N][N], A[N], B[N];

int n, q;

vector< pair<int, int> > g[N];

int edge[N], frm[N];
int dist[N];
void bfs1(int x) {
	memset(edge, -1, sizeof(edge));
	memset(dist, 63, sizeof(dist));
	dist[x] = 0;
	D[x][x] = 0;
	edge[x] = -2;
	queue<int> q;
	q.push(x);

	int ke = 0;
	int X = x;
	while (!q.empty()) {
		x = q.front(); q.pop();

		if (edge[x] >= 0) {
			where[ X ][ edge[x] ] = ke;
			invwhere[ edge[x] ][X] = ke;
			who[ X ][ ke ] = edge[x];
			wherek[ X ][ dist[x] ] = ke++;
		}

		for (int i = 0; i < g[x].size(); ++i)
			if (edge[ g[x][i].first ] == -1) {
				edge[ g[x][i].first ] = g[x][i].second;
				dist[ g[x][i].first ] = dist[x] + 1;
				D[X][ g[x][i].first ] = dist[x] + 1;
				q.push( g[x][i].first );
			}
	}

	for (int i = 1; i <= n; ++i) 
		wherek[X][i] = max(wherek[X][i], wherek[X][i - 1]);
}

void bfs2(int from, int to, int value) {
	memset(edge, -1, sizeof(edge));
	memset(frm, -1, sizeof(frm));

	queue<int> q;
	int x = from;
	q.push(x);
	edge[x] = -2;
	while (!q.empty()) {
		x = q.front(); q.pop();

		for (int i = 0; i < g[x].size(); ++i)
			if (edge[ g[x][i].first ] == -1) {
				edge[ g[x][i].first ] = g[x][i].second;
				frm[ g[x][i].first ] = x;
				q.push(g[x][i].first); 
			}
	}

	while (to != from) {
		int ed = edge[to];
		cost[ed] += value;
		for (int i = 1; i <= n; ++i) {
			int pos = invwhere[ed][i];
			invb[pos >> 5][i] += value;
		}
		to = frm[to];
	}
}

void bfs3(int from, int to, int value) {
	int need = D[from][to];
	for (int i = 1; i < n; ++i)
		if (D[from][ A[i] ] + D[to][ B[i] ] + 1 == need || D[from][ B[i] ] + D[to][ A[i] ] + 1 == need) {
		//if (true) {
			for (int j = 1; j <= n; ++j) {
				int pos = invwhere[i][j];
				inva[pos][i] += value;
				invb[pos >> 5][i] += value;
			}
		} 
}

inline void readi(int& x) {
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();

	do {
		x = x * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');
}

int main() {
	freopen("danger.in", "r", stdin);
	freopen("danger.out", "w", stdout);

	readi(n); readi(q);
	for (int i = 1; i < n; ++i) {
		int a, b;
		readi(a);
		readi(b);
		readi(cost[i]);
		A[i] = a;
		B[i] = b;
		g[a].push_back(make_pair(b, i));
		g[b].push_back(make_pair(a, i));
	}

	for (int i = 1; i <= n; ++i) {
		bfs1(i);
		for (int j = 1; j < n; ++j) {
			int pos = where[i][j];
			inva[ pos ][i] += cost[j];
			invb[ pos >> 5 ][i] += cost[j];
		}
	}

	while (q--) {
		int t; readi(t);
		if (t == 1) {
			int v, u, a;
			readi(v); readi(u); readi(a);
			bfs2(v, u, a);
		} else {
			int v, k;
			readi(v); readi(k);

			int pos = wherek[v][k];

			ll ans = 0;
			int x = 0;
			while (((x + 1) << 5) <= pos + 1) {
				ans += invb[x][v];
				++x;
			}
			x <<= 5;

			for (int i = x; i <= pos; ++i) ans += cost[ who[v][i] ];

			printf("%I64d\n", ans);
		}
	}

	cerr << clock() << endl;
	
	return 0;
}
