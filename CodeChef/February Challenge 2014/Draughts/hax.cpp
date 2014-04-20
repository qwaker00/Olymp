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

LL ans1 = 0, ans2 = 0;
int n, m, a[55555], was[55555], w[55555], total;
vector<int> g[55555];

void dfst(int x) {
	was[x] = 2;
	total += a[x];
	for (int i = 0; i < (int)g[x].size(); ++i) {
		if (was[g[x][i]] != 2) {
			dfst(g[x][i]);
		}
	}
}

void dfs(int x) {
	was[x] = 1;
	LL sum = 0;
	for (int i = 0; i < (int)g[x].size(); ++i) {
		if (was[g[x][i]] != 1) {
			dfs(g[x][i]);
			sum += LL(a[x]) * a[g[x][i]];
			a[x] += a[g[x][i]];
		}
	}
	if (sum > 0 || (total > a[x] && a[x] > 0)) ++ans2;
	ans1 += sum;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
    	if (!was[i]) {
    		total = 0;
    		dfst(i);
    		dfs(i);
    	}
    cout << ans1 << " " << ans2 << endl;

    return 0;
}
