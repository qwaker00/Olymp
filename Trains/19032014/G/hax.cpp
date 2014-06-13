#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <memory.h>
using namespace std;
const int N = 444;

int n, m, a[N], b[N][N], ans[N], en, lid[N+N], wid[N+N];
int was[N * 4], IT = 0;
vector<int> g[N * 4];
vector<int> byline[N];
vector<int> byword[N];
int dead[N*4];

void ERR() {
	puts("NO");
	exit(0);
}

inline void add(int x, int xx, int y, int yy) {
//	cout << "if line " << lid[x] << (xx ? "" : " not") << " set word " << x << " then line " << lid[y] << (yy ? "" : " not") << " set word " << wid[y] << endl;
	g[y * 2 + (1 - yy)].push_back(x * 2 + (1 - xx));
	g[x * 2 + xx].push_back(y * 2 + yy);
}

bool dfsfind(int x, int y) {
	if (was[x] == IT) return false;
	if (dead[x]) return true;
	if (x == y) return true;
	was[x] = IT;
	for (int i = 0; i < g[x].size(); ++i) {
		if (dfsfind(g[x][i], y)) return true;
	}
	return false;
}

void dfsset(int x) {
	if (was[x] == IT) return;
	was[x] = IT;
	dead[x^1] = true;
	if (x & 1) {
		ans[lid[x >> 1]] = wid[x >> 1];
	}
	for (int i = 0; i < g[x].size(); ++i) {
		dfsset(g[x][i]);
	}
}

int main() {
	freopen("show.in", "r", stdin);
	freopen("show.out", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	int en = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &b[i][j]);
		}
		for (int j = 0; j < n; ++j) if (a[j] == b[i][j]) {
			byline[j].push_back(en);
			byword[i].push_back(en);
			lid[en] = j;
			wid[en] = i;
			++en;
		}
	}

	for (int i =  0; i < n; ++i) {
		for (int j = 0; j < byline[i].size(); ++j) {
			for (int k = 0; k < byline[i].size(); ++k) if (k != j) {
				add(byline[i][j], 1, byline[i][k], 0);
				add(byline[i][j], 0, byline[i][k], 1);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) if (b[i][k] == b[j][k]) {
			    for (int ii = 0; ii < byword[i].size(); ++ii)
					for (int jj = 0; jj < byword[j].size(); ++jj)
						if (byword[i][ii] != byword[j][jj])
							add(byword[i][ii], 1, byword[j][jj], 0);
				break;
			}
		}
	}
	for (int i = 0; i < en; ++i) {
		if (dfsfind(i * 2 + 1, i * 2)) dead[i * 2 + 1] = true;
		if (dfsfind(i * 2, i * 2 + 1)) dead[i * 2] = true;
	}

	memset(ans, -1, sizeof(ans));
	for (int i= 0; i < n; ++i) if (ans[i] == -1) {
		for (int j = 0; j < byline[i].size(); ++j) {
			++IT;
			if (!dfsfind(byline[i][j] * 2 + 1, byline[i][j] * 2)) {
				++IT;
				dfsset(byline[i][j] * 2 + 1);
			}
		}
		if (ans[i] == -1) ERR();
	}

	puts("YES");
	for (int i= 0; i < n; ++i) printf("%d ", ans[i] + 1);
	puts("");
	return 0;
}
