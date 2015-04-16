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

char f1[N][22], n1[N][22], son[111], of[111], n2[N][22];
map< pair<string, string> , int> ids;
int n;
int was[N], nxt[N], oncycle[N], cycle[N];
vector<int> g[N];

inline int getid(const char *f, const char * s) {
	if (ids.count(make_pair(f, s)) == 0) return 0;
	return ids[make_pair(f, s)];
}

int calc(int x) {
	int ans = 1;
	for (size_t i = 0; i < g[x].size(); ++i) {
		if (oncycle[g[x][i]]) continue;
		ans = max(ans, calc(g[x][i]) + 1);
	}
	return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int m;
	scanf("%d\n", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s %s %s %s %s\n", f1[i], n1[i], son, of, n2[i]);
		if (ids[make_pair(f1[i], n1[i])] == 0) {
			ids[make_pair(f1[i], n1[i])] = ++n;
		}
	}
	for (int i = 0; i < m; ++i) {
		int x = getid(f1[i], n2[i]);
		int y = getid(f1[i], n1[i]);
		if (x && y) {
			g[x].push_back(y);
			nxt[y] = x;
		}
	}

	int ans = 0, iter = 0;
	for (int i = 1; i <= n; ++i) if (!was[i]) {
		++iter;
		int x = i;
		while (!was[x]) {
			was[x] = iter;
			if (!nxt[x]) break;
			x = nxt[x];
		}
		if (!nxt[x]) {
			ans = max(ans, calc(x));
		} else if (was[x] == iter) {
			int cn = 0;
			int rootx = x;
			do {
				cycle[cn++]= x;
				oncycle[x] = 1;
				x = nxt[x];
			} while (x != rootx);
			for (int j = 0; j < cn; ++j) {
				ans = max(ans, calc(cycle[j]) + cn - 1);
			}
		}
	}
	cout << ans << endl;
    
    return 0;
}
