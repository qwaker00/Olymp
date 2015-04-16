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

const int N = 222222;

set<int> g[N];
int val[N];
int ans[N];

inline void add(int x, int y) {
	g[x].insert(y);
	ans[y] -= val[x];
}
inline void rem(int x, int y) {	
	g[x].erase(y);
	ans[y] += val[x];
}
inline void post(int x) {
	++val[x];
}

int main() {
    freopen("intouch.in", "r", stdin);
    freopen("intouch.out", "w", stdout);

    int n, m;
	scanf("%d%d\n", &n, &m);
	while (m--) {
		char ch;
		scanf("%c", &ch);
		if (ch == '+') {
			int x, y;
			scanf("%d%d\n", &x, &y);
			add(x, y);
			add(y, x);
		} else
		if (ch == '-') {
			int x, y;
			scanf("%d%d\n", &x, &y);
			rem(x, y);
			rem(y, x);
		} else {
			int x;
			scanf("%d\n", &x);
			post(x);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (const auto& j : g[i]) {
			ans[j] += val[i];
		}
	}
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	puts("");

    return 0;
}
