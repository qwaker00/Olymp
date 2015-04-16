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

const int N = 222;

int a[N];
int pr[22222];
vector<int> g[N];

const int INF = 2e9;
const int S = 0;
const int T = 1;

int was[N];
int C[N][N], F[N][N];
int ptr[N];
int IT = 0;

void add(int x, int y, int c) {
	C[x][y] = c;
	C[y][x] = 0;
	F[x][y] = 0;
	F[y][x] = 0;
	g[x].push_back(y);
	g[y].push_back(x);
//	cerr << x << " " << y << " " << c << endl;
}

int dfs(int x, int maxfl) {
	if (x == T) return maxfl;
	if (was[x] == IT) return 0;
	was[x] = IT;
	int fl = 0;
	for (int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if (C[x][y] > F[x][y]) {
			int t = dfs(y, min(maxfl - fl, C[x][y] - F[x][y]));
			F[x][y] += t;
			F[y][x] -= t;
			fl += t;
			if (fl == maxfl) break;
		}
	}
	return fl;
}

void ERR() {	
	cout << "Impossible\n";
	exit(0);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i <= 20000; ++i)
    	if (!pr[i]) {
    		for (int j = i + i; j <= 20000; j += i) pr[j] = 1;
    	}


    int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int t1 = 0, t2 = 0;
	for (int i = 0; i < n; ++i) {
		if ( (a[i] & 1) == 0 ) {
			add(S, i + 2, 2);
			t1++;
		} else {
			add(i + 2, T, 2);
			t2++;
		}
		for (int j = i + 1; j < n; ++j) if (pr[a[i] + a[j]] == 0) {
			if ( (a[i] & 1) == 0 ) {
				add(i + 2, j + 2, 1);
			} else {
				add(j + 2, i + 2, 1);
			}
		}
	}

	if (t1 != t2) {
		ERR();
	}

	++IT;
	int total = 0, t;
	while (t = dfs(S, INF)) {
		++IT;
		total += t;
	}

	if (total != t1 * 2) ERR();
	++IT;

	vector< vector<int> > ans;
	for (int i = 0; i < n; ++i) if (was[i + 2] != IT) {
		ans.push_back(vector<int>());
		vector<int>& v = ans.back();

		int x = i + 2;
		do {	
			v.push_back(x - 1);
			was[x] = IT;

			int found = 0;
			for (int j = 0; j < g[x].size(); ++j) {
				int y = g[x][j];
				if ((F[x][y] > 0 || F[y][x] > 0) && was[y] != IT && y != S && y != T) {
					x = y;
					found = 1;
					break;
				}
			}
			if (!found) break;
		} while (true);
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].size();

		assert(ans[i].size() >= 3);
		for (int j = 0; j < ans[i].size(); ++j) {
			if (j + 1 < ans[i].size())
				assert(pr[ a[ans[i][j] - 1] + a[ans[i][j + 1] - 1] ] == 0);
			else
				assert(pr[ a[ans[i][j] - 1] + a[ans[i][0] - 1] ] == 0);

			cout << " " << ans[i][j];
		}
		cout << "\n";
	}


    return 0;
}
