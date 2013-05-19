#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 1111;

vector<int> g[N];
int n;

vector<int> W, B;
vector< vector<int> > Ws, Bs;

int color[N];
bool u[N];
bool COOL;

int f[N][N];
bool can[N][N];

void dfs(int x) {
	for (int i = 0; i < g[x].size(); ++i) {
		if (u[ g[x][i] ]) {
			if (color[x] == color[ g[x][i] ]) {
				COOL = false;
			}
		} else {
			u[ g[x][i] ] = true;
			color[ g[x][i] ] = 1 - color[x];
			dfs(g[x][i]); 
			if (color[x]) W.push_back(g[x][i]);
			else B.push_back(g[x][i]);
		} 
	}
}

int main() {
    freopen("teams.in", "r", stdin);
    freopen("teams.out", "w", stdout);
    
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			scanf("%d", &x);
			

			if (!x && i != j) {
				g[i].push_back(j);
			}
		}
	}

	Ws.push_back(W);
	Bs.push_back(B);

	COOL = true;
	for (int i = 1; i <= n; ++i) {
		if (!u[i]) {
			W.push_back(i);
			u[i] = true;
			dfs(i);

			Ws.push_back(W);
			Bs.push_back(B);
			W.clear();
			B.clear();
		}
	}

	if (!COOL) {
		puts("NO");
		return false;	
	}

	memset(f, -1, sizeof(f));
	can[0][0] = true;

	int k = Ws.size();
	for (int i = 1; i < k; ++i)
		for (int j = 0; j <= n; ++j) {
			int sz;

			sz = Ws[i].size();
			if (sz <= j) {
				if (can[i - 1][j - sz]) {
					f[i][j] = 0;
					can[i][j] = true;
				}
			}

			sz = Bs[i].size();
			if (sz <= j) {
				if (can[i - 1][j - sz]) {
					f[i][j] = 1;
					can[i][j] = true;
				}
			}	
		}

	for (int m = 0; m <= n; ++m) {
		int nm = n - m;
		if (can[k - 1][m] && nm <= m && nm * 2 >= m) {
			vector<int> ans;

			int cn = k - 1;
			int cm = m;

			while (cn) {
				if (f[cn][cm]) {
					for (int q = 0; q < Bs[cn].size(); ++q) ans.push_back(Bs[cn][q]);
					cm -= Bs[cn].size();
				} else {
					for (int q = 0; q < Ws[cn].size(); ++q) ans.push_back(Ws[cn][q]);
					cm -= Ws[cn].size();				
				}
				--cn;
			}

			sort(ans.begin(), ans.end());
			puts("YES");
			for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
			puts("");
			return 0;
		}
	}

	puts("NO");
    
    return 0;
}
