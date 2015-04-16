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

const int N = 111;
vector<int> g[N][2];

void ERR() {	
	puts("IMPOSSIBLE");
	exit(0);
}


vector<int> ans;

int dfs(int x, int maxv) {
	if (x > maxv) return 0;

	for (int i = 0; i < g[x][0].size(); ++i) {
		if (g[x][0][i] > maxv) ERR();
		if (g[x][0][i] <= x) ERR();
	}
	for (int j = 0; j < g[x][1].size(); ++j) {
		if (g[x][1][j] > maxv) ERR();
		if (g[x][1][j] <= x) ERR();
	}
	int maxl =-1e9;
	for (int i = 0; i < g[x][0].size(); ++i) if (g[x][0][i] > maxl) maxl = g[x][0][i];
	int minr = 1e9;
	for (int i = 0; i < g[x][1].size(); ++i) if (g[x][1][i] < minr) minr = g[x][1][i];
	if (maxl >= minr) ERR();

	if (x == maxv) {
		ans.push_back(x);
		return 1;
	}
	if (minr > 1e8) {
		int w = dfs(x + 1, maxv) + 1;
		ans.push_back(x);
		return w;
	}

	int w = dfs(x + 1, minr - 1);
	ans.push_back(x);
	++w;
	w += dfs(x + w, maxv);

	return w;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int x, y, z;
		string s;
		cin >> x >> y >> s;
		if (s == "LEFT") z = 0;else z = 1;
		g[x][z].push_back(y);
	}
	dfs(1, n);
	if (ans.size() != n) ERR();
	for (int i =0; i < ans.size(); ++i) printf("%d ", ans[i]);
	puts("");
	
    return 0;
}
