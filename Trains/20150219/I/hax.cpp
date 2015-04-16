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

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int n, m, k;

vector< pair<int, int> > u[22];
int dist[15][15];
char s[55][55];

int D[55][55];
int DD[13][13][55][55];

void bfs(int x, int y) {
	memset(D, 63, sizeof(D));
	D[x][y] = 0;
	queue< pair<int, int> > q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (D[x][y] > D[t.first][t.second] + 1) {
				D[x][y] = D[t.first][t.second] + 1;
				q.push(make_pair(x, y));
			}
		}
	}
}

inline void minimize(int& x, int y) {
	if (y < x) x = y;
}
inline void minimize(ll& x, ll y) {
	if (y < x) x = y;
}

int f[5555][13][13];
ll f1[15][15][15];
ll g[5555][13][13];
ll h[5555][13];
int K;


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

	
	scanf("%d%d%d", &n, &m, &K);
	int sx, sy, tMove, tCheck;
	scanf("%d%d%d%d\n", &sx, &sy, &tMove, &tCheck);
	for (int i =0; i < n; ++i) {
		gets(s[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) if (s[i][j] != '.') {
			int nei = 0;
			for (int d = 0;  d < 4; ++d) {
				int x = i + dx[d];
				int y = j + dy[d];
				if (x < 0 || y < 0 || x >= n || y >= m) continue;
				if (s[x][y] == '.') continue;
				nei++;
			}
			if (nei == 1) {
				u[s[i][j] - 'A'].push_back(make_pair(i, j));
			}
		}
	}

	for (int c = 'A'; c <= 'L'; ++c) {
		const vector< pair<int, int> >& U = u[c - 'A'];

		for (int i = 0; i < U.size(); ++i) {
			bfs(U[i].first, U[i].second);
			memcpy(DD[c - 'A'][i], D, sizeof(D));
			for (int j = 0; j < U.size(); ++j)
				dist[i][j] = D[U[j].first][U[j].second];
		}

		int UN = U.size();
		memset(f, 63, sizeof(f));
		for (int i = 0; i < UN; ++i) f[1 << i][i][i] = 0;

		for (int msk = 1; msk < (1 << UN); ++msk)
			for (int i = 0; i < UN; ++i) if (msk & (1 << i))
				for (int j = 0; j < UN; ++j) if (msk & (1 << j))
					for (int k = 0; k < UN; ++k) if ((msk & (1 << k)) == 0) {
						minimize(f[msk | (1 << k)][i][k], f[msk][i][j] + dist[j][k]);
					}

		for (int i = 0; i < UN; ++i)
			for (int j = 0; j < UN; ++j) if (i != j)
				f1[c - 'A'][i][j] = f[(1 << UN) - 1][i][j] * tMove + UN * tCheck;
	}	

	memset(g, 63, sizeof(g));
	memset(h, 63, sizeof(h));
	for (int c = 'A'; c <= 'L'; ++c) {
		const vector< pair<int, int> >& U = u[c - 'A'];
		for (int i = 0; i < U.size(); ++i)
			for (int j = 0; j < U.size(); ++j) if (i != j || U.size() == 1)
				minimize(g[1 << (c - 'A')][c - 'A'][j], DD[c - 'A'][i][sx][sy] * tMove + f1[c - 'A'][i][j]);
	}
	for (int msk = 1; msk < (1 << 12); ++msk) {
		for (int c = 'A'; c <= 'L'; ++c) if ((1 << (c - 'A')) & msk)
		for (int i = 0; i < u[c - 'A'].size(); ++i) {
			int xi = u[c - 'A'][i].first;
			int yi = u[c - 'A'][i].second;
			for (int c1 = 'A'; c1 <= 'L'; ++c1) if ( ((1 << (c1 - 'A')) & msk) == 0 )
			for (int i1 = 0; i1 < u[c1 - 'A'].size(); ++i1)
			for (int i2 = 0; i2 < u[c1 - 'A'].size(); ++i2) if (i1 != i2 || u[c1 - 'A'].size() == 1)
				minimize(g[msk | (1 << (c1 - 'A'))][c1 - 'A'][i2], g[msk][c - 'A'][i] + f1[c1 - 'A'][i1][i2] + DD[c1 - 'A'][i1][xi][yi] * tMove);

			minimize(h[msk][1], g[msk][c - 'A'][i] + DD[c - 'A'][i][sx][sy] * tMove);
		}
		for (int i = 0; i < 12; ++i) 
			if ((1 << i) & msk)
				minimize(h[msk][1], h[msk ^ (1 << i)][1]);
	}
	for (int k = 2; k <= K; ++k) {
		for (int msk = 1; msk < (1 << 12); ++msk) {
			h[msk][k] = h[msk][k - 1];

			for (int i = 0; i < 12; ++i) 
				if ((1 << i) & msk)
					minimize(h[msk][k], h[msk ^ (1 << i)][k]);

			for (int submsk = msk; submsk; submsk = (submsk-1) & msk) {
				minimize(h[msk][k], max(h[submsk][1], h[msk ^ submsk][k - 1]));
			}
		}
	}		
	cout << h[(1 << 12) - 1][K] << endl;
	
    return 0;
}
