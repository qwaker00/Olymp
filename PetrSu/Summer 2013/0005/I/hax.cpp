#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>


typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const LD PI = acos(-1.);
using namespace std;

#define N 1111111

int n;
int w[N];
int p[N];
int a[N];
int tw[N];
int pos[N];
int s[N];
int an = 0;
vector<int> g[N];

void dfs(int x) {
	tw[x] = w[x];
	for (size_t i = 0; i < g[x].size(); ++i) {
		dfs(g[x][i]);
		tw[x] += tw[g[x][i]];
	}
}
void out(int x) {
	a[an++] = x;
	vector< pair<int, int> > child(g[x].size());
	for (size_t i = 0; i < g[x].size(); ++i) {
		child[i] = make_pair(tw[g[x][i]], g[x][i]);
	}
	sort(child.begin(), child.end());
	for (size_t i = 0; i < child.size(); ++i) {
		out(child[i].second);
	}
}

int main() {
//	freopen(".in", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &w[i], &p[i]);
		if (p[i] != -1) {
			g[p[i]].push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) if (p[i] == -1) {
		dfs(i);
		out(i);
	}
	for (int i = 0; i < an; ++i) pos[a[i]] = i;
	s[0] = w[a[0]];
	for (int i = 1; i < an; ++i) s[i] = s[i - 1] + w[a[i]];
	LL ans = 0;
	for (int i = 0; i < n; ++i) if (p[i] != -1) {
		int ii = pos[i];
		int jj = pos[p[i]];
		ans += s[ii - 1] - s[jj];
	}
	cout << ans << endl;
			
	return 0;
}
	