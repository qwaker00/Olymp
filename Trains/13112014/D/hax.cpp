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

const int N = 111111;

int p[N];
vector<int> g[N];
LL f[N][2];
int w[N];

const int MOD = 1000000007;

void dfs(int x) {
	w[x] = 1;
	for (int i = 0; i < g[i].size(); ++i) {
		dfs(g[x][i]);
		w[x] += w[g[x][i]];
	}

	LL ansp1 = 0;
	LL ansp2 = 0;
	f[x][0] = 1;
	f[x][1] = 0;
	for (int i = 0; i < g[i].size(); ++i) {
		int y = g[x][i];
		for (int j = 0; j < 2; ++j) {
			LL fp0 = f[x][0], fp1 = f[x][1];

			ansp0 += (fp0 * f[y][0] + fp1 * f[y][1] + fp1 * f[y][1]) % MOD;
			ansp1 += (fp0 * f[y][0] + fp1 * f[y][1] + fp1 * f[y][1]) % MOD;

			f[x][0] = (fp0 * f[y][0] + fp1 * f[y][1] + fp0) % MOD;
			f[x][1] = (fp1 * f[y][0] + fp0 * f[y][1] + fp1) % MOD;
		}
	}
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &p[i]);
		g[p[i]].push_back(i);
	}

	dfs(1);
	cout << f[1] << endl;

    return 0;
}
