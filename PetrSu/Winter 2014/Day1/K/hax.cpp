#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <assert.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

#define N 111111
#define M 1000003
#define MM (M-1)

int n, k;
vector<int> g[N];
int a[N];

struct Tp {
	map<int, int>* data;
	int shift;

	Tp() : data(new map<int, int>()), shift(0) {};
};

inline void add(map<int, int>& s, int k, int v) {
	int& t = s[k];
	if (t == 0 || (t != 0 && v < t)) t = v;
}

int X = 2e9;
int Y = 2e9;

void update(map<int, int>& s, int v, int x) {
	if (s.count(v) ) {
		int x1 = x;
		int x2 = s[v];
		if (x1 == x2) return;
		if (x1 > x2) swap(x2, x1);
		if (x1 < X || (x1 == X && x2 < Y)) {
			X = x1;
			Y = x2;
		}
	}
}

int P[M], R[M];

Tp dfs(int x, int pr = -1) {	
	Tp ans;
	for (size_t i = 0; i < g[x].size(); ++i) {
		if (g[x][i] == pr) continue;
		Tp child = dfs(g[x][i], x);

		if (child.data->size() > ans.data->size()) {
			swap(child, ans);
		}
		for (map<int, int>::iterator i = child.data->begin(); i != child.data->end(); ++i) {
			update(*ans.data, (k - i->first - a[x] - child.shift - ans.shift + 4 * MM) % MM, i->second);
		}
		for (map<int, int>::iterator i = child.data->begin(); i != child.data->end(); ++i) {
			add(*ans.data, (i->first + child.shift - ans.shift + MM) % MM, i->second);
		}
		delete child.data;
	}
	ans.shift = (ans.shift + a[x]) % MM;
	update(*ans.data, (k - ans.shift + MM) % MM, x);
	add(*ans.data, (a[x] - ans.shift + MM) % MM, x);

/*	cerr << x << ":"; 
	for (map<int, int>::iterator i = ans.data->begin(); i != ans.data->end(); ++i) {
		cerr << " " << P[(i->first + ans.shift) % MM] << "," << i->second;
	}
	cerr << endl;
*/
	return ans;
}

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);

//	for (int i = 2; i < M; ++i)
//		assert (M % i != 0);			

	P[0] = 1;
	R[P[0]] = 0;
	for (int i = 1; i < MM; ++i) {
		P[i] = (P[i - 1] * 2) % M;
		R[P[i]] = i;
	}
	R[0] = -1;
//	cerr << clock() << endl;

	while (scanf("%d%d", &n, &k) == 2) {
		X = Y = 2e9;

		k = R[k];
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			a[i] = R[x];
		}
		for (int i = 1; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}

		if (k == -1) {
			puts("No solution");
			continue;			
		}

		Tp r = dfs(1);
		delete r.data;

		for (int i = 1; i <= n; ++i) g[i].clear();

		if (X > n) {
			puts("No solution");
		} else {
			printf("%d %d\n", X, Y);
		}
	}
//	cerr << clock() << endl;

	return 0;
}